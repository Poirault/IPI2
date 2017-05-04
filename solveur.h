#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "grille.h"
#include "victoire.h"
#include "coul-fct1_2.h"

/**
/file solveur.h
/brief Contient la fonction de solveur et toutes celles qui aident à sa faisabilité
*/
void voisin_random(matrix M, int m, char c);

/**
/function solveur
/return Permet de retourner une solution trouvée.
/brief Le temps peut-être un peu long pour une taille m elevée.
*/
int solveur(matrix M, int m, int nbCoup);

int majoration(matrix M, int m, int nbCoup);