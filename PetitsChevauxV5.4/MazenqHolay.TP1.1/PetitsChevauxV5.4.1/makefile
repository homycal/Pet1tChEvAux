all: petitsChevaux

petitsChevaux: case.o deplacement.o misc.o joueur.o pion.o jeu.o plateau.o ia.o main.o sauvegarde.o
	gcc -o petitsChevaux case.o deplacement.o misc.o joueur.o pion.o jeu.o plateau.o ia.o sauvegarde.o main.o -Wall -O
	#./petitsChevaux

case.o: case.c case.h
		gcc -o case.o -c case.c -Wall -O

deplacement.o: deplacement.c deplacement.h
		gcc -o deplacement.o -c deplacement.c -Wall -O

misc.o: misc.c misc.h
		gcc -o misc.o -c misc.c -Wall -O

joueur.o: joueur.c joueur.h
		gcc -o joueur.o -c joueur.c -Wall -O

pion.o: pion.c pion.h
		gcc -o pion.o -c pion.c -Wall -O

jeu.o: jeu.c jeu.h
		gcc -o jeu.o -c jeu.c -Wall -O

plateau.o: plateau.c plateau.c
		gcc -o plateau.o -c plateau.c -Wall -O

sauvegarde.o: sauvegarde.c sauvegarde.h
		gcc -o sauvegarde.o -c sauvegarde.c -Wall -O

ia.o: ia.c ia.h
		gcc -o ia.o -c ia.c -Wall -O

main.o: main.c main.h
		gcc -o main.o -c main.c -Wall -O

clean:
	rm *.o
