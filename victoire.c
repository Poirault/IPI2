#include "victoire.h"
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
#include <time.h>
int victoire(matrix M,int m)
{
	int j,k;
	int vict=0;
	for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				if(M[0][0]!=M[j][k])
				{
					vict=1;
				}
			}
		}
	if (vict==0){printf("Victory !\n");}
	return(vict);
}
