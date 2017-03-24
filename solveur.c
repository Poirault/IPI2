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

#include "grille.h"
#include "solveur.h"
#include "victoire.h"

void solveur(matrix M, int m, int nbCoup)
{
	int i,j,test;
	
	char solution[nbCoup];

	char c;
	
	matrice T;

	system("clear");

	int tour=0;	

	do { //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
		
		if (tour == nbCoup) { // Si la solution n'a pas fonctionné 
			tour = 0;
			solution[nbCoup] = {0};
		}

		test=rand_a_b(1,6);
            
		if(test==1) {
      		c='b'; //Bleu
   		}

    	if(test==2) {
      		c='g'; //Gris
    	}

   		if(test==3) {
       		c='j'; //Jaune
    	}

   		if(test==4) {
       		c='m'; //Marron
    	}

  		if(test==5) {
       		c='r'; //Rouge
    	}

    	if(test==6) {
      		c='v'; //Vert
   		}

   		solution[tour]=c;

		T=composante_conn(M,c,m); //Matrice d'entier pour savoir quoi "colorier"

		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				if(T[i][j]==1)
				{
					M[i][j]=c; //on a pas besoin de la fct coloreplace
				}
			}
		}

		system("clear");

		tour++;
	
	} while (victoire(M, m, tour, nbCoup));

	printf ("Une solution possible en %d coups est :", tour);
	for (i=0; i<tour; i++) {
		printf("%c ", solution[i]);
	}

}


