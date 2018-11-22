void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour){
  jeu[pionDuTour].plateau=1;
  jeu[pionDuTour].numCase=joueurDuTour*14;
}

void DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes){
  jeu[pionDuTour].numCase = (scoreDes +jeu[pionDuTour].numCase)%56;
}
