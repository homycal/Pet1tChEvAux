#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "sauvegarde.h"

void ChargerSauvegarde(int whitelist[], Pion jeu[], int *joueurDuTour, int *scoreDes, int joueurIA[]){
    FILE *fichier = NULL;
    fichier = fopen("save.txt", "r");
    if(fichier != NULL){ //Si le fichier est bien chargé en mémoire

      rewind(fichier); // on place le curseur au début

      //On récupère le contenu de whitelist
      if(fscanf(fichier, "%d;%d;%d;%d\n",&whitelist[0], &whitelist[1], &whitelist[2], &whitelist[3])!=4){ //fscanf renvoie le nombre de paramètres lus
        printf("Erreur lors du chergement de whitelist\n");
      }
      //On charge le contenu de joueurIA
      if(fscanf(fichier, "%d;%d;%d;%d\n",&joueurIA[0], &joueurIA[1], &joueurIA[2], &joueurIA[3])!=4){ //fscanf renvoie le nombre de paramètres lus
        printf("Erreur lors du chergement de joueurIA\n");
      }

      //On place le curseur au débur de la ligne suivante
      //fseek(fichier,1,SEEK_CUR);//il reste juste le caractère \n sur la ligne donc on passe outre
      //Chaque ligne correspond à un pion
      for(int i=0; i<16; i++){
        if(fscanf(fichier,"%d;%d;%d\n",(int*)&jeu[i].plateau, &jeu[i].numCase, &jeu[i].decompteCase)==3){ // on fait un cast vers int* car plateau est une énumération
          jeu[i].numPion=i;
          jeu[i].couleurPion=i/4;
          //On a pas besoin de sauvegarder les coordonées car UpdateCoord() reliera tout lors du chargement
        }else{
          printf("Erreur lors du chargement du pion %d",i);
        }
      }
      //On charge le joueur du tour
      if(fscanf(fichier,"%d", joueurDuTour)!=1){
        printf("Erreur lors du chargement de joueurDuTour");
      }
      //On charge le score du dé
      if(fscanf(fichier,"%d\n", scoreDes)!=1){
        printf("Erreur lors du chargement de scoreDes");
      }
      fclose(fichier);
    }else{
      printf("Erreur lors de l'ouverture du fichier");
    }

}

void EcrireSauvegarde(int whitelist[], Pion jeu[], int joueurDuTour, int scoreDes, int joueurIA[] ){
  FILE *fichier = NULL;
  fichier = fopen("save.txt", "w+"); //w+ reinitialise le fichier et l'ouvre en écriture
  if(fichier != NULL){ //Si le fichier est bien chargé en mémoire

    rewind(fichier); // on place le curseur au début

    //On récupère le contenu de whitelist
    fprintf(fichier, "%d;%d;%d;%d\n",whitelist[0], whitelist[1], whitelist[2], whitelist[3]);
    //On stock le contenu de joueurIA
    fprintf(fichier, "%d;%d;%d;%d\n", joueurIA[0], joueurIA[1], joueurIA[2], joueurIA[3]);
    //Chaque ligne correspond à un pion
    for(int i=0; i<16; i++){
      fprintf(fichier,"%d;%d;%d\n",jeu[i].plateau, jeu[i].numCase, jeu[i].decompteCase);
      jeu[i].numPion=i;
      jeu[i].couleurPion=i/4;
    }
    //On inscrit le joueurDuTour
    fprintf(fichier,"%d\n",joueurDuTour );
    //On inscrit le score du dé
    fprintf(fichier, "%d",scoreDes );
    fclose(fichier);
  }else{
    printf("Erreur lors de l'ouverture du fichier");
  }
  UpdateCoord(jeu, ecurie, plateauExt, centre); // Pour relier les pions au bonnes coordonées

}
