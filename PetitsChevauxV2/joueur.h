#include <stdio.h>
#include <stdlib.h>
int ChoixCouleur(int nombreJoueur, int whitelist[], int i );
void InitJoueur(int *nombreJoueur,int whitelist[]);


int nombreJoueur;
int whitelist[4]={-1,-1,-1,-1};
void InitJoueur(int *nombreJoueur,int whitelist[]){
  do{
    printf("Combien de joueurs êtes vous ? ");
    scanf("%d", nombreJoueur);
  }while(*nombreJoueur<1 || *nombreJoueur>4); // Mis a 1 pour faciliter les tests
  for(int i=0; i<*nombreJoueur; i++){
    whitelist[i]=ChoixCouleur(*nombreJoueur, whitelist, i);
  }
}

int ChoixCouleur(int nombreJoueur, int whitelist[], int i ){
  int choix, j=0, cpt;
    printf("Joueur n°%d, quelle couleur choisissez vous ?\n0. Vert\n1. Jaune\n2. Bleu\n3. Rouge\n",i);
  do{
    scanf("%d", &choix);
    j=0;
    cpt=0;
    while(j<4){
      if(choix==whitelist[j]){
        printf("Cette couleur est déjà prise !\nVeuillez chosir une autre couleur: ");
        break;
      }else{
        cpt++;
      }
      j++;
    }

  }while(cpt<4 || (choix<0||choix>3));
  return(choix);
}
