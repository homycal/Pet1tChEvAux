#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int contenu[4]; // chaque case peut contenir jusqu'à 4 pions de la même couleur
  int couleur; // Si couleur = 4 , on l'associe à Neutre
}Case;

typedef struct{
Case plateau[56]; // Le plateau extérieur va de la case 0 à 55
Case ecuries[4]; // Une case écurie qui contient les 4 pions de la même couleur
Case colonnes[24]; // 4 couleurs et 6 cases
}Plateau;

Plateau jeu;
/*Quand une case n'a aucun pion dessus, on lui attribue la valeur -1.
Sinon elle prend la valeur du pion
indice 0 = Sortie d'écurie du vert
		  0->55 = cases extérieures*/
void InitPlateau(Plateau *jeu){
// On définit toutes les cases extérieures à -1
  for(int i=0; i<56; i++){
    for(int j=0; j<4;j++){
    jeu->plateau[i].contenu[j]=-1;
    jeu->plateau[i].couleur=4;
  }
  }
// La même chose avec les colonnes intérieures
int k=0;

  for(int i=0; i<24;i++){
    for(int j=0; j<4;j++){
      jeu->colonnes[i].contenu[j]=-1;
      jeu->colonnes[i].couleur=k; // Les cases centrales possèdent une couleur (attribuée par k)
    }
    if(i%24 == 0){k++;} // Si on a atteint 6 cases pour une couleur on passe à la suivante
  }                     //C/est comme les modulos en maths le %
  k=0;
  for(int i=0; i<4;i++){
    for(int j=0; j<4; j++){
      jeu->ecuries[i].contenu[j]=k; // Les n° de pions vont de 0 à 15 (0->3 vert | 4->7 jaune| 8->11 bleu| 12->15 rouge)
      k++;  //Donc on attribue à chaque case d'écurie (représentée par j) la valeur des 4 pions à la suite
    }
    jeu->ecuries[i].couleur=i;
  }
}
