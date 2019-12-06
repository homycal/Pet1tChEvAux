#include "main.h"
void AfficherPlateau(Pion jeu[]){
  int i=0, j=0;
  while(i<15){
    j=0;
    while(j<30){// On utilise des whiles car on veut pouvoir modifier i et j dans la boucle
    do{}while(CheckCoord(&j,i,jeu)); //Comme on a modifié j, on regarde directement après si iln'y a pas un autre pion à afficher
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
     j++;
    }
    printf("\033[8;m\n");
    i++;
  }
}
int CheckCoord(int *x, int y, Pion jeu[]){
  int i=0, numPion=-1;// numPion contient le numéro du pion à écrire
  int cpt=0; // variable servant à compter le nombre de pions sur la case
    while(i<16){
      //D'abord on décide quoi écrire
      if(jeu[i].coord->x==*x && jeu[i].coord->y==y){
        numPion=i; // On écrit le dernier pion testé
        cpt++;
      }
      i++;
    }
    /*-------------------------------------------------------------------*/

        //Puis on écrit
      if(cpt>0){ // Si il y a au moins un pion à écrire
        if(jeu[numPion].plateau==EXTERIEUR){// Si le pion se trouve sur les cases extérieures
          //printf("%d",*cpt);
          if(cpt==1){
            printf(BACKBLACK"%d", numPion);

          }else{ // Si plusieurs pions sont superposés, on fait clignoter pour avertir
            printf(BACKBLACK"\033[1;5m%d", numPion);

          }
        }else if(jeu[numPion].plateau==CENTRE){
          switch(jeu[i].couleurPion){
            case(0):
              printf(BACKGREEN"%d", numPion);
              break;
            case(1):
              printf(BACKYELLOW"%d", numPion);
              break;
            case(2):
              printf(BACKBLUE"%d", numPion);
              break;
            case(3):
              printf(BACKRED"%d", numPion);
          }
          // Pour le cas de l'écurie, pas beosin de faire ces manipulations
        }else{
          printf("%d", numPion);

        }
        /*-------------------------------------------------------------------*/
        //On déplace le curseur de la colonne du nombre de caractère écrit
        (*x)++;
        if(numPion>9){
           (*x)++;
        //   flag=1;
          // numPion=0; // on reset numPion si jamais on doit afficher à nouveau un autre pion a 2 chiffres inférieur à celui d'afficher
        }
        return(1);//Comme on a modifié j, on regarde directement après si iln'y a pas un autre pion à afficher
      }

  return(0);
}
