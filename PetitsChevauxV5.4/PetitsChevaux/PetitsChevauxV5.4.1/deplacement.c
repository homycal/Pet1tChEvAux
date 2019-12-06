#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "deplacement.h"

void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6]){
  Manger(jeu, pionDuTour, 0, joueurDuTour, joueurDuTour*14, couleur);
  jeu[pionDuTour].plateau=EXTERIEUR;//On change de plateau
  jeu[pionDuTour].numCase=joueurDuTour*14;
  jeu[pionDuTour].decompteCase = 55;// on reset le nombre de cases à parcourir ( si le pion avait été mangé)

}

void DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour){
  Manger(jeu, pionDuTour, scoreDes, joueurDuTour, jeu[pionDuTour].numCase, couleur);

  jeu[pionDuTour].numCase = (scoreDes +jeu[pionDuTour].numCase)%56;
  jeu[pionDuTour].decompteCase -= scoreDes;
}

void EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
    jeu[pionDuTour].plateau=CENTRE;
    jeu[pionDuTour].numCase=1;
}


void DeplacementCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
    jeu[pionDuTour].numCase=scoreDes;
}
