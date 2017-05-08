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
	int size = 0, nbr_coup = 0, nbr_coups_max = 0, bouton, out;
	int size_window = 0;	/*size_window dépend de size*/
	matrix T;
	bool border_flag = false;
	char nbr_coup_texte[50];

	SDL_Surface *ecran = NULL;
	TTF_Font *police1 = NULL, *police2 = NULL;

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

	police1 = TTF_OpenFont("texte.ttf", 20);
	police2 = TTF_OpenFont("texte.ttf", 70);

	//SDL_WM_SetIcon(SDL_LoadBMP("img/colorflood.bmp"), NULL); icône de la fenêtre 


	do 
		{
			ecran = menu(police1, police2, &size, nbr_coups_max);

			if (size != 0)
				{
					T = grille(size);
					matrix grille_copie;

					
					nbr_coups_max=1.7*size;
					do 
						{
							grille_copie = copie(T, size);
							size_window = 500;
							ecran = initialize_screen(size_window);

							sprintf(nbr_coup_texte, "%d/%d", nbr_coup, nbr_coups_max);

							initialize_text(ecran, nbr_coup_texte, police1);
							
							display_SDL(ecran, T, size, size_window, border_flag);

							nbr_coup = loop_game(ecran, T, size, nbr_coups_max, nbr_coup_texte, police1, size_window, border_flag, &bouton, &out);

							end_game(ecran, T, size, nbr_coup, nbr_coups_max, police2);

							T = grille_copie;
						} while (bouton == 2 && out != 1);

						free_grille(T, size);
						//free_grille(grille_copie, size); ?
				}
		} while (bouton == 1 && size != 0 && out != 1);

	TTF_CloseFont(police1);
	TTF_CloseFont(police2);
	TTF_Quit();

	SDL_Quit();

	return 0;
}