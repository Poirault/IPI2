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
typedef struct coord coord;
typedef int** matrice;
int getche(void);
matrix coloreplace(matrix M,coord c,char color,int m);
matrice composante_conn(matrix M,char color,int m);
