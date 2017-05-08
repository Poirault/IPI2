#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "grille.h"
#include "victoire.h"
#include "fct_couleur.h"

/**
/file solveur.h
/brief Contient la fonction de solveur et toutes celles qui aident à sa faisabilité
*/
void voisin_random(matrix M, int size, char couleur);

/**
/function solveur
/return Permet de retourner une solution trouvée.
/brief Le temps peut-être un peu long pour une taille m elevée.
*/
int solveur(matrix M, int size, int nb_coup_max);

int majoration(matrix M, int size, int nb_coup_max);