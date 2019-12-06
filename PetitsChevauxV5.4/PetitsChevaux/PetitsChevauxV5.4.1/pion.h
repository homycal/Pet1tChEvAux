#ifndef PION_H
#define PION_H

#include "case.h"

enum PositionP {ECURIE, EXTERIEUR, CENTRE};
enum CouleurJ {VERT, JAUNE, BLEU, ROUGE};

typedef struct{
  int numPion;
  enum PositionP plateau;
  enum CouleurJ couleurPion;
  int numCase;
  int decompteCase;
  coordonnees *coord;
}Pion;

void InitPion(Pion jeu[], coordonnees ecurie[]);
void AfficherPion(Pion jeu[],const char couleur[][6],const char partiePlateau[][10],int whitelist[]);
void UpdateCoord(Pion jeu[], coordonnees ecurie[], coordonnees plateauExt[], coordonnees centre[]);

#endif
