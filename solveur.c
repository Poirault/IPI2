
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
#include "fct_couleur.h"
#include "fonctions_utiles.h"

void voisin_random(matrix M, int size, char couleur) {
	int i, j;

	matrice T;

	matrix P=NULL;
	P=(char **)calloc(size, sizeof(char*));
	for (i = 0; i < size; ++i)
	{
		P[i]=(char *)calloc(size, sizeof(char));
	}

	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			P[i][j] = M[i][j];
		}
	}

	T=composante_conn(M,couleur,size); //Matrice d'entier pour savoir quoi "colorier"

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if((T[i][j]==1) || (T[i][j]==2))
			{
				M[i][j]=couleur; 
			}
		}
	}

}


int solveur(matrix M, int size, int nb_coup_max)
{
	int i,j,/*k,*/ test, s;

	char couleur;
	
	char solution[nb_coup_max];

	matrice T;

	matrix P=NULL;
	P=(char **)calloc(size, sizeof(char*));
	for (i = 0; i < size; ++i)
	{
		P[i]=(char *)calloc(size, sizeof(char));
	}

	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			P[i][j] = M[i][j];
		}
	}


	
 
	int tour=0;	

	while (victoire(M, size, tour, nb_coup_max)!=0){ //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
		
		s = 0;

		if (tour == nb_coup_max) { // Si la solution n'a pas fonctionné 
			tour = 0;
			//printf("On recommence\n");
			matrix T=NULL;
			T=(char **)calloc(size, sizeof(char*));
			for (i = 0; i < size; ++i)
			{
				T[i]=(char *)calloc(size, sizeof(char));
			}

			for(i=0; i<size; i++) {
				for(j=0; j<size; j++) {
					T[i][j] = P[i][j];
				}
			}
			M = T;
		}

		test=rand_a_b(1,7);
            
		if(test==1) {
      		couleur='B'; //Bleu
   		}

    	if(test==2) {
      		couleur='G'; //Gris
    	}

   		if(test==3) {
       		couleur='J'; //Jaune
    	}

   		if(test==4) {
       		couleur='M'; //Marron
    	}

  		if(test==5) {
       		couleur='R'; //Rouge
    	}

    	if(test==6) {
      		couleur='V'; //Vert
   		}

   		T=composante_conn(M,couleur,size);

   		for (i=0; i<size; i++) {
   			for (j=0; j<size; j++) {
   				if (T[i][j]==2) {
   					s++;
   				}
   			}
   		}

   		if (s!=0) {

	   			voisin_random(M, size, couleur);

				solution[tour]=couleur;
				/*
				printf("voici M :\n");

				for (j = 0; j < size; ++j) //affiche le jeu avec les nouvelles couleurs
				{
					for (k = 0; k < size; ++k)
					{
						affich_couleur(M,j,k);
					}
				printf("\n");
				}
				*/

				tour++;
				//printf("On est au tour: %d\n", tour);

   		}
   		/*
   		else {
   			printf("On est toujour au tour: %d\n", tour);
   		}
   		*/

	
	} 

	printf ("Une solution possible en %d coups est :", tour);
	for (i=0; i<tour; i++) {
		printf("%c, ", solution[i]);
	}
	printf("\nMaintenant à vous de jouer ! \n");

	return tour;
}


int majoration(matrix M, int size, int nb_coup_max) {
	int min = nb_coup_max, i, test;

	for (i=0; i<1000; i++) {
		test = solveur (M, size, nb_coup_max);
		if (test < min) {
			min = test;
		}
	}
	return min;
}


