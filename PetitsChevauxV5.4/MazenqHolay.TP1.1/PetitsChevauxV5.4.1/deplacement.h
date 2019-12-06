#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include "pion.h"
#include "main.h"

void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6]);
void DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour);
void EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour);
void DeplacementCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour);

#endif
