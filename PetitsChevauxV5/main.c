#include "main.h"

const char couleur[][6]={"vert", "jaune","bleu","rouge"};
const char partiePlateau[][10]={"écurie","exterieur","centre"};

int main(void){
  srand(time(NULL));
  Pion jeu[16]; //On crée 16 pions
  int joueurDuTour, scoreDes,pionDuTour, action =0, nombreJoueur;
  int whitelist[4]={-1,-1,-1,-1};

  InitJoueur(&nombreJoueur, whitelist);


  InitCaseExt(plateauExt);
  InitEcurie(ecurie);
  InitCentre(centre);

  InitPion(jeu, ecurie); // On initialise les pions
  AfficherPlateau(jeu);


  do{
    joueurDuTour = PremierJoueur(nombreJoueur);
  }while(TestPresence(whitelist, 4, joueurDuTour)==-1);//On joue le dé du 1er joueur tant quil tombe sur un joueur inexistant

  while(ConditionFin(jeu, joueurDuTour)==0){
    joueurDuTour=JoueurSuivant(whitelist, joueurDuTour);
    do{
    scoreDes= LancerdeDes();
    AfficherPion(jeu, couleur, partiePlateau, whitelist);

    printf("Au tour du joueur %s !\n",couleur[joueurDuTour]);
    //do{
    //UpdateCoord(jeu, ecurie, plateauExt, centre);
    //AfficherPlateau(jeu);

    printf("Le dé vaut %d\n", scoreDes);
    Mouvements(joueurDuTour, scoreDes, jeu, &action, &pionDuTour);
    DeplacementPion(joueurDuTour, scoreDes,action, pionDuTour,couleur, jeu);



    //}while(action == 100);

  }while(scoreDes==6); // Tant que le dé vaut 6 , le joueur rejoue.
  //printf("\033[2J"); // On clean le terminal


  }
  //UpdateCoord(jeu, ecurie, plateauExt, centre);
  //printf("\033[2J"); // On clean le terminal
  //AfficherPlateau(jeu);
  printf("LE VANQUEUR EST LE JOUEUR : %s\n", couleur[joueurDuTour]);
  return 0;
}
