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
int victoire(matrix M,int size, int tour, int nb_coup_max)
{

	int j,k;
	int vict=0;
	for (j = 0; j < size; ++j)
	{
		for (k = 0; k < size; ++k)
		{
			if(M[0][0]!=M[j][k])
			{
				vict=1; //Le jeu continue
			}
		}
	}
	if (vict==1 && tour >= nb_coup_max) //Défaite, arrêt du jeu
	{
		vict=2;
	}

// vict == 0 => victoire

	return(vict);
}
