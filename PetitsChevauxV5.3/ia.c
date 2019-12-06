#include "main.h"

void InitIA(int *nombreJoueur, int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[]){
  int couleurPick[4]={0,0,0,0};
  do{
    printf("Combien d'IA souhaitez vous intégrer ? (3 max)\n");
    *nombreJoueur=LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes, joueurIA)+1;
  }while(*nombreJoueur<2 || *nombreJoueur >4);
  printf("Vous êtes le joueur 0.\n");

  for(int i=0; i<*nombreJoueur; i++){
    whitelist[i]=ChoixCouleur(*nombreJoueur, whitelist, i, jeu, couleurPick, joueurDuTour, scoreDes, joueurIA);
    couleurPick[whitelist[i]]= 1; // On déclare cette couleur comme prise
    if(i!=0){//si le joueur testé est une IA
      joueurIA[whitelist[i]]=whitelist[i];//On change la valeur de -1
    }

    printf("\n");
  }

}

int ChoixPionIA(int valide[], Pion jeu[]){
  for(int i=0; i<4; i++){
    if(valide[i]!=-1){
      return(valide[i]);
    }
  }
  return(-1);
}
