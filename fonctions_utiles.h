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

/**
 /function nmbre_coup
 /param m(taille du jeu)
 /return entier
 /brief On a été voir sur internet le jeu et on en a conclu que la formule moyenne du nombre de coup 
en fonction de la taille du jeu de 1,7*tailleJeu
*/
int nmbre_coup(int m); 
