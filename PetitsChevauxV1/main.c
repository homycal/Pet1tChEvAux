#include "joueur.h"
#include "plateau.h"
#include "jeu.h"




int main(void){
  srand(time(NULL));
  Debut();
  InitPlateau(&jeu);


  joueurDuTour=PremierJoueur(nombreJoueur);

  while(ConditionFin(joueurDuTour, &jeu)==0){
    printf("===================================================\n");
    printf("Au tour du joueur %s\n",couleur[participant[joueurDuTour].couleur]);
    do{

    scoreDes = LancerdeDes();
    printf("Le dé vaut %d\n", scoreDes);
    do{
      if(Mouvements(joueurDuTour, scoreDes)!=0){
      DeplacementPion(joueurDuTour, scoreDes, action, pionDuTour, &jeu);
    }
  }while(action==100); // On relance tant que l'action proposé pas le joueur est infaisable7
  for(int i=0; i<56; i++){
    printf("Case %d = ",i);
    for(int j=0; j<4; j++){
      printf(" %d ;",jeu.plateau[i].contenu[j]);
    }
    printf("\n");
  }

    /*for (int i=0; i<56; i+=4){
      printf("Case %d = %d    Case %d = %d    Case %d = %d Case %d = %d\n", i, plateau[i],i+1, plateau[i+1],i+2, plateau[i+2], i+3, plateau[i+3]);
    }*/

  }while(scoreDes==6);// Tant que le joueur fais 6 il peut rejouer
  joueurDuTour ++;
  if(joueurDuTour>nombreJoueur){
    joueurDuTour=0;
  }
  printf("===================================================\n");
}
  return 0;
}
