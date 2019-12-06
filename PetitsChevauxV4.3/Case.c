#include "main.h"
// case 1(413,895)
//case2(413, 895-60)


//On initialise chaque case aux coordonnees de la case du plateau
void InitCaseExt(Case plateauExt[]){
  for(int i=0; i<56; i++){
    if(i==0){
      plateauExt[i].coordonnees.x=413;
      plateauExt[i].coordonnees.y=895;
    }
    if(i>0 && i<=6){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y - 60;
    }
    if(i>6 && i<=12){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x -61;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y;
    }
    if(i>12 && i<=14){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x+1;//+1 juste pour recentrer
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y-61;
    }
    if(i>14 && i<=20){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x +61;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y;
    }
    if(i>20 && i<=26){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y-61;
    }
    if(i>26 && i<=28){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x+59;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y-1;//-1 pour recentrer
    }
    if(i>28 && i<=34){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y+61;
    }
    if(i>34 && i<=40){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x+60;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y;
    }
    if(i>40 && i<=42){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x+1;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y+61;
    }
    if(i>42 && i<=48){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x-60;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y;
    }
    if(i>48 && i<=54){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y+60;
    }
    if(i==55){
      plateauExt[i].coordonnees.x=plateauExt[i-1].coordonnees.x-61;
      plateauExt[i].coordonnees.y=plateauExt[i-1].coordonnees.y+1;
    }
    //plateauExt[i].plateau=EXTERIEUR;
  }
}

//On initialise chaque case aux coordonnées d'une case écurie
void InitEcurie(Case ecurie[]){
//Vert
  ecurie[0].coordonnees.x=200;
  ecurie[0].coordonnees.y=750;
  ecurie[1].coordonnees.x=250;
  ecurie[1].coordonnees.y=750;
  ecurie[2].coordonnees.x=200;
  ecurie[2].coordonnees.y=800;
  ecurie[3].coordonnees.x=250;
  ecurie[3].coordonnees.y=800;
//Jaune
  ecurie[4].coordonnees.x=200;
  ecurie[4].coordonnees.y=250;
  ecurie[5].coordonnees.x=250;
  ecurie[5].coordonnees.y=250;
  ecurie[6].coordonnees.x=200;
  ecurie[6].coordonnees.y=300;
  ecurie[7].coordonnees.x=250;
  ecurie[7].coordonnees.y=300;
//Bleu
  ecurie[8].coordonnees.x=750;
  ecurie[8].coordonnees.y=250;
  ecurie[9].coordonnees.x=800;
  ecurie[9].coordonnees.y=250;
  ecurie[10].coordonnees.x=750;
  ecurie[10].coordonnees.y=300;
  ecurie[11].coordonnees.x=800;
  ecurie[11].coordonnees.y=300;
//Rouge
  ecurie[12].coordonnees.x=750;
  ecurie[12].coordonnees.y=750;
  ecurie[13].coordonnees.x=800;
  ecurie[13].coordonnees.y=750;
  ecurie[14].coordonnees.x=750;
  ecurie[14].coordonnees.y=800;
  ecurie[15].coordonnees.x=800;
  ecurie[15].coordonnees.y=800;

}

//On devra dire la valeur de la case %6 +1 pour la valeur et i/4 pour la Couleur
//Fonctionn qui sert à donner des coorodonées aux cases du CENTRE
void InitCentre(Case centre[]){
  for(int i=0; i<24; i++){
    if(i>=0 && i<=5){
      centre[i].coordonnees.x=474;
      centre[i].coordonnees.y=835-i*60;
    }
    if(i>5 &&i <=11){
      centre[i].coordonnees.x=112+(i%6)*60;
      centre[i].coordonnees.y=474;
    }
    if(i>11 && i<=17){
      centre[i].coordonnees.x=474;
      centre[i].coordonnees.y=112+(i%6)*60;
    }
    if(i>17 && i<=23){
      centre[i].coordonnees.x=835-(i%6)*60;
      centre[i].coordonnees.y=474;
    }
  }
}
