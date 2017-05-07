TARGET1 = colorflood
TARGET2 = prog
TARGETS = $(TARGET1) $(TARGET2)

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm -lSDL -lSDL_ttf

all: $(TARGETS)

main_prog.o: coul-fct1_2.h victoire.h grille.h fonctions_utiles.h solveur.h couleur.h main_prog.c 
	$(CC) -c $(CFLAGS) main_prog.c

main.o: coul-fct1_2.h victoire.h grille.h fonctions_utiles.h solveur.h SDL.h main.c 
	$(CC) -c $(CFLAGS) main.c

coul-fct1_2.o: coul-fct1_2.h grille.h coul-fct1_2.c
	$(CC) -c $(CFLAGS) coul-fct1_2.c

victoire.o: victoire.h grille.h victoire.c
	$(CC) -c $(CFLAGS) victoire.c

grille.o: grille.h  grille.c
	$(CC) -c $(CFLAGS) grille.c 

fonctions_utiles.o: fonctions_utiles.h grille.h fonctions_utiles.c
	$(CC) -c $(CFLAGS) fonctions_utiles.c 

solveur.o: coul-fct1_2.h victoire.h grille.h fonctions_utiles.h solveur.h solveur.c 
	$(CC) -c $(CFLAGS) solveur.c 

SDL.o: SDL.h coul-fct1_2.h victoire.h grille.h fonctions_utiles.h solveur.h SDL.c
	$(CC) -c $(CFLAGS) SDL.c

$(TARGET1): main.o coul-fct1_2.o victoire.o grille.o solveur.o fonctions_utiles.o SDL.o
		@echo "Building $(TARGET1)"
		$(CC) -o $(TARGET1) main.o coul-fct1_2.o victoire.o grille.o solveur.o fonctions_utiles.o SDL.o $(LDFLAGS) $(CFLAGS)

$(TARGET2): main_prog.o coul-fct1_2.o victoire.o grille.o fonctions_utiles.o solveur.o
		@echo "Building $(TARGE2)"
		$(CC) -o $(TARGET2) main_prog.o coul-fct1_2.o victoire.o grille.o fonctions_utiles.o solveur.o $(CFLAGS) -lm

clean: 
	-rm *.o -f colorflood test console

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) $(LFLAGS)


