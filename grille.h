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
 /file grille.h
*/


typedef char **matrix;

/**
 /function rand a_b 
 /param a
 /param b
 /return entier
 /brief Fonction qui créer un chiffre aléatoire entre a et b
*/

int rand_a_b(int a, int b);
matrix grille(int m);

