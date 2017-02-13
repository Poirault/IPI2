#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <string.h>

struct coord{                    /*J'ai crée une nouvelle structure simple pour faciliter les chose surement à remettre dans le main*/
	int x;
	int y;
};

	
matrix coloreplace(matrix m,coord c,char color){                              /* J'ai supposé que la matrice était initiée en globale*/
	if(c.x>t || c.y>t){
		printf("Coordonnées non valide :(%d;%d)",x,y);
		return (m);
	}
	else{
		m[c.x][c.y]='color';
		return(m);
	}
}


typedef int** matrice;

matrice composante_conn(matrix M,char color){    /*renvoie une matrice d'entier donnant les cases à colorier (pas du tout optimal)*/
	int i,q;
	char c;
	q=1;
	matrice mat1= NULL;
	mat1=(int **)calloc(m, sizeof(int*));         /*création de cette dite matrice*/
	for (i = 0; i < m; ++i)
	{
		mat1[i]=(int *)calloc(m, sizeof(int));
	}
	c=M[0][0];
	mat1[0][0]=1;                     /*initialisation avec la couleur en haut à gauche*/
	while(q!=0){                      /*sélectionne toute les cases connexes de même couleur*/
		q=1;							/*condition darrêt : lorsque plus rien ne change*/
		for(i=0,i<m,i++){
			for(j=0,j<m,j++){
				if(mat[i][j]==1){
					if (M[i+1][j]==c){
						mat1[i+1][j]=1;
						q=2;
					}
					if (M[i-1][j]==c){
						mat1[i-1][j]=1;
						q=2;
					}
					if (M[i][j+1]==c){
						mat1[i][j+1]=1;
						q=2;
					}
					if (M[i][j-1]==c){
						mat1[i][j-1]=1;
						q=2;
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	q=1;					/*remise de la cond d'arrêt*/
	for(i=0,i<m,i++){					/*initialisation de la recherche de composante connexe de la nouvelle couleur*/
		for(j=0,j<m,j++){
			if(mat[i][j]==1){
				if (M[i+1][j]==c){
					mat1[i+1][j]=2;
				}
				if (M[i-1][j]==c){
					mat1[i-1][j]=2;
				}
				if (M[i][j+1]==c){
					mat1[i][j+1]=2;
				}
				if (M[i][j-1]==c){
					mat1[i][j-1]=2;
				}
			}
		}
	}
	while(q!=0){		/*boucle pour trouver tous les éléments connexes même cond d'arrêt que précedemment*/
		q=1;
		for(i=0,i<m,i++){
			for(j=0,j<m,j++){
				if(mat[i][j]==2){
					if (M[i+1][j]==c){
						mat1[i+1][j]=2;
						q=2;
					}
					if (M[i-1][j]==c){
						mat1[i-1][j]=2;
						q=2;
					}
					if (M[i][j+1]==c){
						mat1[i][j+1]=2;
						q=2;
					}
					if (M[i][j-1]==c){
						mat1[i][j-1]=2;
						q=2;
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	return(mat1);/*retour de la mat de coloriage les 1 et 2 sont à colorier le reste (0) sont à laisser tel quel chez la mat de char */
}
		
						
	
	
	
	
	
