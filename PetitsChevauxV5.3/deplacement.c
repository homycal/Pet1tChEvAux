#include "main.h"

void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6]){
  Manger(jeu, pionDuTour, 0, joueurDuTour, joueurDuTour*14, couleur);
  jeu[pionDuTour].plateau=1;
  jeu[pionDuTour].numCase=joueurDuTour*14;
  jeu[pionDuTour].decompteCase = 55;// on reset le nombre de cases à parcourir ( si le pion avit été mangé)

}

int DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour){
  Manger(jeu, pionDuTour, scoreDes, joueurDuTour, jeu[pionDuTour].numCase, couleur);

  jeu[pionDuTour].numCase = (scoreDes +jeu[pionDuTour].numCase)%56;
  jeu[pionDuTour].decompteCase -= scoreDes;

  return(0);
}

int EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
    jeu[pionDuTour].plateau=CENTRE;
    jeu[pionDuTour].numCase=1;
  return 0;
}


int DeplacementCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
  if(jeu[pionDuTour].plateau==CENTRE && CaseLibre(jeu, scoreDes, pionDuTour, jeu[pionDuTour].numCase)==-1 && jeu[pionDuTour].numCase<=6){

    if (scoreDes==jeu[pionDuTour].numCase+1){
      jeu[pionDuTour].numCase=scoreDes;

    }
    else{
      printf("Vous ne pouvez pas avancer avec ce score !\n");
    }
  }

return(0);

}
