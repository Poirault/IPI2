
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

int nbcouleur(matrix M, int m);

int composante_conn2(matrix M,char color,int m){    
	int i,q,j;
	char co;
	q=1;
	int count=0;
	matrice mat1= NULL;
	mat1=(int **)calloc(m, sizeof(int*)); //création de cette dite matrice
	for (i = 0; i < m; ++i)
	{
		mat1[i]=(int *)calloc(m, sizeof(int));
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			mat1[i][j]=0;
		}
	}
	co=M[0][0];
	mat1[0][0]=1; //initialisation avec la couleur en haut à gauche
	while(q!=0){  //sélectionne toute les cases connexes de même couleur
		q=1;	//condition darrêt : lorsque plus rien ne change
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(mat1[i][j]==1){
					if (i<m-1){
						if (M[i+1][j]==co && mat1[i+1][j]!=1){
							mat1[i+1][j]=1;
							
							q=2;
						}
					}
					if (i>0){
						if (M[i-1][j]==co && mat1[i-1][j]!=1){
							mat1[i-1][j]=1;
							
							q=2;
						}
					}
					if (j<m-1){
						if (M[i][j+1]==co && mat1[i][j+1]!=1){
							mat1[i][j+1]=1;
							
							q=2;
						}
					}
					if (j>0){
						if (M[i][j-1]==co && mat1[i][j-1]!=1){
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
	for(i=0;i<m;i++){ //initialisation de la recherche de composante connexe de la nouvelle couleur
		for(j=0;j<m;j++){
			if(mat1[i][j]==1){
				if (i<m-1){
					if (M[i+1][j]==color && mat1[i+1][j]!=2){
						mat1[i+1][j]=2;
						count++;
					}
				}
				if (i>0){
					if (M[i-1][j]==color && mat1[i-1][j]!=2){
						mat1[i-1][j]=2;
						count++;
					}
				}
				if (j<m-1){
					if (M[i][j+1]==color && mat1[i][j+1]!=2){
						mat1[i][j+1]=2;
						count++;
					}
				}
				if (j>0){
					if (M[i][j-1]==color && mat1[i][j-1]!=2){
						mat1[i][j-1]=2;
						count++;
					}
				}
			}
		}
	}
	while(q!=0){ //boucle pour trouver tous les éléments connexes même cond d'arrêt que précedemment
		q=1;
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(mat1[i][j]==2){
					if (i<m-1){
						if (M[i+1][j]==color && mat1[i+1][j]!=2){
							mat1[i+1][j]=2;
							count++;
						}
						}
						if (i>0){
							if (M[i-1][j]==color && mat1[i-1][j]!=2){
								mat1[i-1][j]=2;
								count++;
							}
						}
						if (j<m-1){
							if (M[i][j+1]==color && mat1[i][j+1]!=2){
								mat1[i][j+1]=2;
								count++;
							}
						}
						if (j>0){
							if (M[i][j-1]==color && mat1[i][j-1]!=2){
								mat1[i][j-1]=2;
								count++;
						}
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	for (j = 0; j < m; ++j) //Libération d'espace mémoire
		{
			
			free(mat1[j]);
			
			
		
		}
	free(mat1);
	return(count);
}
int max(int a,int z,int e,int r,int w){
	int m=a;
	if(z>m){m=z;}
	if(e>m){m=e;}
	if(r>m){m=r;}
	if(w>m){m=w;}
	return(m);
}




char best(matrix M, int m){
	int i,j,k,tmp,tmp2,ref;
	ref=0;
	char c;
	matrice mat=(int **)calloc(m, sizeof(int*));
	for (i = 0; i < m; ++i)
		{
			mat[i]=(int *)calloc(m, sizeof(int));
		}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			mat[i][j]=0;
		}
	}
	matrix G=(char **)calloc(m, sizeof(char*));
	for (i = 0; i < m; ++i)
		{
			G[i]=(char *)calloc(m, sizeof(char));
		}
	for(k=0;k<6;k++){
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				G[i][j]=M[i][j];
			}
		}
		tmp=0;
		tmp2=0;
		if(nbcouleur(M,m)>2){
			if(k==0 && M[0][0]!='B'){
				tmp=composante_conn2(G,'B',m);
				mat=composante_conn(G,'B',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='B';
						}
					}
				}
				tmp2=max(composante_conn2(G,'J',m),composante_conn2(G,'G',m),composante_conn2(G,'R',m),composante_conn2(G,'M',m),composante_conn2(G,'V',m));
				ref=tmp+tmp2;c='B';
			}
			if(k==1 && M[0][0]!='J'){
				tmp=composante_conn2(G,'J',m);
				mat=composante_conn(G,'J',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='J';
						}
					}
				}
				tmp2=max(composante_conn2(G,'B',m),composante_conn2(G,'G',m),composante_conn2(G,'R',m),composante_conn2(G,'M',m),composante_conn2(G,'V',m));
				if(tmp+tmp2>ref){ref=tmp+tmp2;c='J';}
			}
			if(k==2 && M[0][0]!='R'){
				tmp=composante_conn2(G,'R',m);
				mat=composante_conn(G,'R',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='R';
						}
					}
				}
				tmp2=max(composante_conn2(G,'J',m),composante_conn2(G,'G',m),composante_conn2(G,'B',m),composante_conn2(G,'M',m),composante_conn2(G,'V',m));
				if(tmp+tmp2>ref){ref=tmp+tmp2;c='R';}
			}
			if(k==3 && M[0][0]!='M'){
				tmp=composante_conn2(G,'M',m);
				mat=composante_conn(G,'M',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='M';
						}
					}
				}
				tmp2=max(composante_conn2(G,'J',m),composante_conn2(G,'G',m),composante_conn2(G,'R',m),composante_conn2(G,'B',m),composante_conn2(G,'V',m));
				if(tmp+tmp2>ref){ref=tmp+tmp2;c='M';}
			}
			if(k==4 && M[0][0]!='G'){
				tmp=composante_conn2(G,'G',m);
				mat=composante_conn(G,'G',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='G';
						}
					}
				}
				tmp2=max(composante_conn2(G,'J',m),composante_conn2(G,'B',m),composante_conn2(G,'R',m),composante_conn2(G,'M',m),composante_conn2(G,'V',m));
				if(tmp+tmp2>ref){ref=tmp+tmp2;c='G';}
			}
			if(k==5 && M[0][0]!='V'){
				tmp=composante_conn2(G,'V',m);
				mat=composante_conn(G,'V',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat[j][k]==1 || mat[j][k]==2){
							G[j][k]='V';
						}
					}
				}
				tmp2=max(composante_conn2(G,'J',m),composante_conn2(G,'B',m),composante_conn2(G,'R',m),composante_conn2(G,'M',m),composante_conn2(G,'G',m));
				if(tmp+tmp2>ref){ref=tmp+tmp2;c='V';}
			}
		}
		if(nbcouleur(M,m)==2){
			if(k==0 && M[0][0]!='B'){
				tmp=composante_conn2(M,'B',m);
				c='B';
			}
			if(k==1 && M[0][0]!='J'){
				if(composante_conn2(M,'J',m)>tmp){
					tmp=composante_conn2(M,'J',m);
					c='J';
				}
			}
			if(k==2 && M[0][0]!='R'){
				if(composante_conn2(M,'R',m)>tmp){
					tmp=composante_conn2(M,'R',m);
					c='R';
				}
			}
			if(k==3 && M[0][0]!='G'){
				if(composante_conn2(M,'G',m)>tmp){
					tmp=composante_conn2(M,'G',m);
					c='G';
				}
			}
			if(k==4 && M[0][0]!='M'){
				if(composante_conn2(M,'M',m)>tmp){
					tmp=composante_conn2(M,'M',m);
					c='M';
				}
			}
			if(k==5 && M[0][0]!='V'){
				if(composante_conn2(M,'V',m)>tmp){
					tmp=composante_conn2(M,'V',m);
					c='V';
				}
			}
		}
	}
	for (j = 0; j < m; ++j) //Libération d'espace mémoire
		{
			
			free(mat[j]);

		
		}
		free(mat);
	return(c);
}















