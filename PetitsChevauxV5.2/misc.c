#include "main.h"


int TestPresence(int tab[], int n, int valTest){
  int presence=-1;
  for(int i=0; i<n; i++){
    if(tab[i]==valTest){
      presence = i;
    }
  }
  return(presence); // Si Test presence renvoi -1, la valeur n'est pas trouvée dans le tablau,
  //autrement elle renvoie l'indice de la dernière occurence trouvée
}
int PresencePlateau(Pion jeu[], int pionDuTour){//renvoie le plateau du pion
  int presence =-1;
  for(int i=0; i<16;i++){
    if(jeu[i].numPion == pionDuTour){
      presence=jeu[i].plateau;
    }
  }
  return(presence);
}
int VerifEcurie(Pion jeu[], int pionTest){
  if(jeu[pionTest].plateau == ECURIE){
    return(1);
  }else{
    return(0);
  }
}

/*int ChoixPion(Pion jeu[],int joueurDuTour, int whitelist[],int scoreDes){
  int choix;
  do{
    //printf("Quel pion souhaitez vous jouer ?\n0. %d\n1. %d\n2. %d\n3. %d\n",
    //((joueurDuTour*4)%16),((joueurDuTour*4)%16)+1,((joueurDuTour*4)%16)+2,((joueurDuTour*4)%16)+3);
    choix=LireEntier(whitelist, jeu ,1, joueurDuTour, scoreDes);
  }while(choix<0 ||choix >3);
  printf("Vous avez choisi le pion %d\n",((joueurDuTour*4)%16)+choix);


  return(((joueurDuTour*4)%16)+choix);
}*/

int JoueurSuivant(int whitelist[],int joueurDuTour){
  do{
    joueurDuTour= (joueurDuTour+1)%4;
  }while(TestPresence(whitelist,4,joueurDuTour)==-1);
  return(joueurDuTour);

}

int DetectionBlocage(Pion jeu[], int pionDuTour, int scoreDes){
  int bloqueur = -1;
  for(int i=0; i<16; i++){
    for(int j=0;j<scoreDes;j++){
      if(jeu[i].couleurPion != jeu[pionDuTour].couleurPion && (jeu[i].numCase>jeu[pionDuTour].numCase && (jeu[i].numCase)<=(jeu[pionDuTour].numCase+scoreDes-1)%55) && jeu[i].plateau==EXTERIEUR && jeu[pionDuTour].plateau==EXTERIEUR){
/**Si le pion est d'une couleur différente que le pion du tour ET
Si il se trouve entre le pion du tour et la position qu'il doit atteindre (sans l'égaler)ET
Si le pion testé se trouve bien sur le plateau exterieur ET
Si notre pion se trouve aussi en exterieur*/
        bloqueur =i;
      }

    }
  }
  return(bloqueur);
}

void Manger(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour, int CaseDepart, char const couleur[][6]){
  for(int i=0; i<16; i++){
    for(int j=0;j<scoreDes;j++){//on utilise CaseDepart afin de pouvoir aussi utiliser la fonction lors de la sortie d'écurie
      if(jeu[i].couleurPion != jeu[pionDuTour].couleurPion && jeu[i].numCase==(CaseDepart+scoreDes)%55 && jeu[i].plateau==EXTERIEUR){
        //On renvoie le pion concernés dans leur écurie.
          jeu[i].plateau = ECURIE;
          jeu[i].numCase =1;
          printf("Le pion %d a été renvoyé a l'écurie %s !\n", i, couleur[jeu[i].couleurPion]);
      }

    }
  }

}

int CaseLibre(Pion jeu[], int scoreDes, int pionTest, int CaseDepart){//permet de savoir si la case suivante de la colonne intérieure est libre
  int occupe = -1;
  for(int i=0; i<16;i++){
    if(jeu[i].couleurPion==jeu[pionTest].couleurPion && jeu[i].plateau==CENTRE && jeu[i].numCase==CaseDepart+1){ // On cherche si un pion bloque
      occupe = i;
    }
  }
  return(occupe);
}

int LireEntier(int whitelist[], Pion jeu[], int save, int joueurDuTour, int scoreDes){
  char nombre[3]="..";//On met des caractères invalide pour être sur de devoir lire
  char *posEntree=NULL;
  char c='o';
  char autoriser[11]="0123456789";
  do{
    printf("Saisissez un nombre : ");
    if(fgets(nombre, 3, stdin)!=NULL){// fgets renvoi NULL en cas d'erreur lors de la lecture
    posEntree=strchr(nombre, '\n'); // on cherche \n
    if(posEntree!=NULL){ // si il existe
      *posEntree='\0'; // remplace \n par \0
    }else{// si on a pas de \n, on a pas atteint le bout de la chaine, donc il reste des choses dans le buffer
      while(c != '\n' && c!= EOF){ //on vide le buffer jusqu'au End-of-File
        c = getchar();
      }
    }
    //ICI ON DEFINIT LE MOYEN DE SEUVEGARDER
    if(save == 1 && nombre[0]=='s'){ // grace à save, la sauvegarde ne sera autorisée que dans choixPion
      EcrireSauvegarde(whitelist, jeu, joueurDuTour, scoreDes);
      printf("Partie sauvegardée !\n");
    }
  }else{
    printf("Erreur lors de la lecture\n");
  }
  }while(TestPresenceChar(autoriser, 11, nombre[0])!=1 || TestPresenceChar(autoriser, 11, nombre[1])!=1);
  //Tant qu'un caractère n'est pas autotisé, on relance

  return atoi(nombre);//Sert à convertir une chaine de caractère en entier
}

int TestPresenceChar(char tab[], int n, char valTest){
  int presence=-1;
  for(int i=0; i<n; i++){
    if(tab[i]==valTest){
      presence = 1;
    }
  }
  return(presence); // Si Test presence renvoi -1, la valeur n'est pas trouvée dans le tablau,
  //autrement elle renvoie l'indice de la dernière occurence trouvée
}
