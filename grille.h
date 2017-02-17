#include "grille.c"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>


typedef char **matrix;

int rand_a_b(int a, int b);
matrix mat1(int m);
