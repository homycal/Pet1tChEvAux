#include <stdlib.h>
#include <stdio.h>
#include "misc.h"

void Ballayage(int nombreJoueur, int caseDepart, int scoreDes, joueur participant[], Plateau *jeu ){
  for(int i=0; i<nombreJoueur;i++){
    for(int j=0;j<4;j++){
      for(int k=0; k<4;k++)
      if(jeu->plateau[(caseDepart+scoreDes)%56].contenu[j]==participant[i].pions[k]){
        //Puis on le replace dans l'écurie
        jeu->ecuries[i].contenu[k%4]=jeu->plateau[(caseDepart+scoreDes)%56].contenu[j]; //WARNING faut gérer si il y a plusieurs pions à balayer
        printf("Le pion %d a été renvoyé à son écurie !\n",jeu->plateau[(caseDepart+scoreDes)%56].contenu[j] );
      }
    }
  }

}

void SortieEcurie(int joueurDuTour, int scoreDes, int pionDuTour,Plateau *jeu, int nombreJoueur, joueur participant[]){
  // On récupère le pion choisi dans l'écurie
  for(int i=0; i<4; i++){
    if(jeu->ecuries[joueurDuTour].contenu[i]== pionDuTour){
      jeu->ecuries[joueurDuTour].contenu[i]=-1; // On passe l'emplecement où se trouvait le pion à -1
    }
  }
  //Si jamais, il ballaye un pion se trouvant sur la case de sortie d'écurie
  if(DetectionBallayage(0, jeu, 0+joueurDuTour*14, joueurDuTour)!=-1){
    Ballayage(nombreJoueur, 0+joueurDuTour*14,  0, participant ,jeu);
  }
  //On le place dans la case de sortie d'écurie
  int i=0;
  while(i<4){
    if(jeu->plateau[0+joueurDuTour*14].contenu[i]==-1){ // on check l'emplacement libre pour le placer dedans
          jeu->plateau[0+joueurDuTour*14].contenu[i]=pionDuTour;
          break;
    }
    i++;

  }
}



int DeplacementPlateau(int pionDuTour,int joueurDuTour, Plateau *jeu, int scoreDes,joueur participant[]){
  int t;

  t=DetectionPionCaseExt(pionDuTour, jeu);

  if(DetectionBarrage(scoreDes, jeu, t, joueurDuTour, participant)!=-1){ // Là faut changer,faut mettre le résulat de la fonction dans une variable pour pas la lancer 2 fois (doit y avoir d'autres endroit comme ça dsl)
    printf("Le pion %d bloque le passage, c'est pour une prochaine fois !\n", DetectionBarrage(scoreDes, jeu, t, joueurDuTour, participant));
    return 0;
  }

  int i=0;
  while(i<4){
    if(jeu->plateau[t].contenu[i%4]==pionDuTour){ // On met l'emplacement case où y avait le pion à -1 pour dire qu'il est libre
          jeu->plateau[t].contenu[i%4]=-1;
          break;
        }
      i++;
    }
  if(DetectionBallayage(scoreDes, jeu, t, joueurDuTour)!=-1){// Si un pion est présent sur la case d'arrivée
    Ballayage(nombreJoueur, t,  scoreDes, participant , jeu);
      }
  i=0;
  while(i<4){
    if(jeu->plateau[(t+scoreDes)%56].contenu[i%4]==-1){ // On check le premier emplacement vide de la case pour y caser le pion
          jeu->plateau[(t+scoreDes)%56].contenu[i%4]=pionDuTour;
          break;
        }
        i++;
    }
  return 0;
}
