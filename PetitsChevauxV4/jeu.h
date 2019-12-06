#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "deplacement.h"


//Fonction choisissant le premier joueur
int PremierJoueur(int nombreJoueur){
  return (rand()%(3-0+1)+0);
}
  //Fonction lançant un dé de 6
  int LancerdeDes(){
    return(rand()%(6-1+1)+1);
  }

int ConditionFin(Pion jeu[],int joueurDuTour){
  int cpt=0;
  for(int i=0; i<16; i++){
    if(jeu[i].couleurPion== joueurDuTour && jeu[i].plateau == CENTRE && jeu[i].numCase>2 && jeu[i].numCase<=6){
      cpt++;
    }
  }
  if(cpt==4){
    return(1);
  }else{
    return(0);
  }
}

int Mouvements(int joueurDuTour, int scoreDes, Pion jeu[]){
  int statutEcurie=VerifEcurie(jeu, joueurDuTour); // on stock le résultat de la fonction pour tester juste la valeur sans relancer la fonction
  if(statutEcurie==1 && scoreDes !=6) { // Si tous les pions du joueur sont dans l'écurie et le dés !=6
    printf("Dommage, vous ne pouvez pas sortir de l'écurie\n");
    action =0;//Ne produit aucun déplacement de pion
    return 0;
  }
  if(statutEcurie ==1 && scoreDes == 6){// Si le joueur peut sortir un pion de l'écurie
    pionDuTour=ChoixPion(jeu, joueurDuTour);
    action = 1; // action 1 signifie sortir le pion de l'écurie
  }
  if(statutEcurie==0){// Si un des pions est en dehors de l'écurie
    pionDuTour=ChoixPion(jeu, joueurDuTour);
    int statutPresence= PresencePlateau(jeu,pionDuTour);//même principe que pour statutEcurie
    if(scoreDes==6 && statutPresence==0){// si le joueur essaye de sortir un pion de l'écurie avec 6
      action = 1;
    }else if(scoreDes!=6 && statutPresence==0){// si le joueur essaye de sortir un pion de l'écurie sans 6
      printf("Vous ne pouvez pas jouer ce pion ! Dommage !\n");
      //action =100;
    }else if(jeu[pionDuTour].decompteCase==0 && jeu[pionDuTour].plateau == EXTERIEUR){
      action=3;
    }else if(jeu[pionDuTour].decompteCase==0 && jeu[pionDuTour].plateau == CENTRE){
      action=4;
    }else{//Faire toutes les conditions éliminatrices
      action = 2;

    }

}
return(action);
}

int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,Pion jeu[], SDL_Surface *ecran,  SDL_Rect positionBackground, SDL_Surface *background){//Fonction qui se charge de déplacer le pion
  switch(action){
    case 1:
    SortieEcurie(jeu, joueurDuTour, pionDuTour, couleur, stockImages, ecran, positionBackground, background);
    UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

      break;

    case 2 : // déplacement basique du pion
    DeplacementPlateau(jeu, pionDuTour, scoreDes, couleur, joueurDuTour,stockImages, ecran);
    UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;

    case 3: // Entrée dans les colonnes intérieures
    EntreeCentre(jeu, pionDuTour, scoreDes, joueurDuTour, stockImages, ecran);
    UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;

    case 4: // Déplacement dans les colonnes intérieures
    DeplacementCentre(jeu, pionDuTour, scoreDes, joueurDuTour, stockImages, ecran);
    UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;
  }

  return(0);
}
