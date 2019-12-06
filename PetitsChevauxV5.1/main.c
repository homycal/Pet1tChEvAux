#include "main.h"

const char couleur[][6]={"vert", "jaune","bleu","rouge"};
const char partiePlateau[][10]={"écurie","exterieur","centre"};

int main(void){
  srand(time(NULL));
  Pion jeu[16]; //On crée 16 pions
  int joueurDuTour=-1, scoreDes=-1,pionDuTour, action =0, nombreJoueur, chargement;
  int whitelist[4]={-1,-1,-1,-1};
  InitCaseExt(plateauExt);
  InitEcurie(ecurie);
  InitCentre(centre);

  do{
    printf("1. Commencer une nouvelle partie\n2. Charger la dernière sauvegarde\n");
    chargement = LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes);
  }while(chargement !=1 && chargement !=2);

  if(chargement == 1){ // La partie s'initialise de 0
    InitJoueur(&nombreJoueur, whitelist, jeu, joueurDuTour, scoreDes);
    InitPion(jeu, ecurie);
    do{
      joueurDuTour = PremierJoueur(nombreJoueur);
    }while(TestPresence(whitelist, 4, joueurDuTour)==-1);//On joue le dé du 1er joueur tant quil tombe sur un joueur inexistant

  }else{
    ChargerSauvegarde(whitelist, jeu, &joueurDuTour, &scoreDes);
  }
  //AfficherPlateau(jeu);

  printf("N'oubliez pas, vous pouvez sauvegarder dés qu'une saisie vous est demandée !\nIl suffit d'entrer 's' ! \n");
  sleep(5);//on fait une pause de 5 secondes pour laisser le temps de lire

  while(ConditionFin(jeu, joueurDuTour)==0){
    if(chargement!=2){ // si on a chargé la partie, on empêche de passer au joueur suivant dés le début du tour
      joueurDuTour=JoueurSuivant(whitelist, joueurDuTour);

    }
    do{
      if(chargement !=2){
        scoreDes= LancerdeDes(); // si on a chargé la partie, on ne relance pas le dé la première fois
      }
      chargement=0;
    AfficherPion(jeu, couleur, partiePlateau, whitelist);

    printf("Au tour du joueur %s !\n",couleur[joueurDuTour]);
    //do{
    //UpdateCoord(jeu, ecurie, plateauExt, centre);
    //AfficherPlateau(jeu);

    printf("Le dé vaut %d\n", scoreDes);
    Mouvements(joueurDuTour, scoreDes, jeu, &action, &pionDuTour, whitelist);
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
