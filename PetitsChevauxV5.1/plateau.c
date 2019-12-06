#include "main.h"
void AfficherPlateau(Pion jeu[]){
  for(int i=0; i<15; i++){
    for(int j=0; j<30; j++){
    do{}while(CheckCoord(&j,i,jeu));
      //Ecurie jaune
    if(i>=0 && i<=5 && j>=0 && j<=11){
     printf(BACKYELLOW" ");
   }  //Ecurie Bleu
   else if(i>=0 && i<=5 && j>=18 && j<=30){
     printf(BACKBLUE" ");
   }  //Ecurie Verte
   else if(i>=9 && i<=15 && j>=0 && j<=11){
     printf(BACKGREEN" ");
   }  //Ecurie rouge
   else if(i>=9 && i<=15 && j>=18 && j<=30){
     printf(BACKRED" ");
   }else if(i==7 && j>=16 && j<=27){
     printf(BACKRED" ");
   }else if(i>=8 && i<=13 && (j==14 || j==15)){
     printf(BACKGREEN" ");
   }else if(i==7 && j>=2 && j<=13){
     printf(BACKYELLOW" ");
   }else if(i>=1 && i<=6 &&(j==14 || j==15)){
     printf(BACKBLUE" ");
   }else{
     printf(BACKBLACK" ");
     }
    }
    printf("\033[8;m\n");
  }
}

int CheckCoord(int *x, int y, Pion jeu[]){
  for(int i=0; i<16; i++){
    if(jeu[i].coord->x==*x && jeu[i].coord->y==y){
      if(jeu[i].plateau==EXTERIEUR){
        printf(BACKBLACK"%d", jeu[i].numPion);

      }else if(jeu[i].plateau==CENTRE){
        if(jeu[i].couleurPion == 0){
          printf(BACKGREEN"%d", jeu[i].numPion);
        }else if(jeu[i].couleurPion == 1){
          printf(BACKYELLOW"%d", jeu[i].numPion);
        }else if(jeu[i].couleurPion == 2){
          printf(BACKBLUE"%d", jeu[i].numPion);
        }else if(jeu[i].couleurPion == 3){
          printf(BACKRED"%d", jeu[i].numPion);
        }

      }else{
        printf("%d", jeu[i].numPion);
      }
      if(jeu[i].numPion>9){
        (*x)++;
      }
      (*x)++;
      if(i<13 && jeu[i+1].coord->x==*x && jeu[i+1].coord->y==y){
        return(1);
      }
    }
  }
  return(0);
}