int nope(matrix M, char ch, int m){
	int i,q,j;
	q=1;
	int count=0;
	matrice mat1= NULL;
	mat1=(int **)calloc(m, sizeof(int*)); //création de cette dite matrice
	for (i = 0; i < m; ++i)
	{
		mat1[i]=(int *)calloc(m, sizeof(int));
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			mat1[i][j]=0;
		}
	}
	char co=M[0][0];
	mat1[0][0]=1; //initialisation avec la couleur en haut à gauche
	while(q!=0){  //sélectionne toute les cases connexes de même couleur
		q=1;	//condition darrêt : lorsque plus rien ne change
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(mat1[i][j]==1){
					if (i<m-1){
						if (M[i+1][j]==co && mat1[i+1][j]!=1){
							mat1[i+1][j]=1;
							
							q=2;
						}
					}
					if (i>0){
						if (M[i-1][j]==co && mat1[i-1][j]!=1){
							mat1[i-1][j]=1;
							
							q=2;
						}
					}
					if (j<m-1){
						if (M[i][j+1]==co && mat1[i][j+1]!=1){
							mat1[i][j+1]=1;
							
							q=2;
						}
					}
					if (j>0){
						if (M[i][j-1]==co && mat1[i][j-1]!=1){
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
	for(i=0;i<m;i++){ //initialisation de la recherche de composante connexe de la nouvelle couleur
		for(j=0;j<m;j++){
			if(mat1[i][j]==1){
				if (i<m-1){
					if (M[i+1][j]==ch && mat1[i+1][j]!=2){
						mat1[i+1][j]=2;
						count++;
					}
				}
				if (i>0){
					if (M[i-1][j]==ch && mat1[i-1][j]!=2){
						mat1[i-1][j]=2;
						count++;
					}
				}
				if (j<m-1){
					if (M[i][j+1]==ch && mat1[i][j+1]!=2){
						mat1[i][j+1]=2;
						count++;
					}
				}
				if (j>0){
					if (M[i][j-1]==ch && mat1[i][j-1]!=2){
						mat1[i][j-1]=2;
						count++;
					}
				}
			}
		}
	}
	while(q!=0){ //boucle pour trouver tous les éléments connexes même cond d'arrêt que précedemment
		q=1;
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(mat1[i][j]==2){
					if (i<m-1){
						if (M[i+1][j]==ch && mat1[i+1][j]!=2){
							mat1[i+1][j]=2;
							count++;
						}
						}
						if (i>0){
							if (M[i-1][j]==ch && mat1[i-1][j]!=2){
								mat1[i-1][j]=2;
								count++;
							}
						}
						if (j<m-1){
							if (M[i][j+1]==ch && mat1[i][j+1]!=2){
								mat1[i][j+1]=2;
								count++;
							}
						}
						if (j>0){
							if (M[i][j-1]==ch && mat1[i][j-1]!=2){
								mat1[i][j-1]=2;
								count++;
						}
					}
				}
				if (q==1){
					q=0;
				}
			}
		}
	}
	for (j = 0; j < m; ++j) //Libération d'espace mémoire
		{
			
			free(mat1[j]);
			
			
		
		}
	free(mat1);
	return(count);	
}



char* createlist(int n){           //fonction permettant la création de liste 
	char* l=malloc(n*sizeof(char));
	for(int i=0;i<n;i++){
		l[i]=' ';
	}
	return(l);
}





void test(char* l, int n){  //fonction permettant l'affichage
	printf("Voici une liste : ");
	for(int i=0;i<n;i++){
		printf("%c",l[i]);
	}
	printf("\n");
}



/* cette fonction bug pour du 2*2 et je n'arrive pas à afficher le jeu après*/
int resolution(matrix M, int m){
	int i,j,k,count;
	char c;
	char* l= createlist(1);
	char* t= createlist(1);
	matrice mat1=(int **)calloc(m, sizeof(int*));
	for (i = 0; i < m; ++i)
		{
			mat1[i]=(int *)calloc(m, sizeof(int));
		}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			mat1[i][j]=0;
		}
	}
	count=0;
	while(nbcouleur(M,m)>1){
		count++;
		c=best(M, m);
		t=createlist(count+1);
		for (i = 0; i < count; ++i)
		{
			t[i]=l[i];
		}
		t[count]=c;
		l=createlist(count+1);
		for (i = 0; i < count+1; ++i)
		{
			l[i]=t[i];
		}
		printf("Couleur choisie : %c\n",  c);


		mat1=composante_conn(M,c,m);
		for ( j = 0; j < m; ++j){
			for (int k = 0; k < m; ++k){
				if(mat1[j][k]==1 || mat1[j][k]==2){
					M[j][k]=c;
				}
			}
		}
	
	
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < m; ++k)
			{
	
				affich_couleur(M,j,k); //affiche les couleurs avec 10 espaces entre les couleurs d'une même ligne
			}
		printf("\n");


			} 
		printf("Nombre de coup : %d  \n", count);
		}
		test(l,count+1);
			
	for (j = 0; j < m; ++j) //Libération d'espace mémoire
		{
			
			free(mat1[j]);
			
			
		
		}
		free(mat1);
