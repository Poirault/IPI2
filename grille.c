#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>


typedef char **matrix;

/*
Fonction qui créer un chiffre aléatoire entre a et b
*/
int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;// Pour commencer à "a"
}


/*
Fonction créant la grille du jeu avec des couleur aléatoire
*/
matrix mat1(int m)
{
	int a,b,i,test;
	char **mat1= NULL;
	mat1=(char **)calloc(m, sizeof(char*));
	for (i = 0; i < m; ++i)
	{
		mat1[i]=(char *)calloc(m, sizeof(char));
	}
	
	for (a = 0; a < m; ++a)
    {
        for (b = 0; b < m; ++b)
        {
            test=0;
            test=rand_a_b(1,6);
            
            if(test==1)
            {
            	mat1[a][b]='B'; //Bleu
            }
            if(test==2)
            {
            	mat1[a][b]='G'; //Gris
            }
            if(test==3)
            {
            	mat1[a][b]='J'; //Jaune
            }
            if(test==4)
            {
            	mat1[a][b]='M'; //Marron
            }
            if(test==5)
            {
            	mat1[a][b]='R'; //Rouge
            }
            if(test==6)
            {
            	mat1[a][b]='V'; //Vert
            }
                     
        }
    }

	return mat1;


}






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
