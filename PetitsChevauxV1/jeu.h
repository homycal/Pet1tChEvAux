#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "deplacement.h"

//Variables utiles pour un tour
int joueurDuTour, scoreDes,pionDuTour, action=0;

//Fonction choisissant le premier joueur
int PremierJoueur(int nombreJoueur){
  return (rand()%(nombreJoueur-0+1)+0);
}
//Fonction lançant un dé de 6
int LancerdeDes(){
  return(rand()%(6-1+1)+1);
}
//Permet de choisir le pion à jouer
int ChoixPion(int joueurDuTour){
  int pionJoueur;
  do{
    printf("Quel pion souhaitez vous jouer ?\n%d.\n%d.\n%d.\n%d.\n", participant[joueurDuTour].pions[0], participant[joueurDuTour].pions[1],
    participant[joueurDuTour].pions[2], participant[joueurDuTour].pions[3]); // on affiche les pions du joueur
    scanf("%d",&pionJoueur);// on lit la valeur du pion choisi

  }while(pionJoueur < participant[joueurDuTour].pions[0] || pionJoueur> participant[joueurDuTour].pions[3]);
  printf("Vous avez choisi le pion %d\n", pionJoueur);
  return(pionJoueur);
}

//Fonction permettant de tester la condition de fin WARNING, ça sent mauvais je crois ^^'
int ConditionFin(int joueurDuTour, Plateau *jeu){
  //Si les 4 cases les plus proches du centre ont une valeur différente de -1
  for(int i=5; i>1;i--){
    if(jeu->colonnes[(6*joueurDuTour)+i].contenu[1]==-1){ // si une des 4 cases les + proche du centre et apparteanant au joueur qui termine est vide, il n'as pas fini la partie.
      return 0;
    }
  }
  return 1;
}

int Mouvements(int joueurDuTour, int scoreDes){ // Fonction qui décrit les mouvements d'un joueur
  if(scoreDes !=6 && VerificationEcurie(joueurDuTour, &jeu)==0){ // Si le joueur ne peut pas sortir un chaval de l'écurie
    printf("Dommage, vous ne pouvez pas sortir de l'écurie !\n");
    return(0);
  }
  if(scoreDes ==6 && VerificationEcurie(joueurDuTour, &jeu)==0){
    pionDuTour=ChoixPion(joueurDuTour);
    action = 1; // action 1 signifie placer le pion à la sortie d'écurie
  }
  if(VerificationEcurie(joueurDuTour, &jeu)==1){// Si un des pions est en dehors de l'écurie
    pionDuTour=ChoixPion(joueurDuTour);

    if(scoreDes==6 && DetectionPionEcurie(&jeu,pionDuTour)==1){// si le joueur essaye de sortir un pion de l'écurie avec 6
      action = 1;
    }else if(scoreDes!=6 && DetectionPionEcurie(&jeu,pionDuTour)==1){// si le joueur essaye de sortir un pion de l'écurie sans 6
      printf("Vous ne pouvez pas jouer ce pion !\n");
      action =100;
    }
    else{
      action = 2; // WARNING actuellement, j'écrase le pion déjà présent sur la case
    }
  }
return(action);
}

int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,Plateau *jeu){//Fonction qui se charge de déplacer le pion
  switch(action){
    case 1:
    SortieEcurie(joueurDuTour, scoreDes, pionDuTour, jeu, nombreJoueur, participant);
      break;

    case 2 : // déplacement basique du pion
    DeplacementPlateau(pionDuTour,joueurDuTour, jeu, scoreDes, participant);
    break;


  }
  return(0);
}
