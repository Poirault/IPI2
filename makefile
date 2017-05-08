TARGET1 = colorflood
TARGET2 = prog
TARGETS = $(TARGET1) $(TARGET2)

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm -lSDL -lSDL_ttf

all: $(TARGETS)

main_prog.o: fct_couleur.h victoire.h grille.h fonctions_utiles.h solveur.h couleur.h main_prog.c 
	$(CC) -c $(CFLAGS) main_prog.c

main.o: fct_couleur.h victoire.h grille.h fonctions_utiles.h solveur.h SDL.h main.c 
	$(CC) -c $(CFLAGS) main.c

fct_couleur.o: fct_couleur.h grille.h fct_couleur.c
	$(CC) -c $(CFLAGS) fct_couleur.c

victoire.o: victoire.h grille.h victoire.c
	$(CC) -c $(CFLAGS) victoire.c

grille.o: grille.h  grille.c
	$(CC) -c $(CFLAGS) grille.c 

fonctions_utiles.o: fonctions_utiles.h grille.h couleur.h fct_couleur.h fonctions_utiles.c
	$(CC) -c $(CFLAGS) fonctions_utiles.c 

solveur.o: fct_couleur.h victoire.h grille.h fonctions_utiles.h solveur.h solveur.c 
	$(CC) -c $(CFLAGS) solveur.c 

SDL.o: SDL.h fct_couleur.h victoire.h grille.h fonctions_utiles.h solveur.h SDL.c
	$(CC) -c $(CFLAGS) SDL.c

$(TARGET1): main.o fct_couleur.o victoire.o grille.o solveur.o fonctions_utiles.o SDL.o
		@echo "Building $(TARGET1)"
		$(CC) -o $(TARGET1) main.o fct_couleur.o victoire.o grille.o solveur.o fonctions_utiles.o SDL.o $(LDFLAGS) $(CFLAGS)

$(TARGET2): main_prog.o fct_couleur.o victoire.o grille.o fonctions_utiles.o solveur.o
		@echo "Building $(TARGET2)"
		$(CC) -o $(TARGET2) main_prog.o fct_couleur.o victoire.o grille.o fonctions_utiles.o solveur.o $(CFLAGS) -lm

clean: 
	-rm *.o -f colorflood test console


