#include "coul-fct1_2.c"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct coord coord;
typedef struct voisin voisin;

matrix coloreplace(matrix m,coord c,char color);
voisin* voisinage(matrix m,coord c,int n);
matrice composante_conn(matrix M,char color);
