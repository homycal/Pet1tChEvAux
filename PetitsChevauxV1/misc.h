#include <stdlib.h>
#include <stdio.h>


//Fonction vérifiant si tous les chevaux sont dans l'écurie du joueurDuTour
int VerificationEcurie(int joueurDuTour, Plateau *jeu){
  for(int i =0;i<4;i++){
    if(jeu->ecuries[joueurDuTour].contenu[i]==-1){ // Si un pion est sortie de l'écurie on retourne 1
      return(1);
    }
  }
  return(0); // si tous les pions sont dans l'écurie on retourne 0
}
//Permet de détécter sur quelle case extérieur se trouve un pion
int DetectionPionCaseExt(int pionDuTour,Plateau *jeu){
  for(int i=0; i<56; i++){
    for(int j=0; j<4;j++){
      if(jeu->plateau[i].contenu[j]==pionDuTour){
        return(i); // i joue le rôle du n° de case, et j un des 4 emplacements de la case
      }   // Si le pionDuTour est dans la case, on renvoie la valeur de la case
      }
    }
  printf("ERREUR\n");
  return(0);
}
//Permet de détécter si un pion est dans l'écurie ou dans les colonnes intérieures
int DetectionPionEcurie(Plateau *jeu, int pionDuTour){
  for(int i =0; i<4;i++){
    for(int j=0; j<4; j++){
      if(jeu->ecuries[i].contenu[j] == pionDuTour){
        return(1);
      }
    }
  }
  return(0);
}
//Detection d'un pion qui bloque le déplacement dans le plateau WARNING DE MEMOIRE LA C'EST FOIREUX
int DetectionBarrage(int scoreDes, Plateau *jeu, int caseDepart, int joueurDuTour,joueur participant[]){
  for(int i=caseDepart+1; i<caseDepart+scoreDes;i++){//scoreDes car on va utiliser une autre fonction si un pion est présent à l'arrivée
    if(jeu->plateau[i%56].contenu[1]!=-1){
      return(jeu->plateau[i%56].contenu[1]);
    }
    printf("i = %d\n",i%56);
}

  return(-1); // Il n'y a aucun barrage
}

int DetectionBallayage(int scoreDes, Plateau *jeu, int caseDepart, int joueurDuTour){ //WARNING ICI AUSSI C'EST PAS COOL
  if (jeu->plateau[(scoreDes+caseDepart)%56].contenu[1]!=-1 &&  jeu->plateau[(scoreDes+caseDepart)%56].couleur != joueurDuTour){
    //Si le  contenu de la case est occupée par un pion d'une autre couleur
    return(jeu->plateau[(scoreDes+caseDepart)%56].contenu[1]);//WARNING faut gérer si il y a plusieurs pions à balayer
    //On renvoi le num du pion qui bloque
  }else{
    return -1;
  }
}
