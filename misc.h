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
int VerifEcurie(Pion jeu[], int joueurDuTour){
  int cpt =0;
  for(int i=0; i<16;i++){
    if(jeu[i].couleurPion == joueurDuTour && jeu[i].plateau==ECURIE){// Si le pion testé est de la même couleur que le joueur et se trouve dans l'écurie
      cpt++;
    }
  }
  if(cpt==4){
    //printf("Tous les pions sont dans l'écurie\n");
    return(1);
  }else{
    return(0);
  }
}

int ChoixPion(Pion jeu[],int joueurDuTour){
  int choix;
  do{
    printf("Quel pion souhaitez vous jouer ?\n0. %d\n1. %d\n2. %d\n3. %d\n",
    ((joueurDuTour*4)%16),((joueurDuTour*4)%16)+1,((joueurDuTour*4)%16)+2,((joueurDuTour*4)%16)+3);
    scanf("%d", &choix);
  }while(choix<0 ||choix >3);
  printf("Vous avez choisi le pion %d\n",((joueurDuTour*4)%16)+choix);


  return(((joueurDuTour*4)%16)+choix);
}

int JoueurSuivant(int whitelist[],int joueurDuTour){
  do{
    joueurDuTour= (joueurDuTour+1)%4;
  }while(TestPresence(whitelist,4,joueurDuTour)==-1);
  return(joueurDuTour);

}
