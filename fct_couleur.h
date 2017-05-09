#include "grille.h"
#include "fonctions_utiles.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


/**
* \file coul-fct1_2.h
*/

typedef struct coord coord;
typedef int** matrice;

/**
* \function getche
* \brief Fonction permettant aux joueurs d'interagir avec le jeu 
*/
int getche(void);

/**
* \function colorplace
* \param M(matrice de caractère)
* \param c(coordonnée)
* \param color
* \param size
* \return matrix
* \brief Prend les coordonnées c(x;y) d'une matrice pour changer par la couleur 'color' 
*/
matrix coloreplace(matrix M,coord c,char color,int size);

/**
* \function composante_conn
* \param M(matrice de caractère)
* \param color
* \param size
* \return matrice(d'entier)
* \brief Renvoie une matrice d'entier donnant les cases à colorier (pas du tout optimal)
*/
matrice composante_conn(matrix M,char color,int size);


/**
* \function modif_color
* \param M(matrice de caractère)
* \param color
* \param size
* \brief Permet de modifier le jeu à partir de la fonction composante_conn
*/
void modif_color(matrix M, char color, int size);
