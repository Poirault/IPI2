
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

#include "fct_couleur.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "couleur.h"

int nbcouleur(matrix M, int m);

int composante_conn2(matrix M,char color,int m);

char* createlist(int n);

void test(char* l, int n);

int resolution(matrix M, int m);

int max(int a,int z,int e,int r,int w);

char best(matrix M, int m);

int nope(matrix M, char c, int m);

int testvictoire(matrix M, char* l, int n, int m);

void thelist(matrix M,char* l, int n,int i,int m,char* liste);
