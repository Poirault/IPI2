

main.o: main.c grille.h coul-fct1_2.h
	gcc -Wall -Wextra -c main.c
coul-fct1_2.o: coul-fct1_2.c coul-fct1_2.h
	gcc -Wall -Wextra -c coul-fct1_2.c
grille.o: grille.c grille.h
	gcc -Wall -Wextra -c foo.c
prog: main.o foo.o
	gcc -Wall -Wextra main.o foo.o -o prog
