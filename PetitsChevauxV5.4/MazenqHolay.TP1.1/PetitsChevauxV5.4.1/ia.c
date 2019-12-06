#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ia.h"

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

int ChoixPionIA(int valide[], Pion jeu[], int scoreDes){
int i=0, pionChoisi=-1;
/*On est obliger de tester les prioritées de chaque pion avant de prendre une décision
Ce modèle permet de choisir le pion qui possède la plus grande priorité
C'est pour cela qu'on teste tous les pions pour chaque priorité avant de passer à la suivante

On sait déjà que les pions peuvent être joués (la séléction a été faite avant)*/

/* 1: Si un pion peut entrer au centre, il le fait*/
while(i<4 && pionChoisi == -1){
  if(valide[i]!=-1){//Si il s'agit d'un pion à joueur
    if(jeu[valide[i]].plateau==EXTERIEUR && jeu[valide[i]].decompteCase ==0){ // Si le pion se trouve au pied des colonnes centrales et qu'il peut rentrer
      pionChoisi = valide[i];
    }
  }
  i++;
}
i=0;

/* 2: Si un pion peut en balyer un autre, il le fait*/
while(i<4 && pionChoisi == -1){
  if(valide[i]!=-1){//Si il s'agit d'un pion à joueur
    int caseArrivee= (jeu[valide[i]].numCase+scoreDes)%56;
    int j=0;
    while(j<16  && pionChoisi == -1 ){
      if(jeu[j].numCase==caseArrivee){
        pionChoisi=valide[i];
      }
      j++;

    }
  }
  i++;
}
i=0;
/* 3: Si un pion peut avancer dans le centre, il le fait*/
while(i<4 && pionChoisi == -1){
  if(valide[i]!=-1){//Si il s'agit d'un pion à joueur
    if(jeu[valide[i]].plateau==CENTRE){ // si le pion est dans le centre, on le fait avancer
      pionChoisi = valide[i];
    }
  }
  i++;
}
i=0;

/* 4: Si un pion adverse se trouve à moins de 7 cases, on fuit*/
while(i<4 && pionChoisi == -1){
  int j=0;
  while(j<16 && pionChoisi == -1){
    if(((jeu[valide[i]].numCase-jeu[j].numCase)+56)%56<7 && jeu[valide[i]].plateau == EXTERIEUR && jeu[valide[i]].plateau == EXTERIEUR){
      pionChoisi = valide[i];
    }
    j++;
  }
  i++;
}

/* 5: Si un pion peut sortir de l'écurie, il le fait*/
while(i<4 && pionChoisi == -1){
  if(valide[i]!=-1){//Si il s'agit d'un pion à joueur
    if(jeu[valide[i]].plateau==ECURIE){ // si le pion est dans l'écurie alors on le sort
      pionChoisi = valide[i];
    }
  }
  i++;
}
i=0;

/*while(i<4 && pionChoisi ==-1){//WARNING La premier pion croisé qui possède une priorité est choisie
  i++;
}*/

/*Si aucun cas prioritaire n'a été choisi, on choisit un pion aléatoirement*/
if(pionChoisi == -1){
  do{
    i=rand()%4;// rand()%(MAX-MIN+1)+MIN
  }while(valide[i]==-1);
  pionChoisi=valide[i];
}

return(pionChoisi);
}
