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
* \param *police_texte
* \param *police_colorflood
* \param size
* \param nb_coup_max
* \brief //TODO
*/	
SDL_Surface *regle(TTF_Font *police_texte,TTF_Font *police_colorflood,TTF_Font *police_regle, SDL_Surface *ecran, int *size);


/**
* \function menu
* \param *police_texte
* \param *police_colorflood
* \param size
* \param nb_coup_max
* \brief //TODO
*/
SDL_Surface *menu(TTF_Font *police_texte, TTF_Font *police_colorflood, TTF_Font *police_regle, int *size);


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
SDL_Surface *initialize_screen(int taille_fenetre);


/**
* \function texte
* \param *ecran
* \param *nbr_coup_texte
* \param *police
* \brief Créer un rectangle à la position (x;y)
*/
void texte(SDL_Surface *ecran, TTF_Font *police, TTF_Font *police_coup);


/**
* \function couleur_a_choisir
* \param *ecran
* \param taille_fenetre
* \brief //TODO
*/
void couleur_a_choisir(SDL_Surface *ecran,int taille_fenetre);


/**
* \function display_SDL
* \param *ecran
* \param T
* \param size
* \param taille_fenetre
* \param separation
* \brief //TODO
*/
void display_SDL(SDL_Surface *ecran, matrix T, int size, int taille_fenetre, bool separation);


/**
* \function boucle_jeu
* \param *ecran
* \param T
* \param size
* \param nbr_coup_max
* \param *nbr_coup_texte
* \param *police
* \param taille_fenetre
* \param separation
* \param *bouton
* \param *out
* \brief Créer un rectangle à la position (x;y)
*/
int boucle_jeu(SDL_Surface *ecran, matrix T, int size, int nb_coup_max, char *nbr_coup_texte, TTF_Font *police,int taille_fenetre, bool separation, int* bouton, int* out);


/**
* \function fin_jeu
* \param *ecran
* \param T
* \param size
* \param nbr_coup
* \param nbr_coup_max
* \param *police
* \brief //TODO
*/
void fin_jeu(SDL_Surface *ecran, matrix T, int size, int nbr_coup, int nb_coup_max, TTF_Font *police);


/**
* \function texte
* \param *ecran
* \param *nbr_coup_texte
* \param *police
* \brief //TODO
*/


#endif

