#include "coul-fct1_2.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "couleur.h"
#include "solveur.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>


<<<<<<< Updated upstream
=======
#ifndef SDL_H
#define SDL_H

>>>>>>> Stashed changes
struct RGB
{
	int r;
	int g;
	int b;
};

<<<<<<< Updated upstream
typedef struct RGB RGB;
=======
typedef struct RGB RGB;

void drawRectangle(SDL_Surface *ecran, int px, int py, int size, RGB couleur);

void fillScreen(SDL_Surface *ecran, RGB couleur);

void display_menu(SDL_Surface *ecran, matrix T, int size, int size_window);

SDL_Surface *initialize_screen(int size_window);

void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima);

SDL_Surface *initialize_screen(int size_window);

void color_box(SDL_Surface *ecran,int size_window);

void initialize_text(SDL_Surface *ecran,char *nbr_coup_texte, TTF_Font *police);










#endif
>>>>>>> Stashed changes