return(count);
}





int testvictoire(matrix M, char* l, int n, int m){  // fonction permettant de voir si une liste est solution (et cb de coups sont utilisés)
	matrice T;
	
	matrix P=NULL;
	P=(char **)calloc(m, sizeof(char*));
	for (int j = 0; j < m; ++j)
	{
		P[j]=(char *)calloc(m, sizeof(char));
	}
	for ( int j = 0; j < m; ++j){
			for (int k = 0; k < m; ++k){
				P[j][k]=M[j][k];
			}
	}
	int i;
	for( i=0;i<n;i++){
		T=composante_conn(P,l[i],m);
		for (int j = 0; j < m; ++j){
			for (int k = 0; k < m; ++k){
				if(T[j][k]==1 || T[j][k]==2){
					P[j][k]=l[i]; //on a pas besoin de la fct coloreplace
					if(nbcouleur(P,m)==0){
						printf("\nnombre de couleurs dans la liste : %d\n",i);
						return(i);
						
					}
				}
			}
		}
	}
	return(10000);
}


int nbcouleur(matrix M, int m){
	int b=0;
	int j=0;
	int g=0;
	int r=0;
	int ma=0;
	int v=0;
	for(int i=0;i<m;i++){
		for(int k=0;k<m;k++){
			if(M[i][k]=='B'){b=1;}
			if(M[i][k]=='J'){j=1;}
			if(M[i][k]=='R'){r=1;}
			if(M[i][k]=='G'){g=1;}
			if(M[i][k]=='M'){ma=1;}
			if(M[i][k]=='V'){v=1;}
		}
	}
	return(b+j+r+g+ma+v);
}
	

