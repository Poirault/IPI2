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
	affiche_grille(M, size);

	nb_coup_max = nmbre_coup(size); //formule empirique du jeu

	printf ("Voulez-vous afficher une solution ?\n Si oui tapez 'o' sinon tapez 'n' \n");
	scanf("%c", &choix);
	scanf("%c", &choix);
	if (choix == 'o')
	{
		P = copie(M, size);
		solveur(P, size, nb_coup_max);
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
		
		vict=victoire(M,size,tour,nb_coup_max);

		texte_victoire(vict);
	}

	free_grille(M, size);
	free_grille(P, size);

	return 0;

}
