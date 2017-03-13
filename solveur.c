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

/*
solveur(matrix T, pile solution) 
{
	// déclarations des variables locales i, g2, ...
	int i;
	for (i=0; i<6; i=i+1) 
		{ // pour toutes les couleurs possibles
		if (choixPertinent(T,i)) 
			{
			solution = empiler(solution,c[i]);
			g2 = propageCouleur(T, c[i]);
			if 
			{
				(terminaison(g2)) uneSolutionTrouvee(solution);
			}
			else 
			{
				solveur(g2, solution);
			}
			depiler(&solution);
			}
		}
}*/