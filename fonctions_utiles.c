#include "fonctions_utiles.h"
#include "grille.h"
#include "couleur.h"
#include "fct_couleur.h"
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
On a été voir sur internet le jeu et on en a conclu que la formule moyenne du nombre de coup 
en fonction de la taille du jeu de 1,7*tailleJeu
*/
int nmbre_coup(int size)
{
	int nmbre_coup, partie_entiere;
	nmbre_coup= 1.7*size; //Pondération empirique
	partie_entiere= floor(nmbre_coup)+1;
	return partie_entiere;
}

void affich_couleur(matrix M, int j, int k)
{
	
	if(M[j][k]=='B')
	{
	couleur("34");
	printf("%10c", M[j][k]);
	couleur("0");
	}
	if(M[j][k]=='G')
	{
	couleur("30");
	printf("%10c", M[j][k]);
	couleur("0");
	}
	if(M[j][k]=='J')
	{
	couleur("33");
	printf("%10c", M[j][k]);
	couleur("0");
	}
	if(M[j][k]=='M')
	{
	couleur("35");
	printf("%10c", M[j][k]);
	couleur("0");
	}
	if(M[j][k]=='R')
	{
	couleur("31");
	printf("%10c", M[j][k]);
	couleur("0");
	}
	if(M[j][k]=='V')
	{
	couleur("32");
	printf("%10c", M[j][k]);
	couleur("0");
	}

}


void affiche_grille(matrix M, int size)
{
	int j, k;
	for (j = 0; j < size; ++j) //affiche le jeu avec les nouvelles couleurs
	{
		for (k = 0; k < size; ++k)
		{
			affich_couleur(M,j,k);
		}
	printf("\n");
	}
}

matrix copie(matrix M, int size) 
{
	int j, k;
	matrix P=NULL;
	P=(char **)calloc(size, sizeof(char*));
	for (j = 0; j < size; ++j)
	{
		P[j]=(char *)calloc(size, sizeof(char));
	}

	for(j=0; j<size; j++) 
	{
		for(k=0; k<size; k++) 
		{
			P[j][k] = M[j][k];
		}
	}
	return P;
}

char commande_clavier()
{
	int g=1;
	char o, couleur;
	printf("Choisissez une couleur\n");
	while(g!=0){
		o=getche();
		if(o=='b'){
			couleur='B';
			g=0;
		}
		if(o=='g'){
			couleur='G';
			g=0;
		}
		if(o=='j'){
			couleur='J';
			g=0;
		}
		if(o=='m'){
			couleur='M';
			g=0;
		}
		if(o=='r'){
			couleur='R';
			g=0;
		}
		if(o=='v'){
			couleur='V';
			g=0;
		}
	}
	return couleur;
}

void free_grille(matrix M, int size)
{
	int j;
	for (j = 0; j < size; ++j)
	{		
		free(M[j]);
	}
	free(M);
}

void texte_victoire(int vict)
{
	if (vict==0)
	{
		printf("Victory !");
	}
	else if (vict==2)
	{
		printf("Defeat !");
	}
}