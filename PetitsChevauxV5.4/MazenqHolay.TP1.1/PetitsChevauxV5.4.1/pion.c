#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "pion.h"

//Fonction permettant d'initialiser la valeur des pions
void InitPion(Pion jeu[], coordonnees ecurie[]){
  for(int i=0; i<16; i++){
    jeu[i].numPion=i;
    jeu[i].plateau=ECURIE;
    jeu[i].couleurPion=i/4;
    jeu[i].numCase=1; //Chaque écurie est différenciée pas la couleur du pion
    jeu[i].decompteCase=55;
    jeu[i].coord=&ecurie[i]; // on donne une adresse au pointeur

  }
}
//Fonction permettant d'afficher les caractéristiques de chaque pion
void AfficherPion(Pion jeu[],const char couleur[][6],const char partiePlateau[][10],int whitelist[]){
 for(int i=0; i<16; i++){

  if(jeu[i].couleurPion == whitelist[0]||jeu[i].couleurPion== whitelist[1] || jeu[i].couleurPion== whitelist[2]||jeu[i].couleurPion== whitelist[3]){
    printf("Pion n°%d de couleur %s\n",jeu[i].numPion, couleur[jeu[i].couleurPion]);
    printf("\t Position : %s Case : %d\n", partiePlateau[jeu[i].plateau], jeu[i].numCase);
    }
  }
}

void UpdateCoord(Pion jeu[], coordonnees ecurie[], coordonnees plateauExt[], coordonnees centre[]){
  for(int i=0; i<16; i++){
    if(jeu[i].plateau == ECURIE){
      jeu[i].coord=&ecurie[i];
    }
    if(jeu[i].plateau == EXTERIEUR){
      jeu[i].coord=&plateauExt[jeu[i].numCase];
    }
    if(jeu[i].plateau == CENTRE){
      jeu[i].coord=&centre[(jeu[i].numCase)+6*(jeu[i].numPion/4)-1];//jeu[i].numPion/4 pour retrouver le joueur sans l'appeler
                                                                //-1 car la case [1] de centre correspond à l'indice 0
    }

  }
}