void thelist(matrix M,char* l, int n,int i,int m,char* liste){ // fonction de création des listes et test des listes
	int j, k;
	matrice mat1= NULL;
	mat1=(int **)calloc(m, sizeof(int*)); 
	for (k = 0; k < m; ++k)
	{
		mat1[k]=(int *)calloc(m, sizeof(int));
	}
	for(k=0;k<m;k++){
		for(j=0;j<m;j++){
			mat1[k][j]=0;
		}

	}
	char* t=(char*)malloc(n*sizeof(char));
	for(int j=0;j<i+1;j++){
		t[j]=l[j];
	}

	matrix G=(char **)calloc(m, sizeof(char*));
	for (k = 0; k < m; ++k)
		{
			G[k]=(char *)calloc(m, sizeof(char));
		}
	for(k=0;k<m;k++){
			for(j=0;j<m;j++){
				G[k][j]=M[k][j];
			}
		}

	if(i<n-1 ){   //travail récursif sur les listes pour atteindre toutes les possibilités
		if(i==0){
			if(nope(G, 'B',m)!=0){
				t[0]='B';
				mat1=composante_conn(G,'B',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat1[j][k]==1 || mat1[j][k]==2){
							G[j][k]='B';
						}
					}
				}
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}

			if(nope(G, 'J',m)!=0){
				t[0]='J';
				mat1=composante_conn(G,'J',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat1[j][k]==1 || mat1[j][k]==2){
							G[j][k]='J';
						}
					}
				}
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}

			if(nope(G, 'R',m)!=0){
				mat1=composante_conn(G,'R',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat1[j][k]==1 || mat1[j][k]==2){
							G[j][k]='R';
						}
					}
				}
				t[0]='R';
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}

			if(nope(G, 'G',m)!=0){
			mat1=composante_conn(G,'G',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='G';
					}
				}
			}
				t[0]='G';
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}

			if(nope(G, 'M',m)!=0){
				mat1=composante_conn(G,'M',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat1[j][k]==1 || mat1[j][k]==2){
							G[j][k]='M';
						}
					}
				}
				t[0]='M';
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}

			if(nope(G, 'V',m)!=0){
				mat1=composante_conn(G,'V',m);
				for ( j = 0; j < m; ++j){
					for (int k = 0; k < m; ++k){
						if(mat1[j][k]==1 || mat1[j][k]==2){
							G[j][k]='V';
						}
					}
				}
				t[0]='V';
				thelist(G,t,n,i+1,m,liste);
				for(k=0;k<m;k++){
					for(j=0;j<m;j++){
						G[k][j]=M[k][j];
					}
				}
			}
		}

		if(i!=0 && t[i-1]!='B' && nope(G, 'B',m)!=0){
			t[i]='B';
			mat1=composante_conn(G,'B',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='B';
					}
				}
			}
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[k][j];
				}
			}
		}

		if(i!=0 && t[i-1]!='J' && nope(G, 'J',m)!=0){
			mat1=composante_conn(G,'J',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='J';
					}
				}
			}
			t[i]='J';
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[k][j];
				}
			}
		}

		if(i!=0 && t[i-1]!='R' && nope(G, 'R',m)!=0){
			t[i]='R';
			mat1=composante_conn(G,'R',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='R';
					}
				}
			}
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[k][j];
				}
			}
		}

		if(i!=0 && t[i-1]!='G' && nope(G, 'G',m)!=0){
			mat1=composante_conn(G,'G',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='G';
					}
				}
			}
			t[i]='G';
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[k][j];
				}
			}
		}

		if(i!=0 && t[i-1]!='M' && nope(G, 'M',m)!=0){
			mat1=composante_conn(G,'M',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='M';
					}
				}
			}
			t[i]='M';
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[k][j];
				}
			}
		}
	
		if(i!=0 && t[i-1]!='V' && nope(G, 'V',m)!=0){
			mat1=composante_conn(G,'V',m);
			for ( j = 0; j < m; ++j){
				for (int k = 0; k < m; ++k){
					if(mat1[j][k]==1 || mat1[j][k]==2){
						G[j][k]='V';
					}
				}
			}
			t[i]='V';
			thelist(G,t,n,i+1,m,liste);
			for(k=0;k<m;k++){
				for(j=0;j<m;j++){
					G[k][j]=M[j][j];
				}
			}
		}
	}
	
	if(i==n-1){
			
			if(nbcouleur(G,m)==1){
				liste=t;
				test(t,n);printf("\n");
printf("\n");
			}
			
			
			
			
		}
	
	}
	



