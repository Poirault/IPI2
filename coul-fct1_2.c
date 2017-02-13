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

struct voisin{     /*Une deuxième structure pour pouvoir accès aux voisins via des fonctions*/
	coord haut;
	coord bas;
	coord gauche;
	coord droite;
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

voisin* voisinage(matrix m,coord c,int n){  /* n la taille de la matrice*/
	voisins* v =malloc(sizeof(*v));
	if(c.y !=0){
		v.haut.x = c.x ; 
		v.haut.y = c.y +1;
	}
	else{
		v.haut.x = c.x ;   /*mettre (0;0)??*/
		v.haut.y = c.y ;
	}
	if(c.y !=n-1){
		v.bas.x = c.x ; 
		v.haut.y = c.y -1;
	}
	else{
		v.haut.x = c.x ;   /*mettre (0;0)??*/
		v.haut.y = c.y ;
	if(c.x !=0){
		v.gauche.x = c.x -1; 
		v.haut.y = c.y;
	}
	else{
		v.haut.x = c.x ;   /*mettre (0;0)??*/
		v.haut.y = c.y ;
	}
	if(c.x !=n-1){
		v.droite.x = c.x +1; 
		v.haut.y = c.y;
	}
	else{
		v.haut.x = c.x ;   /*mettre (0;0)??*/
		v.haut.y = c.y ;
	}	
	return(v);
}
	
	
	
	
	
	
