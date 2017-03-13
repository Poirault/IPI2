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

#include "solveur.h"

void solveur(matrix M, int m)
{
	int j,k,m,g, nbCoup, NbCoupMin=1000;
	

	char c;

	matrix M;
	
	matrice T;

	M=grille(m);

	nbCoup = nmbre_coup(m);

	system("clear");

	while() { //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
	int tour=0;	
		
		T=composante_conn(M,c,m); //Matrice d'entier pour savoir quoi "colorier"

		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				if(T[j][k]==1)
				{
					M[j][k]=c; //on a pas besoin de la fct coloreplace
				}
			}
		}

		system("clear");


		tour++;
		

		/* Fonction solveur */
		if (victoire(M,m,tour,nbCoup)==1)
		{
			NbCoupMin=tour;
			
		}
		
	}

	
	

	printf("Le nombre de coup minium est : %d\n", NbCoupMin);

}
