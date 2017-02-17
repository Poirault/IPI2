#include "coul-fct1_2.h"
#include "grille.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>

int main()
{
	int j,k,m;
	matrix M;
	printf("Donnez la taille du jeu");
	scanf("%d",&m);
	M=testmat1(m);

	for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				
				printf("%10c", M[j][k]);
			}
		printf("\n");
		}
	
	free(M);

	return 0;

}
