#ifndef FONCTIONS_UTILES
#define FONCTIONS_UTILES

#include "grille.h"
#include "couleur.h"
#include "fct_couleur.h"
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
 /file victoire.h
 /brief On y mettra toutes les fonctions simples, utiles, pour faciliter la lecture
*/




int nmbre_coup(int size); 



/**
 /function nmbre_coup
 /param m(taille du jeu)
 /return entier
 /brief On a été voir sur internet le jeu et on en a conclu que la formule moyenne du nombre de coup 
en fonction de la taille du jeu de 1,7*tailleJeu
*/
void affich_couleur(matrix M,int j,int k);

void affiche_grille(matrix M, int size);

matrix copie(matrix M, int size);

char commande_clavier();

void free_grille(matrix M, int size);

void texte_victoire(int vict);


#endif