#include "grille.h"
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




/*
Fonction qui créer un chiffre aléatoire entre a et b
*/
int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;// Pour commencer à "a"
}


/*
Fonction créant la grille du jeu avec des couleur aléatoire
*/
matrix grille(int size)
{
	int a,b,i,test;
	matrix mat1= NULL;
	mat1=(char **)calloc(size, sizeof(char*));
	for (i = 0; i < size; ++i)
	{
		mat1[i]=(char *)calloc(size, sizeof(char));
	}
	srand(time(NULL));
	for (a = 0; a < size; ++a)
    {
        for (b = 0; b < size; ++b)
        {
            test=0;
            test=rand_a_b(1,7);
            
            if(test==1)
            {
            	mat1[a][b]='B'; //Bleu
            }
            if(test==2)
            {
                mat1[a][b]='G'; //Gris
            }
            if(test==3)
            {
            	mat1[a][b]='J'; //Jaune
            }
            if(test==4)
            {
            	mat1[a][b]='M'; //Marron
            }
            if(test==5)
            {
            	mat1[a][b]='R'; //Rouge
            }
            if(test==6)
            {
                mat1[a][b]='V'; //Vert
            }
                     
        }
    }

	return mat1;


}






