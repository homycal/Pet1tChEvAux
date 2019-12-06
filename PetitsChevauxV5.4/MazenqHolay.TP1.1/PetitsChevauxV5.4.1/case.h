#ifndef CASE_H
#define CASE_H

//On définit une strucure case
typedef struct{
  int x;
  int y;
}coordonnees;

typedef struct{
char contenu[3];
  coordonnees *coordCase;
}Case;

void InitCaseExt(coordonnees plateauExt[]);
void InitEcurie(coordonnees ecurie[]);
void InitCentre(coordonnees centre[]);

#endif
