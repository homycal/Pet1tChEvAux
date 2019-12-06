all: petitsChevaux

petitsChevaux: Case.o deplacement.o misc.o joueur.o pion.o jeu.o plateau.o ia.o main.o sauvegarde.o
	gcc -o petitsChevaux Case.o deplacement.o misc.o joueur.o pion.o jeu.o plateau.o ia.o sauvegarde.o main.o -Wall -O
	#./petitsChevaux

Case.o: Case.c
		gcc -o Case.o -c Case.c -Wall -O

deplacement.o: deplacement.c
		gcc -o deplacement.o -c deplacement.c -Wall -O

misc.o: misc.c
		gcc -o misc.o -c misc.c -Wall -O

joueur.o: joueur.c
		gcc -o joueur.o -c joueur.c -Wall -O

pion.o: pion.c
		gcc -o pion.o -c pion.c -Wall -O

jeu.o: jeu.c
		gcc -o jeu.o -c jeu.c -Wall -O

plateau.o: plateau.c
		gcc -o plateau.o -c plateau.c -Wall -O

sauvegarde.o: sauvegarde.c
		gcc -o sauvegarde.o -c sauvegarde.c -Wall -O

ia.o: ia.c
		gcc -o ia.o -c ia.c -Wall -O

main.o: main.c
		gcc -o main.o -c main.c -Wall -O

clean:
	rm *.o
