#include "SDL.h"
#include "fct_couleur.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "solveur.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

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




int main()
{
	int size = 0, nbr_coup = 0, nb_coup_max = 0, bouton, out;
	int size_window = 0;	/*size_window dépend de size*/
	matrix T;
	bool separation = false;
	char nbr_coup_texte[50];

	SDL_Surface *ecran = NULL;
	TTF_Font *police1 = NULL, *police2 = NULL, *police3 = NULL, *police4 = NULL;

	/*On initialise la SDL*/
	const SDL_VideoInfo *info = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError());
		SDL_Quit();
	}
	info = SDL_GetVideoInfo();
	if(!info)
	{
		fprintf(stderr, "Video query failed: %s\n", SDL_GetError());
		SDL_Quit();
	}
	/*fin d'initialisation*/ 

	TTF_Init();

	police1 = TTF_OpenFont("essai.ttf", 20); //police pour le choix taille du jeu
	police2 = TTF_OpenFont("stocky.ttf", 70); //police pour "Color Flood" dans le menu
	police3 = TTF_OpenFont("texte.ttf", 20);
	police4 = TTF_OpenFont("texte.ttf", 40); //police pour le texte dans le déroulement du jeu

	//SDL_WM_SetIcon(SDL_LoadBMP("img/colorflood.bmp"), NULL); icône de la fenêtre 


	do 
		{
			ecran = menu(police1, police2, &size); //mise en place du menu

			if (size != 0)
				{
					T = grille(size); //initialisation d'une grille random pour le jeu
					matrix grille_copie; //pour pouvoir rejouer si le joueur le souhaite

					
					nb_coup_max=1.9*size;
					do 
						{
							grille_copie = copie(T, size);
							size_window = 500; //taille que l'on a choisi pour la fenêtre 
							ecran = initialize_screen(size_window); //itialise l'écran en fond noir

							sprintf(nbr_coup_texte, "%d", nb_coup_max-nbr_coup); //pour les coup(s) restant(s)

							texte(ecran, police3, police4);
							
							display_SDL(ecran, T, size, size_window, separation); //affiche la grille du jeu

							nbr_coup = boucle_jeu(ecran, T, size, nb_coup_max, nbr_coup_texte, police4, size_window, separation, &bouton, &out); //fait tourner le jeu jusque victoire ou défaite

							fin_jeu(ecran, T, size, nbr_coup, nb_coup_max, police2); //affichage en fonction de victoire ou défaite

							T = grille_copie;
						} while (bouton == 2 && out != 1); //tant que le joueur ne ferme pas le jeu ou ne clique pas sur menu

						free_grille(T, size);
						//free_grille(grille_copie, size);
					
				}
		} while (bouton == 1 && size != 0 && out != 1); //tant que le joueur ne ferme pas le jeu


	TTF_CloseFont(police1);
	TTF_CloseFont(police2);
	TTF_CloseFont(police3);
	TTF_Quit();

	SDL_Quit();

	return 0;
}