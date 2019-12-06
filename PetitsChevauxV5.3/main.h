#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define RED     "\033[1;31m"
#define WHITE   "\033[0;m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define YELLOW     "\033[1;33m"
#define BACKRED     "\033[1;41m"
#define BACKGRAY   "\033[1;40m"
#define BACKGREEN   "\033[1;42m"
#define BACKBLUE    "\033[1;44m"
#define BACKYELLOW     "\033[1;43m"
#define BACKBLACK    "\033[0;0m"
#define BLINK "\033[1;5m"

enum PositionP {ECURIE, EXTERIEUR, CENTRE};
enum CouleurJ {VERT, JAUNE, BLEU, ROUGE};

//On définit une strucure case
typedef struct{
  int x;
  int y;
}coordonnees;

typedef struct{
char contenu[3];
  coordonnees *coordCase;
}Case;

typedef struct{
  int numPion;
  enum PositionP plateau;
  enum CouleurJ couleurPion;
  int numCase;
  int decompteCase;
  coordonnees *coord;
}Pion;

//On déclare ses variables ici pour qu'elles soient visible dans tous les fichiers
//Le plateau extérieur est composé de 56 cases
coordonnees plateauExt[56];
coordonnees ecurie[12];
coordonnees centre[24];


//Case
void InitCaseExt(coordonnees plateauExt[]);
void InitEcurie(coordonnees ecurie[]);
void InitCentre(coordonnees centre[]);
//deplacement
void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour,const char couleur[][6]);
int DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,const char couleur[][6], int joueurDuTour);
int EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour);
int DeplacementCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour);
//jeu
int PremierJoueur(int nombreJoueur);
int LancerdeDes();
int ConditionFin(Pion jeu[],int joueurDuTour);
int Mouvements(int joueurDuTour, int scoreDes, Pion jeu[], int *action, int *pionDuTour, int whitelist[], int joueurIA[]);
int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,const char couleur[][6],Pion jeu[]);
void TestDeplacement(Pion jeu[], int joueurDuTour, int scoreDes, int valide[]);
//joueur
int ChoixCouleur(int nombreJoueur, int whitelist[], int i, Pion jeu[], int couleurPick[], int joueurDuTour, int scoreDes, int joueurIA[]);
void InitJoueur(int *nombreJoueur,int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);
//misc
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

//pion
void InitPion(Pion jeu[], coordonnees ecurie[]);
void AfficherPion(Pion jeu[],const char couleur[][6],const char partiePlateau[][10],int whitelist[]);
void UpdateCoord(Pion jeu[], coordonnees ecurie[], coordonnees plateauExt[], coordonnees centre[]);
//plateau
void AfficherPlateau(Pion jeu[]);
int CheckCoord(int *x, int y, Pion jeu[]);
//sauvegarde
void EcrireSauvegarde(int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);
void ChargerSauvegarde(int whitelist[], Pion jeu[], int *joueurDuTour, int *scoreDes, int joueurIA[]);
//IA
void InitIA(int *nombreJoueur, int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]);
int ChoixPionIA(int valide[], Pion jeu[]);
