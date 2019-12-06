#include <stdio.h>
#include <stdlib.h>

enum CouleurJ {VERT,JAUNE,BLEU,ROUGE};
typedef struct{
  enum CouleurJ couleur; // Chaque joueur pssède 4 pions et un couleur (0-> vert| 1-> jaune| 2-> bleu| 3-> rouge )
  int pions[4];
}joueur;

int nombreJoueur;

char couleur[][6]={"vert", "jaune", "bleu", "rouge"};

//Inititalisation des joueurs
joueur participant[4] ={ {VERT, {0,1,2,3}},// on donne la couleur et les pions
                         {JAUNE, {4,5,6,7}},
                         {BLEU, {8,9,10,11}},
                         {ROUGE, {12,13,14,15}}};



void Debut(){
  printf("Bienvenue dans ce programme de petits chevaux !\n");
  do{
  printf("Combien de joueurs êtes-vous ? ");

    scanf("%d", &nombreJoueur);

}while(nombreJoueur < 1 || nombreJoueur >4); //WARNING J'ai mis pour tester rapidement les bugs, sinon faut jour à min 2
nombreJoueur--; // Pour la concordance des indices, on va pouvoir repartir de l'indice 0 pour les calculs
}
