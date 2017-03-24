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


#define MAXFILS 6
typedef struct t_narbre {
 char info;
 struct t_narbre *tabfils[MAXFILS]; // tableau des fils, initialisés à NULL
 int nbFils; // nombre de fils, initialisé à 0.

} NNoeud, *NArbre;
#define NARBREVIDE NULL 


 NArbre nouvelNArbre(char info)
 	{
 		
 		NNoeud*a;
 		a=(NNoeud *)malloc(sizeof(NNoeud));
 		a->info=info; 
 		a->nbFils=0;
 		int i;
 		for (i = 0; i < MAXFILS; ++i)
 		{
 			a->tabfils[i]=NARBREVIDE;
 		}
 		return a;
 	}


 int narbreVide(NArbre a)
 	{
		return a==NARBREVIDE;
 	}

 
 NArbre ajoutFils(NArbre a, NArbre fils)
 	{

 		int i;
 		for (i = 0; i < MAXFILS; ++i)
 		{
 			if (narbreVide(a->tabfils[i]))
	 			{
	 				a->tabfils[i]=fils;
	 				a->nbFils++;
	 				return a;
	 			}
 		}
 		printf("Plus de place");	
 		return a;
 	}


void affNArbreRec(NArbre a, int j)
	{
		int k=0;
		if(narbreVide(a)!=1)

			{
				printf("n%d [label=%c]\n", j, a->info);
				if (j!=0)
					{
						printf("n%d -> n%d\n", (j-k)/10, j);

					}

				for (k = 1; k < MAXFILS; ++k)
				{
					affNArbreRec(a->tabfils[k-1], j*10 + k);
				}
				
			}


	}



 int main()
 {
 	
 	NArbre a1;

	a1=ajoutFils(ajoutFils(ajoutFils(ajoutFils(ajoutFils(ajoutFils(nouvelNArbre('R'),nouvelNArbre('J')),nouvelNArbre('M')),
		nouvelNArbre('V')),nouvelNArbre('B')),nouvelNArbre('G'));

	

	

	affNArbreRec(a1, 0);	


	return 0;
 }

