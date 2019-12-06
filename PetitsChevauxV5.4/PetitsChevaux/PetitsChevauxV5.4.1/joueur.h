#ifndef JOUEUR_H
#define JOUEUR_H

#include "main.h"
#include "pion.h"

int ChoixCouleur(int nombreJoueur, int whitelist[], int i, Pion jeu[], int couleurPick[], int joueurDuTour, int scoreDes, int joueurIA[]);
void InitJoueur(int *nombreJoueur,int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);

#endif
