
prog: main2.o coul-fct1_2.o victoire.o grille.o
	gcc -Wall -Wextra main2.o coul-fct1_2.o victoire.o grille.o -o prog
main2.o: main2.c grille.h coul-fct1_2.h victoire.h
	gcc -Wall -Wextra -c main2.c
coul-fct1_2.o: coul-fct1_2.c coul-fct1_2.h grille.h
	gcc -Wall -Wextra -c coul-fct1_2.c -lm
grille.o: grille.c grille.h
	gcc -Wall -Wextra -c grille.c
victoire.o: victoire.c victoire.h grille.h
	gcc -Wall -Wextra -c victoire.c -lm
fonctions_utiles.o: fonctions_utiles.c fonctions_utiles.h grille.h couleur.h
	gcc -Wall -Wextra -c fonctions_utiles.c -lm
solveur.o: solveur.c solveur.h
	gcc -Wall -Wextra -c solveur.c -lm


