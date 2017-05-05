APPLI = colorflood

CSRC = coul-fct1_2.c victoire.c grille.c fonctions_utiles.c solveur.c SDL.c main.c

CC = gcc

CFLAGS = -Wall -Wextra -g

LFLAGS = -lm -lSDL -lSDL_ttf

COBJ = $(CSRC: .c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $*.c



prog:
	$(CC) -o $(APPLI) main_prog.c coul-fct1_2.c victoire.c grille.c fonctions_utiles.c solveur.c -o prog -lm

clean:
	-rm *.o -f colorflood prog