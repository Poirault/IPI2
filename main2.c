#include "coul-fct1_2.h"
#include "grille.h"
#include "victoire.h"
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

int main()
{
	int j,k,m,f,g;
	f=1;
	char o,c;
	matrix M;
	matrice T;
	printf("Donnez la taille du jeu\n");
	scanf("%d", &m);
	M=grille(m);
	system("clear");
	for (j = 0; j < m; ++j)
	{
		for (k = 0; k < m; ++k)
		{
			
			printf("%10c", M[j][k]);
		}
	printf("\n");
	}
	while(f!=0){
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

		T=composante_conn(M,c,m);
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				
				printf("%10d", T[j][k]);
			}
		printf("\n");
		}
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				if(T[j][k]==1)
				{
					M[j][k]=c;      //on a pas besoin de la fct coloreplace
				}
			}
		}
		system("clear");
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				
				printf("%10c", M[j][k]);
			}
		printf("\n");
		}
		f=victoire(M,m);
	}

	for (j = 0; j < m; ++j)
		{
			
			free(M[j]);
			free(T[j]);
		
		}
		free(M);
		free(T);
	

	return 0;

}
