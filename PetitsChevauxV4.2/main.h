#include "SDL/SDL.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


enum PositionP {ECURIE, EXTERIEUR, CENTRE};
enum CouleurJ {VERT, JAUNE, BLEU, ROUGE};

//On définit une strucure case
typedef struct{
  SDL_Rect coordonnees;
}Case;

typedef struct{
  int numPion;
  enum PositionP plateau;
  enum CouleurJ couleurPion;
  int numCase;
  int decompteCase;
}Pion;

//On déclare ses variables ici pour qu'elles soient visible dans tous les fichiers
//Le plateau extérieur est composé de 56 cases
Case plateauExt[56];
Case ecurie[12];
Case centre[24];
SDL_Surface *stockImages[16];


//Case
void InitCaseExt(Case plateauExt[]);
void InitEcurie(Case ecurie[]);
void InitCentre(Case centre[]);
//deplacement
void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6], SDL_Surface *stockImages[], SDL_Surface *ecran, SDL_Rect positionBackground, SDL_Surface *background);
int DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour , SDL_Surface *stockImages[], SDL_Surface *ecran);
int EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour, SDL_Surface *stockImages[], SDL_Surface *ecran);
int DeplacementCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour, SDL_Surface *stockImages[], SDL_Surface *ecran);
//jeu
int PremierJoueur(int nombreJoueur);
int LancerdeDes();
int ConditionFin(Pion jeu[],int joueurDuTour);
int Mouvements(int joueurDuTour, int scoreDes, Pion jeu[], int *action, int *pionDuTour);
int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,const char couleur[][6],Pion jeu[], SDL_Surface *ecran,  SDL_Rect positionBackground, SDL_Surface *background);
//joueur
int ChoixCouleur(int nombreJoueur, int whitelist[], int i );
void InitJoueur(int *nombreJoueur,int whitelist[]);
//misc
int TestPresence(int tab[], int n, int valTest);
int PresencePlateau(Pion jeu[], int pionDuTour);
int VerifEcurie(Pion jeu[], int joueurDuTour);
int ChoixPion(Pion jeu[],int joueurDuTour);
int JoueurSuivant(int whitelist[],int joueurDuTour);
int DetectionBlocage(Pion jeu[], int pionDuTour, int scoreDes);
void Manger(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour, int CaseDepart, char const couleur[][6]);
int CaseLibre(Pion jeu[], int scoreDes, int PionduTour, int CaseDepart);
//pion
void InitPion(Pion jeu[], Case ecurie[]);
void AfficherPion(Pion jeu[],const char couleur[][6],const char partiePlateau[][10],int whitelist[]);
void PionImage(SDL_Surface *jeu[],  SDL_Surface *ecran);
void UpdateEcran(SDL_Surface *stockImages[], SDL_Surface *ecran, SDL_Rect positionBackground, SDL_Surface *background, int pionDuTour, Pion jeu[]);
