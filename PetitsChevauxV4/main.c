#include <SDL/SDL.h>
#include "Case.h"
#include "pion.h"
#include "misc.h"
#include "joueur.h"
#include "jeu.h"


int main(void){
  srand(time(NULL));
  Pion jeu[16]; //On crée 16 pions
  int joueurDuTour, scoreDes,pionDuTour, action =0;

  InitJoueur(&nombreJoueur, whitelist);

  //PARTIE SDL
  //On initialise une surface (un rctangle à afficher)
  SDL_Surface *ecran = NULL, *background=NULL;
  //SDL_Surface *jeu[16];
  SDL_Rect positionBackground;
  positionBackground.x=0;
  positionBackground.y=0;

  InitCaseExt(plateauExt);
  InitEcurie(ecurie);
  InitCentre(centre);
  SDL_Init(SDL_INIT_VIDEO);

  InitPion(jeu, ecurie); // On initialise les pions

  //Chargement de la partie "video" de SDL et test de l'ouverture

    //Création de la fenêtre
  ecran= SDL_SetVideoMode(1000,1000,32,SDL_SWSURFACE);//(largeur,hauteur,nbcouleur,mémoire chargée dans la ram)
  SDL_WM_SetCaption("Petits Chevaux", NULL); // On donne un titre à la fenêtre

  //  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255, 255, 255)); // ecran en blanc
  //Chargement du plateau en .bmp
  background = SDL_LoadBMP("images/Plateau.bmp");
  SDL_BlitSurface(background, NULL, ecran, &positionBackground);
  PionImage(stockImages, ecran);
// FIN PARTIE SDL
InitPion(jeu, ecurie); // On initialise les pions
SDL_Flip(ecran);//mise à jour de l'écran
  do{
    joueurDuTour = PremierJoueur(nombreJoueur);
  }while(TestPresence(whitelist, 4, joueurDuTour)==-1);//On joue le dé du 1er joueur tant quil tombe sur un joueur inexistant
  while(ConditionFin(jeu, joueurDuTour)==0){
    printf("===================================================\n");
    joueurDuTour=JoueurSuivant(whitelist, joueurDuTour);
    do{
    scoreDes= LancerdeDes();
    AfficherPion(jeu, couleur, partiePlateau, whitelist);
    printf("===================================================\n");

    printf("Au tour du joueur %s !\n",couleur[joueurDuTour]);
    //do{
      printf("Le dé vaut %d\n", scoreDes);
      Mouvements(joueurDuTour, scoreDes, jeu);
      DeplacementPion(joueurDuTour, scoreDes,action, pionDuTour, jeu, ecran, positionBackground, background);

      SDL_Flip(ecran);//mise à jour de l'écran


    //}while(action == 100);


  }while(scoreDes==6); // Tant que le dé vaut 6 , le joueur rejoue.

    printf("===================================================\n");

  }
  printf("LE VANQUEUR EST LE JOUEUR : %s\n", couleur[joueurDuTour]);
  //Arrêt de la SDL
  SDL_FreeSurface(background);
  SDL_FreeSurface(*stockImages);
  SDL_Quit();
  return 0;
}
