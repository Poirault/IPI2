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

#include "coul-fct_2.h"
#include "grille.h"

int main {
	/*Test matrice taille négative*/
	printf ("Test création de matrice à taille négative (m=-3)");
	int j,k;
	matrix M1;
	M1=grille(-3);
	for (j = 0; j < -3; ++j) {
			for (k = 0; k < -3; ++k) {
				printf("%10c", M1[j][k]);
			}
		printf("\n");
		}
	free(M1);
	
	/*Test matrice taille nulle*/
	printf ("Test création de matrice à taille nulle");
	matrix M2;
	M2=grille(0);
	for (j = 0; j < -3; ++j) {
			for (k = 0; k < 0; ++k) {
				printf("%10c", M2[j][k]);
			}
		printf("\n");
		}
	free(M2);

	/* Test matrice taille unitaire*/
	printf ("Test création de matrice à taille unitaire (m=1)");
	matrix M3;
	M3=grille(1);
	for (j = 0; j < 1; ++j) {
			for (k = 0; k < 1; ++k) {
				printf("%10c", M3[j][k]);
			}
		printf("\n");
		}
	free(M3);

	/*Test matrice taille normale*/
	printf ("Test création de matrice à taille normale (m=5)");
	matrix M;
	M=grille(5);
	for (j = 0; j < 5; ++j) {
			for (k = 0; k < 5; ++k) {
				printf("%10c", M[j][k]);
			}
		printf("\n");
		}
	
	/*Test colorplace avec des coordonnées en dehors de la grille*/
	matrix M4;	
	coord c;
	c.x = 7;
	c.y = 8;
	printf("Test 'colorplace' avec des coordonnées en dehors de la grille (7;8) avec la couleur J");
	M4 = colorplace(M, c, J);
	for (j = 0; j < 5; ++j) {
		for (k = 0; k < 5; ++k) {
			printf("%10c", M4[j][k]);
		}
	printf("\n");
	}
	free(M4);
	
	/*Test colorplace avec une couleur identique à la couleur à remplacer*/
	matrix M5;	
	coord c;
	c.x = 2;
	c.y = 2;
	char couleur = M[2][2];
	printf("Test 'colorplace' avec une couleur identique à la couleur à remplacer (la case de coordonnée (2;2)");
	M5 = colorplace(M, c, couleur);
	for (j = 0; j < 5; ++j) {
		for (k = 0; k < 5; ++k) {
			printf("%10c", M5[j][k]);
		}
	printf("\n");
	}
	free(M5);


	


	free(M);
}
	


