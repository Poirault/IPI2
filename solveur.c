
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
#include "coul-fct1_2.h"
#include "fonctions_utiles.h"




void solveur(matrix M, int m, int nbCoup)
{
	int i,j,k,test;
	
	char solution[nbCoup];

	matrix P=NULL;
	P=(char **)calloc(m, sizeof(char*));
	for (i = 0; i < m; ++i)
	{
		P[i]=(char *)calloc(m, sizeof(char));
	}

	for(i=0; i<m; i++) {
		for(j=0; j<m; j++) {
			P[i][j] = M[i][j];
		}
	}

	char c;

	
	matrice T;

	for (j = 0; j < m; ++j) //affiche le jeu avec les nouvelles couleurs
		{
			for (k = 0; k < m; ++k)
			{
				affich_couleur(M,j,k);
			}
		printf("\n");
		}
	printf("\n");

	
 
	int tour=0;	

	while (victoire(M, m, tour, nbCoup)!=0){ //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
		
		if (tour == nbCoup) { // Si la solution n'a pas fonctionné 
			tour = 0;
			printf("On recommence\n");
			M = P;
		}
		test=rand_a_b(1,6);
            
		if(test==1) {
      		c='B'; //Bleu
   		}

    	if(test==2) {
      		c='G'; //Gris
    	}

   		if(test==3) {
       		c='J'; //Jaune
    	}

   		if(test==4) {
       		c='M'; //Marron
    	}

  		if(test==5) {
       		c='R'; //Rouge
    	}

    	if(test==6) {
      		c='V'; //Vert
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

		printf("voici M :\n");

		for (j = 0; j < m; ++j) //affiche le jeu avec les nouvelles couleurs
		{
			for (k = 0; k < m; ++k)
			{
				affich_couleur(M,j,k);
			}
		printf("\n");
		}


		printf("Voici P (la grille de départ\n");

		for (j = 0; j < m; ++j) //affiche le jeu avec les nouvelles couleurs
		{
			for (k = 0; k < m; ++k)
			{
				affich_couleur(P,j,k);
			}
		printf("\n");
		}

		
		sleep(1);

		tour++;
		printf("On est au tour: %d\n", tour);
	
	} 

	printf ("Une solution possible en %d coups est :", tour);
	for (i=0; i<tour; i++) {
		printf("%c, ", solution[i]);
	}
	printf("\n");

}


