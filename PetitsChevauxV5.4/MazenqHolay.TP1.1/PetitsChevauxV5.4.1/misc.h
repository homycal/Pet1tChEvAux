#ifndef MISC_H
#define MISC_H

#include "pion.h"
#include "sauvegarde.h"
#include "main.h"

int TestPresence(int tab[], int n, int valTest);
int PresencePlateau(Pion jeu[], int pionDuTour);
int VerifEcurie(Pion jeu[], int pionTest);
//int ChoixPion(Pion jeu[],int joueurDuTour, int whitelist[],int scoreDes);
int JoueurSuivant(int whitelist[],int joueurDuTour);
int DetectionBlocage(Pion jeu[], int pionDuTour, int scoreDes);
void Manger(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour, int CaseDepart, char const couleur[][6]);
int CaseLibre(Pion jeu[], int scoreDes, int PionTest, int CaseDepart);
int LireEntier(int whitelist[], Pion jeu[], int save, int joueurDuTour, int scoreDes, int joueurIA[]);
int TestPresenceChar(char tab[], int n, char valTest);


#endif
