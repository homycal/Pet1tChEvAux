#include "main.h"

//Fonction choisissant le premier joueur
int PremierJoueur(int nombreJoueur){
  return (rand()%(3-0+1)+0);
}
  //Fonction lançant un dé de 6
  int LancerdeDes(){
    return(rand()%(6-1+1)+1);
  }

int ConditionFin(Pion jeu[],int joueurDuTour){
  int cpt=0;
  for(int i=0; i<16; i++){
    if(jeu[i].couleurPion== joueurDuTour && jeu[i].plateau == CENTRE && jeu[i].numCase>=3 && jeu[i].numCase<=6){
      cpt++;
    }
  }
  if(cpt==4){
    return(1);
  }else{
    return(0);
  }
}

int Mouvements(int joueurDuTour, int scoreDes, Pion jeu[], int *action, int *pionDuTour, int whitelist[]){
  int valide[4]={-1,-1,-1,-1}, jouable=0, j=0; // jouable sert à savoir si on peut jouer
  TestDeplacement(jeu, joueurDuTour, scoreDes, valide);
  while(j<4){
    if(valide[j]!=-1){
      jouable =1;
      break;
    }
    j++;
  }
  if(jouable){
    do{
      printf("Quel pion souhaitez vous jouer ?\n");
      for(int i=0; i<4; i++){
        if(valide[i]!=-1){
          printf("Pion %d\n", valide[i]);
        }
      }
      *pionDuTour = LireEntier(whitelist, jeu ,1, joueurDuTour, scoreDes);

  }while(*pionDuTour!=valide[0] && *pionDuTour!=valide[1] && *pionDuTour!=valide[2] && *pionDuTour!=valide[3]);
  printf("Vous avez choisi le pion %d\n", *pionDuTour);
  if(jeu[*pionDuTour].plateau==ECURIE){
    *action = 1; // sortie d'écurie
  }else if(jeu[*pionDuTour].plateau==EXTERIEUR && jeu[*pionDuTour].decompteCase == 0){
    *action = 3; // entrée CENTRE
  }else if(jeu[*pionDuTour].plateau==CENTRE && jeu[*pionDuTour].decompteCase == 0){
    *action = 4; // Déplacement CENTRE
  }else{
    *action = 2;// Déplacement EXTERIEUR
  }
}else{
  printf("Vous ne pouvez jouer aucun pion\n");
  sleep(2); // Pour avoir le temps d'apréhender
  *action = 0;
}

return(*action);
}

int DeplacementPion(int joueurDuTour, int scoreDes, int action, int pionDuTour,const char couleur[][6], Pion jeu[]){//Fonction qui se charge de déplacer le pion
  switch(action){
    case 1:
    SortieEcurie(jeu, joueurDuTour, pionDuTour, couleur);
    //UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

      break;

    case 2 : // déplacement basique du pion
    DeplacementPlateau(jeu, pionDuTour, scoreDes, couleur, joueurDuTour);
    //UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;

    case 3: // Entrée dans les colonnes intérieures
    EntreeCentre(jeu, pionDuTour, scoreDes, joueurDuTour);
    //UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;

    case 4: // Déplacement dans les colonnes intérieures
    DeplacementCentre(jeu, pionDuTour, scoreDes, joueurDuTour);
    //UpdateEcran(stockImages,ecran, positionBackground, background, pionDuTour, jeu);

    break;
  }

  return(0);
}

void TestDeplacement(Pion jeu[], int joueurDuTour, int scoreDes, int valide[]){
  for(int i=0; i<4; i++){
    int pionTest=i+4*joueurDuTour;
    int caseTest, piedCol=((joueurDuTour*14)-1)%56;
    if(jeu[pionTest].numCase==piedCol){
      caseTest=0; // Si le pion se trouve au pied de la colonne centrale, on test à partir de 0 CaseLibre()
    }else{
      caseTest=jeu[pionTest].numCase;
    }

    int block = DetectionBlocage(jeu, pionTest, scoreDes);
    int block2 = CaseLibre(jeu, scoreDes, pionTest, caseTest); //WARNING fonctionnement à check
    //Si le pion est dans l'écurie
    if(VerifEcurie(jeu, pionTest) && scoreDes != 6){
      printf("Le pion %d est dans l'écurie et ne peut pas être joué\n", pionTest);
    }
    //Si le pion est bloqué par un autre pion à l'extérieur
    else if(block!=-1){
      printf("le pion %d est bloqué par le pion %d\n", pionTest, block);
    }
    //Si le pion est bloqué car il dépasse ça case du CENTRE
    else if(jeu[pionTest].plateau==EXTERIEUR && jeu[pionTest].decompteCase-scoreDes<-1){
      printf("Le pion %d dépasserai sa case d'entrée au centre\n", pionTest);
    }
    //Si le pion est bloqué car il ne peut pas avancer DANS le CENTRE
    else if((jeu[pionTest].plateau == CENTRE || jeu[pionTest].numCase == piedCol) && scoreDes != caseTest +1){
      printf("Le pion %d ne peut pas avancer avec ce score !\n", pionTest);
    }
    else if(block2!=-1){
      printf("Le pion %d est bloqué par le pion %d\n", pionTest, block2);
    }
    else if(jeu[pionTest].plateau == CENTRE && jeu[pionTest].numCase==6){
      printf("Le pion %d ne peut plus avancer\n", pionTest);
    }
    else{
      //printf("Le pion %d peut être joué !\n", pionTest);
      valide[i]=pionTest;

    }
  }

}
