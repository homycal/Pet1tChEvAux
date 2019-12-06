#include "main.h"

void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6]){
  Manger(jeu, pionDuTour, 0, joueurDuTour, joueurDuTour*14, couleur);
  jeu[pionDuTour].plateau=1;
  jeu[pionDuTour].numCase=joueurDuTour*14;

}

int DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour){
  int statutBlocage;
  if(jeu[pionDuTour].decompteCase-scoreDes<0){
    printf("Vous allez dépasser l'entrée de votre zone, c'est impossible dommage ! \n");
    return(0);
  }
  statutBlocage=DetectionBlocage(jeu,pionDuTour, scoreDes); // on stock le résultat pour ne pas relancer la fonctiion

  if(statutBlocage!=-1){
    printf("Impossible, le pion %d bloque le passage, une autre fois ! \n",statutBlocage );
    return(0);
  }
  Manger(jeu, pionDuTour, scoreDes, joueurDuTour, jeu[pionDuTour].numCase, couleur);

  jeu[pionDuTour].numCase = (scoreDes +jeu[pionDuTour].numCase)%56;
  jeu[pionDuTour].decompteCase -= scoreDes;

  return(0);
}

int EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
  int statutCase=CaseLibre(jeu, scoreDes, pionDuTour, 0);
  if(scoreDes != 1){
    printf("Vous ne pouvez pas entrer avec ce score !\n");
  }else if(scoreDes ==1 && statutCase!=-1){
    printf("Le pion %d bloque le passage !\n", statutCase );
  }else if(scoreDes ==1 && statutCase==-1){ // Si tout est bon
    jeu[pionDuTour].plateau=CENTRE;
    jeu[pionDuTour].numCase=1;

  }else{
    printf("ERREUR CAS NON PRIS EN COMPTE\n"); // On ne sait jamais
  }
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
