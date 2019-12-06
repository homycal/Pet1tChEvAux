#ifndef JEU_H
#define JEU_H

#include "pion.h"
#include "deplacement.h"
#include "main.h"
#include "ia.h"
#include "misc.h"

int PremierJoueur(int nombreJoueur);
int LancerdeDes();
int ConditionFin(Pion jeu[],int joueurDuTour);
int Mouvements(int joueurDuTour, int scoreDes, Pion jeu[], int *action, int *pionDuTour, int whitelist[], int joueurIA[]);
int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,const char couleur[][6],Pion jeu[]);
void TestDeplacement(Pion jeu[], int joueurDuTour, int scoreDes, int valide[]);

#endif
