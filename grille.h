#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/**
* \file grille.h
* \brief On y trouve la structure matrix(grille du jeu avec des caractères représentant les couleurs)
et deux fonctions permettant de créer un jeu aléatoire
*/


typedef char **matrix;

/**
* \function rand a_b 
* \param a
* \param b
* \return entier
* \brief Fonction qui créer un chiffre aléatoire entre a et b
*/
int rand_a_b(int a, int b);

/**
* \function grille
* \param size(taille du jeu)
* \return matrix(de caractère)
* \brief Fonction créant la grille du jeu avec des couleur aléatoire
*/
matrix grille(int size);

