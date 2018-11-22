#include <stdio.h>
#include <stdlib.h>

enum PositionP {ECURIE, EXTERIEUR, CENTRE};

enum CouleurJ {VERT, JAUNE, BLEU, ROUGE};

typedef struct{
  int numPion;
  enum PositionP plateau;
  enum CouleurJ couleurPion;
  int numCase;
}Pion;

char couleur[][6]={"vert", "jaune","bleu","rouge"};
char partiePlateau[][10]={"écurie","exterieur","centre"};
Pion jeu[16]; //On crée 16 pions
//Fonction permettant d'initialiser la valeur des pions
void InitPion(Pion jeu[]){
  for(int i=0; i<16; i++){
    jeu[i].numPion=i;
    jeu[i].plateau=ECURIE;
    jeu[i].couleurPion=i/4;
    jeu[i].numCase=1; //Chaque écurie est différenciée pas la couleur du pion
  }
}
//Fonction permettant d'afficher toutes les caractéristiques de chaque pion
void AfficherPion(Pion jeu[],char couleur[][6],char partiePlateau[][10],int whitelist[]){
 for(int i=0; i<16; i++){

  if(jeu[i].couleurPion == whitelist[0]||jeu[i].couleurPion== whitelist[1] || jeu[i].couleurPion== whitelist[2]||jeu[i].couleurPion== whitelist[3]){
    printf("Pion n°%d de couleur %s\n",jeu[i].numPion, couleur[jeu[i].couleurPion]);
    printf("    Position : %s Case : %d\n", partiePlateau[jeu[i].plateau], jeu[i].numCase);
    }
  }
}
