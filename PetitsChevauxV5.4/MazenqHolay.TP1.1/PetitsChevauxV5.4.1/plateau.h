#ifndef PLATEAU_H
#define PLATEAU_H

#include "pion.h"
#include "main.h"

//On déclare ses variables ici pour qu'elles soient visibles dans tous les fichiers
//Le plateau extérieur est composé de 56 cases
coordonnees plateauExt[56];
coordonnees ecurie[12];
coordonnees centre[24];

void AfficherPlateau(Pion jeu[]);
int CheckCoord(int *x, int y, Pion jeu[]);

#endif
