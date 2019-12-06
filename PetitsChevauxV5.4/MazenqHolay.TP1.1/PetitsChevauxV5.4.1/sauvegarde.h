#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "pion.h"
#include "plateau.h"

void EcrireSauvegarde(int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);
void ChargerSauvegarde(int whitelist[], Pion jeu[], int *joueurDuTour, int *scoreDes, int joueurIA[]);

#endif
