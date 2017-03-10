#include "fonctions_utiles.h"
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


/*
On a été voir sur internet le jeu et on en a conclu que la formule moyenne du nombre de coup 
en fonction de la taille du jeu de 1,7*tailleJeu
*/
int nmbre_coup(int m)
{
	int nmbre_coup,partie_entiere;
	nmbre_coup= 1.7*m; //Pondération empirique
	partie_entiere= floor(nmbre_coup)+1;
	return partie_entiere;
}

