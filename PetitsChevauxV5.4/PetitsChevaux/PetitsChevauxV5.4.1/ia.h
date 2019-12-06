#ifndef IA_H
#define IA_H

#include "pion.h"
#include "main.h"
#include "joueur.h"

void InitIA(int *nombreJoueur, int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);
int ChoixPionIA(int valide[], Pion jeu[], int scoreDes);

#endif
