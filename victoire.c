#include "victoire.h"
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

/*
Test si les couleurs sont les mêmes partout dans la grille du jeu
*/
int victoire(matrix M,int m, int tour, int nbCoup)
{
	int j,k;
	int vict=0;
	for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				if(M[0][0]!=M[j][k])
				{
					vict=1; //Le jeu continue
				}
			}
		}
	if (tour>nbCoup) //Défaite, arrêt du jeu
		{
			printf("Defeat !\n");
			vict=2;
		}
	if(vict==0)//Victoire, arrêt du jeu
		{
			printf("Victory !\n");
		}
	return(vict);
}

