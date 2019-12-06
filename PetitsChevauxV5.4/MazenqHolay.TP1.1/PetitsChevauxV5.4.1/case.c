#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "case.h"

/*On initialise chaque case aux coordonnées de la case du plateau*/
void InitCaseExt(coordonnees plateauExt[]){
  for(int i=0; i<56; i++){
    if(i==0){
      plateauExt[i].x=12;
      plateauExt[i].y=14;
    }
    if(i>0 && i<=6){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y - 1;
    }
    if(i>6 && i<=12){
      plateauExt[i].x=plateauExt[i-1].x -2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
    if(i>12 && i<=14){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y-1;
    }
    if(i>14 && i<=20){
      plateauExt[i].x=plateauExt[i-1].x +2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
    if(i>20 && i<=26){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y-1;
    }
    if(i>26 && i<=28){
      plateauExt[i].x=plateauExt[i-1].x+2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
    if(i>28 && i<=34){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y+1;
    }
    if(i>34 && i<=40){
      plateauExt[i].x=plateauExt[i-1].x+2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
    if(i>40 && i<=42){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y+1;
    }
    if(i>42 && i<=48){
      plateauExt[i].x=plateauExt[i-1].x-2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
    if(i>48 && i<=54){
      plateauExt[i].x=plateauExt[i-1].x;
      plateauExt[i].y=plateauExt[i-1].y+1;
    }
    if(i==55){
      plateauExt[i].x=plateauExt[i-1].x-2;
      plateauExt[i].y=plateauExt[i-1].y;
    }
  }
}

/*On initialise chaque case aux coordonnées d'une case écurie*/
void InitEcurie(coordonnees ecurie[]){
/*Vert*/
  ecurie[0].x=1;
  ecurie[0].y=13;
  ecurie[1].x=3;
  ecurie[1].y=13;
  ecurie[2].x=1;
  ecurie[2].y=14;
  ecurie[3].x=3;
  ecurie[3].y=14;
/*Jaune*/
  ecurie[4].x=1;
  ecurie[4].y=0;
  ecurie[5].x=3;
  ecurie[5].y=0;
  ecurie[6].x=1;
  ecurie[6].y=1;
  ecurie[7].x=3;
  ecurie[7].y=1;
/*Bleu*/
  ecurie[8].x=23;
  ecurie[8].y=0;
  ecurie[9].x=26;
  ecurie[9].y=0;
  ecurie[10].x=23;
  ecurie[10].y=1;
  ecurie[11].x=26;
  ecurie[11].y=1;
/*Rouge*/
  ecurie[12].x=23;
  ecurie[12].y=13;
  ecurie[13].x=26;
  ecurie[13].y=13;
  ecurie[14].x=23;
  ecurie[14].y=14;
  ecurie[15].x=26;
  ecurie[15].y=14;

}

/*On devra dire la valeur de la case %6 +1 pour la valeur et i/4 pour la Couleur*/
/*Fonction qui sert à donner des coorodonées aux cases du CENTRE*/
void InitCentre(coordonnees centre[]){
  for(int i=0; i<24; i++){
    if(i>=0 && i<=5){
      centre[i].x=14;
      centre[i].y=13-i;
    }
    if(i>5 &&i <=11){
      centre[i].x=2+(i%6*2);
      centre[i].y=7;
    }
    if(i>11 && i<=17){
      centre[i].x=14;
      centre[i].y=1+(i%6);
    }
    if(i>17 && i<=23){
      centre[i].x=27-(i%6)*2;
      centre[i].y=7;
    }
  }
}
