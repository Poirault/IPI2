
prog: main2.o coul-fct1_2.o victoire.o grille.o fonctions_utiles.o
	gcc -Wall -Wextra main2.o coul-fct1_2.o victoire.o grille.o fonctions_utiles.o -o prog -lm
main2.o: main2.c grille.h coul-fct1_2.h victoire.h fonctions_utiles.h
	gcc -Wall -Wextra -c main2.c -lm
coul-fct1_2.o: coul-fct1_2.c coul-fct1_2.h grille.h
	gcc -Wall -Wextra -c coul-fct1_2.c -lm
grille.o: grille.c grille.h
	gcc -Wall -Wextra -c grille.c
victoire.o: victoire.c victoire.h grille.h
	gcc -Wall -Wextra -c victoire.c -lm
fonctions_utiles.o: fonctions_utiles.c fonctions_utiles.h
	gcc -Wall -Wextra -c fonctions_utiles.c -lm



