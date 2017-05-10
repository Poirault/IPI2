#include "fct_couleur.h"
#include "grille.h"
#include "fonctions_utiles.h"
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

/*
Structure simple pour accéder au coordonnées (x;y)
*/
struct coord{                    
	int x;
	int y;
};


/* 
Fonction permettant aux joueurs d'interagir avec le jeu 
*/
int getche(void) {                                 
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}


/*
Prend les coordonnées c(x;y) d'une matrice pour changer par la couleur 'color' 
*/	
matrix coloreplace(matrix M,coord c,char color,int size){ //J'ai supposé que la matrice était initiée en globale
	if(c.x>size || c.y>size){
		printf("Coordonnées non valide :(%d;%d)",c.x,c.y);
		return (M);
	}
	else{
		M[c.x][c.y]=color;
		return(M);
	}
}



/*
Renvoie une matrice d'entier donnant les cases à colorier (pas du tout optimal)
*/
matrice composante_conn(matrix M,char color,int size){    
	int i,q,j;
	char c;
	q=1;
	matrice mat1= NULL;
	mat1=(int **)calloc(size, sizeof(int*)); //création de cette dite matrice
	for (i = 0; i < size; ++i)
	{
		mat1[i]=(int *)calloc(size, sizeof(int));
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			mat1[i][j]=0;
		}
	}
	c=M[0][0];
	mat1[0][0]=1; //initialisation avec la couleur en haut à gauche
	while(q!=0){  //sélectionne toute les cases connexes de même couleur
		q=1;	//condition darrêt : lorsque plus rien ne change
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(mat1[i][j]==1){
					if (i<size-1){
						if (M[i+1][j]==c && mat1[i+1][j]!=1){
							mat1[i+1][j]=1;
							q=2;
						}
					}
					if (i>0){
						if (M[i-1][j]==c && mat1[i-1][j]!=1){
							mat1[i-1][j]=1;
							q=2;
						}
					}
					if (j<size-1){
						if (M[i][j+1]==c && mat1[i][j+1]!=1){
							mat1[i][j+1]=1;
							q=2;
						}
					}
					if (j>0){
						if (M[i][j-1]==c && mat1[i][j-1]!=1){
							mat1[i][j-1]=1;
							q=2;
						}
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	q=1; //remise de la cond d'arrêt
	for(i=0;i<size;i++){ //initialisation de la recherche de composante connexe de la nouvelle couleur
		for(j=0;j<size;j++){
			if(mat1[i][j]==1){
				if (i<size-1){
					if (M[i+1][j]==color){
						mat1[i+1][j]=2;
					}
				}
				if (i>0){
					if (M[i-1][j]==color){
						mat1[i-1][j]=2;
					}
				}
				if (j<size-1){
					if (M[i][j+1]==color){
						mat1[i][j+1]=2;
					}
				}
				if (j>0){
					if (M[i][j-1]==color){
						mat1[i][j-1]=2;
					}
				}
			}
		}
	}
	while(q!=0){ //boucle pour trouver tous les éléments connexes même cond d'arrêt que précedemment
		q=1;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(mat1[i][j]==2){
					if (i<size-1){
						if (M[i+1][j]==color && mat1[i+1][j]!=2){
							mat1[i+1][j]=2;
							q=2;
						}
					}
					if (i>0){
						if (M[i-1][j]==color && mat1[i-1][j]!=2){
							mat1[i-1][j]=2;
							q=2;
						}
					}
					if (j<size-1){
						if (M[i][j+1]==color && mat1[i][j+1]!=2){
							mat1[i][j+1]=2;
							q=2;
						}
					}
					if (j>0){
						if (M[i][j-1]==color && mat1[i][j-1]!=2){
							mat1[i][j-1]=2;
							q=2;
						}
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	return(mat1);

	free_matrice(mat1, size);
	/*
	retour de la matrice de coloriage les 1 et 2 sont à colorier le reste (0) sont à laisser tel quel chez la mat de char 
	*/
}


void modif_color(matrix M, char color, int size)
{
	matrice T = composante_conn(M,color,size);
	int k, j;

	for (j = 0; j < size; ++j)
	{
		for (k = 0; k < size; ++k)
		{
			if(T[j][k]==1 || T[j][k]==2) //là où il y a des 1 et des 2 il faut changer par la nouvelle couleur (color)
			{
				M[j][k]=color;
			}
		}
	}
	free_matrice(T, size);
}
		
						
	
	
	
	
	

	
