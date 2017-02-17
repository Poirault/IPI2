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
typedef int** matrice;

matrix coloreplace(matrix m,coord c,char color);
matrice composante_conn(matrix M,char color);
