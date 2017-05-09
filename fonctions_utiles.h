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
 * \file victoire.h
 * \brief On y mettra toutes les fonctions simples, utiles, pour faciliter la lecture
*/



/**
* \function nmbre_coup
* \param m(taille du jeu)
* \return entier
* \brief On a été voir sur internet le jeu et on en a conclu que la formule moyenne du nombre de coup 
en fonction de la taille du jeu de 1,7*tailleJeu
*/
int nmbre_coup(int size); 


/**
* \function affich_couleur
* \param M (matrix étant le jeu)
* \param j (position x du jeu)
* \param k (position j du jeu)
* \brief Permet d'afficher les lettres en couleur dans le terminal
*/
void affich_couleur(matrix M,int j,int k);


/**
* \function affiche_grille
* \param M (matrix étant le jeu)
* \param size (taille du jeu)
* \brief Permet d'afficher le jeu en couleur dans le terminal
*/
void affiche_grille(matrix M, int size);


/**
* \function copie
* \param M (matrix étant le jeu)
* \param size (taille du jeu)
* \brief Permet de copier la matrix M afin de pouvoir la sauvegarder
*/
matrix copie(matrix M, int size);


/**
* \function commande_clavier
* \param M (matrix étant le jeu)
* \param size (taille du jeu)
* \brief Permet d'avoir une saisie direct des touches pour jouer via le terminal
*/
char commande_clavier();


/**
* \function free_grille
* \param M (matrix étant le jeu)
* \param size (taille du jeu)
* \brief libération d'espace mémoire des matrix
*/
void free_grille(matrix M, int size);


/**
* \function free_grille
* \param M (matrix étant le jeu)
* \param size (taille du jeu)
* \brief libération d'espace mémoire des matrice
*/
void free_matrice(matrice M, int size);


/**
* \function texte_victoire
* \param vict (entier permettant de savoir si on a gagné ou perdu)
* \brief Ecrit "victory" ou "defeat" en fonction du paramètre
*/
void texte_victoire(int vict);


#endif