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

#include "fct_couleur.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "couleur.h"
#include "solveur.h"



int main()
{
	int size, nb_coup_max;
	int vict=1, tour=0;

	char couleur, choix;

	matrix M, P;


	printf("Donnez la taille du jeu\n");
	scanf("%d", &size);

	M=grille(size); //grille aléatoire du jeu
	affiche_grille(M, size); //afiche le jeu sur le terminal avec les couleur

	nb_coup_max = nmbre_coup(size); //formule empirique du jeu pour le nombre de coup max

	printf ("Voulez-vous afficher une solution ?\n Si oui tapez 'o' sinon tapez 'n' puis entrez.\n");
	scanf("%c", &choix);
	scanf("%c", &choix);
	if (choix == 'o')
	{
		P = copie(M, size); //afin de ne pas modifier le jeu initial 
		resolution(P, size);
		affiche_grille(M, size);
		free_grille(P, size);
	}

	printf("Number tour : %d/%d \n", tour, nb_coup_max);

	while((vict!=0) && (vict!=2)) //Tant qu'il n'y a pas de victoire ou que le nombre de tour est inférieure ou égale aux nombres de coups
	{ 
		couleur = commande_clavier();
		
		modif_color(M, couleur, size);

		affiche_grille(M, size);

		tour++;
		if (tour<=nb_coup_max) 
		{
			printf("Number tour : %d/%d \n", tour, nb_coup_max);
		}
		
		vict=victoire(M,size,tour,nb_coup_max); //test s'il y a victoire, défaite (nombre de coup > nombre coup max) ou si le jeu continu

		texte_victoire(vict); //s'il y a victoire ou défaite écrit "victory" ou "defeat" en fonction
	}

	free_grille(M, size);

	return 0;

}
