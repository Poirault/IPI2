#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("Mauvais nombre d'arguments \n");
		return 0; /*Premier argument : /, Deuxième argument : nom du fichier, Troisième argument : taille de la matrice*/
	}
	else
	{
		int i,j;
		int m=atoi(argv[2]);
		int test_unitaire=open(argv[1], O_RDONLY);
  		char buffer[100];
  		i=read(test_unitaire, buffer, sizeof(buffer));
  		for (i= 0; i < (m+1)*m; ++i)
  		{
    		printf("%c", buffer[i]);
    		
    		
  		}
  		printf("\n");
  		close(test_unitaire);
  		return 0;








		fclose(test_unitaire);


	}
}
