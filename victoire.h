#include "grille.h"
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
* \file victoire.h
*/

/**
* \function victoire 
* \param M(matrice de caractère)
* \param size(taille du jeu)
* \param tour
* \param nb_coup_max(nombre de coup total)
* \return vict(entier permettant de déterminer si le jeu continue ou s'il s'arrête, si on a perdu ou gagné)
* \brief Test si les couleurs sont les mêmes partout dans la grille du jeu
*/
int victoire(matrix M,int size, int tour, int nb_coup_max);

