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
	int i,j,k,m,g;
	
	char solution[nbCoup];

	char c;
	
	matrice T;

	system("clear");

	int tour=0;	

	do { //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
		
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
		
	} while (victoire(M, m, tour, nbCoup));

	
	

	printf("Le nombre de coup minium est : %d\n", NbCoupMin);

}



/*
test=rand_a_b(1,6);
            
	if(test==1) {
      	mat1[a][b]='B'; //Bleu
    }

    if(test==2) {
       	mat1[a][b]='G'; //Gris
    }

   	if(test==3) {
       	mat1[a][b]='J'; //Jaune
    }

   	if(test==4) {
        mat1[a][b]='M'; //Marron
    }

   	if(test==5) {
        mat1[a][b]='R'; //Rouge
    }

    if(test==6) {
        mat1[a][b]='V'; //Vert
   	}
*/