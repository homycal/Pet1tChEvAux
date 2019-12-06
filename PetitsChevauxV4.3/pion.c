#include "main.h"

//Fonction permettant d'initialiser la valeur des pions
void InitPion(Pion jeu[], Case ecurie[]){
  for(int i=0; i<16; i++){
    jeu[i].numPion=i;
    jeu[i].plateau=ECURIE;
    jeu[i].couleurPion=i/4;
    jeu[i].numCase=1; //Chaque écurie est différenciée pas la couleur du pion
    jeu[i].decompteCase=55;

  }
}
//Fonction permettant d'afficher toutes les caractéristiques de chaque pion
void AfficherPion(Pion jeu[],const char couleur[][6],const char partiePlateau[][10],int whitelist[]){
 for(int i=0; i<16; i++){

  if(jeu[i].couleurPion == whitelist[0]||jeu[i].couleurPion== whitelist[1] || jeu[i].couleurPion== whitelist[2]||jeu[i].couleurPion== whitelist[3]){
    printf("Pion n°%d de couleur %s\n",jeu[i].numPion, couleur[jeu[i].couleurPion]);
    printf("\t Position : %s Case : %d\n", partiePlateau[jeu[i].plateau], jeu[i].numCase);
    }
  }
}


//On associe une image à chaque pion
void PionImage(SDL_Surface *jeu[],  SDL_Surface *ecran){
  //  Chargement des pions
  jeu[0] = SDL_LoadBMP("images/Pion0.bmp");
  jeu[1] = SDL_LoadBMP("images/Pion1.bmp");
  jeu[2] = SDL_LoadBMP("images/Pion2.bmp");
  jeu[3] = SDL_LoadBMP("images/Pion3.bmp");

  jeu[4] = SDL_LoadBMP("images/Pion4.bmp");
  jeu[5] = SDL_LoadBMP("images/Pion5.bmp");
  jeu[6] = SDL_LoadBMP("images/Pion6.bmp");
  jeu[7] = SDL_LoadBMP("images/Pion7.bmp");

  jeu[8] = SDL_LoadBMP("images/Pion8.bmp");
  jeu[9] = SDL_LoadBMP("images/Pion9.bmp");
  jeu[10] = SDL_LoadBMP("images/Pion10.bmp");
  jeu[11] = SDL_LoadBMP("images/Pion11.bmp");

  jeu[12] = SDL_LoadBMP("images/Pion12.bmp");
  jeu[13] = SDL_LoadBMP("images/Pion13.bmp");
  jeu[14] = SDL_LoadBMP("images/Pion14.bmp");
  jeu[15] = SDL_LoadBMP("images/Pion15.bmp");
  for(int i=0; i<16;i++){
    SDL_SetColorKey(jeu[i],SDL_SRCCOLORKEY,SDL_MapRGB(jeu[i]->format,0,0,255)); // On dit que le bleu devient transparant
    SDL_BlitSurface(jeu[i], NULL, ecran, &ecurie[i].coordonnees);//On affiche
  }
}

void UpdateEcran(SDL_Surface *stockImages[], SDL_Surface *ecran, SDL_Rect positionBackground, SDL_Surface *background, int pionDuTour, Pion jeu[]){
  SDL_BlitSurface(background, NULL, ecran, &positionBackground);
  for(int i=0; i<16; i++){
    if(jeu[i].plateau == ECURIE){
      SDL_BlitSurface(stockImages[i], NULL, ecran, &ecurie[i].coordonnees);//On affiche
    }
    if(jeu[i].plateau == EXTERIEUR){
      SDL_BlitSurface(stockImages[i], NULL, ecran, &plateauExt[jeu[i].numCase].coordonnees);//On affiche

    }
    if(jeu[i].plateau == CENTRE){
      SDL_BlitSurface(stockImages[i], NULL, ecran, &centre[((jeu[i].numCase)+6*(jeu[i].numPion/4))-1].coordonnees);//jeu[i].numPion/4 pour retrouver le joueur sans l'appeler
                                                                                                  //-1 car la case [1] de centre correspond à l'indice 0
    }
  }
  SDL_Flip(ecran);

}
