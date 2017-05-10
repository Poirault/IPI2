#include "fct_couleur.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "solveur.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>


#ifndef SDL_H
#define SDL_H

/**
* \file SDL.h
* \brief On y trouve la structure RGB (pour faire toutes les couleurs à partir du rouge, vert et bleu)
et toutes les fonctions permettant au SDL de fonctionner et agréable graphyquement
*/


struct RGB
{
	int r;
	int g;
	int b;
};


typedef struct RGB RGB;


/**
* \function drawRectangle
* \param *ecran
* \param px
* \param py
* \param size
* \param couleur
* \brief Créer un rectangle à la position (x;y)
*/
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, RGB couleur);


/**
* \function fillScreen
* \param *ecran
* \param couleur
* \brief //TODO
*/
void fillScreen(SDL_Surface *ecran, RGB couleur);


/**
* \function menu
* \param *police_moyenne
* \param *police_grande
* \param size
* \param nbr_coup_max
* \brief //TODO
*/
SDL_Surface *menu(TTF_Font *police_moyenne, TTF_Font *police_grande, int *size, int nbr_coups_max);


/**
* \function drawTexture
* \param *ecran
* \param px
* \param py
* \param *ima
* \brief //TODO
*/
void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima);


/**
* \function initialize_scree
* \param size_xindow
* \brief //TODO
*/
SDL_Surface *initialize_screen(int size_window);


/**
* \function initialize_text
* \param *ecran
* \param *nbr_coup_texte
* \param *police
* \brief Créer un rectangle à la position (x;y)
*/
void initialize_text(SDL_Surface *ecran,char *nbr_coup_texte, TTF_Font *police);


/**
* \function color_box
* \param *ecran
* \param size_window
* \brief //TODO
*/
void color_box(SDL_Surface *ecran,int size_window);


/**
* \function display_SDL
* \param *ecran
* \param T
* \param size
* \param size_window
* \param border_flag
* \brief //TODO
*/
void display_SDL(SDL_Surface *ecran, matrix T, int size, int size_window, bool border_flag);


/**
* \function loop_game
* \param *ecran
* \param T
* \param size
* \param nbr_coup_max
* \param *nbr_coup_texte
* \param *police
* \param size_window
* \param border_flag
* \param *bouton
* \param *out
* \brief Créer un rectangle à la position (x;y)
*/
int loop_game(SDL_Surface *ecran, matrix T, int size, int nbr_coups_max, char *nbr_coup_texte, TTF_Font *police,int size_window, bool border_flag, int* bouton, int* out);


/**
* \function end_game
* \param *ecran
* \param T
* \param size
* \param nbr_coup
* \param nbr_coup_max
* \param *police
* \brief //TODO
*/
void end_game(SDL_Surface *ecran, matrix T, int size, int nbr_coup, int nbr_coups_max, TTF_Font *police);


/**
* \function initialize_text
* \param *ecran
* \param *nbr_coup_texte
* \param *police
* \brief //TODO
*/
void initialize_text(SDL_Surface *ecran,char *nbr_coup_texte, TTF_Font *police);


#endif

