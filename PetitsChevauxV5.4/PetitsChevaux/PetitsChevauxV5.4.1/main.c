#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

const char couleur[][6]={"vert", "jaune","bleu","rouge"};
const char partiePlateau[][10]={"écurie","exterieur","centre"};

int main(void){
  srand(time(NULL));
/*Déclaration des variables et initialisation des coordonnées des cases du plateau*/
  Pion jeu[16]; //On crée 16 pions
  int joueurDuTour=-1, scoreDes=-1,pionDuTour, action =0, nombreJoueur, chargement, modeJeu;
  int whitelist[4]={-1,-1,-1,-1};//Stockera les joueurs de la partie
  int joueurIA[4]={-1,-1,-1,-1};//On comparera a whitelist pour savoir si le joueur est une IA

  InitCaseExt(plateauExt);
  InitEcurie(ecurie);
  InitCentre(centre);

/*Paramètres de la partie*/
  do{
    printf("1. Commencer une nouvelle partie\n2. Charger la dernière sauvegarde\n");
    chargement = LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes, joueurIA);
  }while(chargement !=1 && chargement !=2);

  if(chargement == 1){ // La partie s'initialise de 0
    do{
      printf("Quel mode de jeu choisissez vous ?\n1. Solo\n2. Multi\n");
      modeJeu= LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes, joueurIA);
    }while(modeJeu != 1 && modeJeu != 2);

    if(modeJeu == 1){
      /*On lance le programme pour initialiser les IAs*/
      InitIA( &nombreJoueur, whitelist, jeu, joueurDuTour,scoreDes,joueurIA);
    }else{
      /*On lance le programme pour initialiser les différents joueurs*/
      InitJoueur(&nombreJoueur, whitelist, jeu, joueurDuTour, scoreDes, joueurIA);
    }
    /*On initialise chaque pion*/
    InitPion(jeu, ecurie);

    do{
      joueurDuTour = PremierJoueur(nombreJoueur);
    }while(TestPresence(whitelist, 4, joueurDuTour)==-1);
    /*On joue le dé du 1er joueur tant qu'il tombe sur un joueur inexistant*/

  }else{
    ChargerSauvegarde(whitelist, jeu, &joueurDuTour, &scoreDes, joueurIA);
  }
  //AfficherPlateau(jeu);

  printf("\nChargement de 5 secondes\nN'oubliez pas, vous pouvez sauvegarder dés qu'une saisie vous est demandée !\nIl suffit d'entrer 's' ! \n\nSi 2 pions sont superposés, ils clignoteront.\n ");
  sleep(5);//on fait une pause de 5 secondes pour laisser le temps de lire

  while(ConditionFin(jeu, joueurDuTour)==0){
    if(chargement!=2){ // si on a chargé la partie, on empêche de passer au joueur suivant dés le début du tour
      joueurDuTour=JoueurSuivant(whitelist, joueurDuTour);

    }
    do{
      if(chargement !=2){
        scoreDes= LancerdeDes(); // si on a chargé la partie, on ne relance pas le dé la première fois
      }
    chargement=0; // On débloque les conditions au dessus pour les prochains tour;
    printf("==========================================================\n");
    //AfficherPion(jeu, couleur, partiePlateau, whitelist);
    /*Si le plateau pose problème décommenter AfficherPion()*/

    printf("Au tour du joueur %s !\n",couleur[joueurDuTour]);

    UpdateCoord(jeu, ecurie, plateauExt, centre);
    AfficherPlateau(jeu);

    printf("Le dé vaut %d\n", scoreDes);
    Mouvements(joueurDuTour, scoreDes, jeu, &action, &pionDuTour, whitelist, joueurIA);
    DeplacementPion(joueurDuTour, scoreDes,action, pionDuTour,couleur, jeu);




  }while(scoreDes==6); // Tant que le dé vaut 6 , le joueur rejoue.
  //printf("\033[2J"); // On clean le terminal


  }
  UpdateCoord(jeu, ecurie, plateauExt, centre);
  printf("\033[2J"); // On clean le terminal
  AfficherPlateau(jeu);
  printf("==========================================================\n");
  AfficherPion(jeu, couleur, partiePlateau, whitelist);
  printf("LE VANQUEUR EST LE JOUEUR : %s\n", couleur[joueurDuTour]);
  return 0;
}
