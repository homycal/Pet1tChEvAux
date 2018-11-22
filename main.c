#include "pion.h"
#include "misc.h"
#include "joueur.h"
#include "jeu.h"
//#include "deplacement.h"

int main(void){
  InitPion(jeu);
  InitJoueur(&nombreJoueur, whitelist);
  do{
      joueurDuTour = PremierJoueur(nombreJoueur);
  }while(TestPresence(whitelist, 4, joueurDuTour)==-1);//On joue le dé du 1er joueur tant quil tombe sur un joueur inexistant
  while(ConditionFin(jeu, joueurDuTour)==0){
    printf("===================================================\n");
    do{
    scoreDes= LancerdeDes();
    printf("Au tour du joueur %s !\n",couleur[joueurDuTour]);
    do{
      printf("Le dé vaut %d\n", scoreDes);
      Mouvements(joueurDuTour, scoreDes, jeu);
      DeplacementPion(joueurDuTour, scoreDes,action, pionDuTour, jeu);

    }while(action == 100);

    printf("===================================================\n");

    AfficherPion(jeu, couleur, partiePlateau, whitelist);

  }while(scoreDes==6); // Tant que le dé vaut 6 , le joueur rejoue.
    joueurDuTour=JoueurSuivant(whitelist, joueurDuTour);
    printf("===================================================\n");

  }
  return 0;
}
