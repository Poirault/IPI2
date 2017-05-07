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

#include "coul-fct1_2.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "couleur.h"
#include "solveur.h"



int main()
{
	int j,k,m,f,g, nbCoup, tour = 0;
	f=1;

	char o,c;

	matrix M;


	matrice T;




	printf("Donnez la taille du jeu\n");
	scanf("%d", &m);

	M=grille(m);

	for (j = 0; j < m; ++j) //affiche le jeu avec les nouvelles couleurs
	{
		for (k = 0; k < m; ++k)
		{
			
			affich_couleur(M,j,k);
		}
	printf("\n");
	}

	matrix P=NULL;
	P=(char **)calloc(m, sizeof(char*));
	for (j = 0; j < m; ++j)
	{
		P[j]=(char *)calloc(m, sizeof(char));
	}

	for(j=0; j<m; j++) 
	{
		for(k=0; k<m; k++) 
		{
			P[j][k] = M[j][k];
		}
	}

	nbCoup = nmbre_coup(m);


	solveur(P, m, nbCoup);




	printf("Number tour : %d/%d \n", tour, nbCoup);

	while((f!=0) && (f!=2)) { //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
		g=1;
		printf("Choisissez une couleur\n");
		while(g!=0){
			o=getche();
			if(o=='b'){
				c='B';
				g=0;
			}
			if(o=='g'){
				c='G';
				g=0;
			}
			if(o=='j'){
				c='J';
				g=0;
			}
			if(o=='m'){
				c='M';
				g=0;
			}
			if(o=='r'){
				c='R';
				g=0;
			}
			if(o=='v'){
				c='V';
				g=0;
			}
		}
		
		T=composante_conn(M,c,m); //Matrice d'entier pour savoir quoi "colorier"

		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				if(T[j][k]==1 || T[j][k]==2)
				{
					M[j][k]=c; //on a pas besoin de la fct coloreplace
				}
			}
		}

		for (j = 0; j < m; ++j) //affiche le jeu avec les nouvelles couleurs
		{
			for (k = 0; k < m; ++k)
			{
				
				affich_couleur(M,j,k);
			}
		printf("\n");
		}

		tour++;
		if (tour<=nbCoup) {
			printf("Number tour : %d/%d \n", tour, nbCoup);
		}
		
		f=victoire(M,m,tour,nbCoup);

		if (f==0)
		{
			printf("Victory !");
		}
		else if (f==2)
		{
			printf("Defeat !");
		}
	}

	for (j = 0; j < m; ++j) //Libération d'espace mémoire
	{
			
		free(M[j]);
		free(T[j]);	
	}
	free(M);
	free(T);

	return 0;

}
