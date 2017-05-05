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


struct RGB
{
	int r;
	int g;
	int b;
};

typedef struct RGB RGB;