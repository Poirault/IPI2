#include "SDL.h"
#include "coul-fct1_2.h"
#include "grille.h"
#include "fonctions_utiles.h"
#include "victoire.h"
#include "couleur.h"
#include "solveur.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>




void drawRectangle(SDL_Surface *ecran, int px, int py, int size, RGB couleur)
{
	SDL_Rect rect;
	rect.y=px;
	rect.x=py;
	rect.h=rect.w=size;
	SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, couleur.r, couleur.g, couleur.b));
}

void fillScreen(SDL_Surface *ecran, RGB couleur)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, couleur.r, couleur.g, couleur.b));
	SDL_Flip(ecran);	/*MàJ de l'écran*/
}

void display_menu(SDL_Surface *ecran, matrix T, int size, int size_window)
{
	size_window=size_window-9;

	RGB J = {255, 247, 0}; //Jaune
	RGB R = {255, 0, 0 };  //Rougr
	RGB G = {169, 143, 100}; //Gris
	RGB V = {85, 107, 47}; //Vert
	RGB B = {255,255,102}; //Bleu
	RGB M = {255, 153, 102}; //Magenta

	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 245, 240, 240));
	int i, j;
	char couleur;

	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			couleur = T[i][j];
			switch (couleur)
			{
				case 'B':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, B);
				break;

				case 'V':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, V);
				break;

				case 'R':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, R);
				break;

				case 'J':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, J);
				break;

				case 'M':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, M);
				break;

				case 'G':
				drawRectangle(ecran, i*size_window/size+i*1, j*size_window/size+j*1, size_window/size, G);
				break;
			}
		}
	}
	SDL_Flip(ecran);
}


void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima) {
	SDL_Rect rect;
    rect.x=px;
    rect.y=py;
	SDL_BlitSurface(ima, NULL, ecran, &rect);
	SDL_Flip(ecran);
}

SDL_Surface *initialize_screen(int size_window)
{

	SDL_Surface *ecran = NULL;
	RGB init_screen = {255,255,255};	//blanc

	ecran = SDL_SetVideoMode(2*size_window, size_window+120, 8, SDL_HWSURFACE);
	/* nom de la fenêtre */
	SDL_WM_SetCaption("ColorFlood (THOR)", NULL);

	/*
	SDL_Rect positionFond;
	positionFond.x = 0;
	positionFond.y = 0;
	SDL_Surface *ima1=NULL;
	ima1 = SDL_LoadBMP("img/fond1.bmp");
	SDL_BlitSurface(ima1, NULL, ecran, &positionFond);
	*/
	
	SDL_Surface *img=SDL_LoadBMP("./home.bmp");
    drawTexture(ecran, 50, 50, img);
    SDL_FreeSurface(img);
	
	/* écran tout blanc */
	fillScreen(ecran, init_screen);
	
	return ecran;
}

void initialize_text(SDL_Surface *ecran,char *nbr_coup_texte, TTF_Font *police)
{
	SDL_Rect position1,position2,position3,position4;
	SDL_Rect position_menu, position_rejouer;
	SDL_Color texteNoir = {0, 0, 0, 42}, fondBlanc = {255, 255, 255, 42};	/* 4ème paramètre inutile */
	SDL_Surface *texte1,*texte2,*texte3,*texte4;
	SDL_Surface *menu, *rejouer;

	texte1 = TTF_RenderUTF8_Shaded(police, "Color Box", texteNoir, fondBlanc);
	texte2 = TTF_RenderUTF8_Shaded(police, "Afficher le solveur ", texteNoir, fondBlanc);
	texte3 = TTF_RenderUTF8_Shaded(police, "Nombre de coups ", texteNoir, fondBlanc);
	texte4 = TTF_RenderUTF8_Shaded(police, nbr_coup_texte, texteNoir, fondBlanc);
	menu = TTF_RenderUTF8_Shaded(police, "Menu", texteNoir, fondBlanc);
	rejouer = TTF_RenderUTF8_Shaded(police, "Rejouer", texteNoir, fondBlanc);

	position1.x = 80;
	position1.y = 520;
	position2.x = 785;
	position2.y = 455;
	position3.x = 500*(3/2.0)+40;
	position3.y = 500/2.0;
	position4.x = 500*(3/2.0)+90;
	position4.y = 500/2.0+30;

	position_menu.x = 802;
	position_menu.y = 100;
	position_rejouer.x = 890;
	position_rejouer.y = 100;

	SDL_BlitSurface(texte1, NULL, ecran, &position1);
	SDL_BlitSurface(texte2, NULL, ecran, &position2);
	SDL_BlitSurface(texte3, NULL, ecran, &position3);
	SDL_BlitSurface(texte4, NULL, ecran, &position4);
	SDL_BlitSurface(menu, NULL, ecran, &position_menu);
	SDL_BlitSurface(rejouer, NULL, ecran, &position_rejouer);
	
	SDL_FreeSurface(texte1);
	SDL_FreeSurface(texte2);
	SDL_FreeSurface(texte3);
	SDL_FreeSurface(texte4);
	SDL_FreeSurface(menu);
	SDL_FreeSurface(rejouer);
}

void color_box(SDL_Surface *ecran,int size_window)
{
	RGB J = {255, 247, 0}; //Jaune
	RGB R = {255, 0, 0 };  //Rougr
	RGB G = {169, 143, 100}; //Gris
	RGB V = {85, 107, 47}; //Vert
	RGB B = {255,255,102}; //Bleu
	RGB M = {255, 153, 102}; //Magenta
	RGB solveur = {66,66,66};
	RGB menu = {100,100,100};
	RGB rejouer = {150,150,150};
	drawRectangle(ecran, size_window*(0.0/6)+20, size_window/4.0-40, (size_window-40)/6, G);
	drawRectangle(ecran, size_window*(1.0/6)+20,size_window/4.0-40, (size_window-40)/6, R);
	drawRectangle(ecran, size_window*(2.0/6)+20,size_window/4.0-40, (size_window-40)/6, J);
	drawRectangle(ecran, size_window*(3.0/6)+20,size_window/4.0-40, (size_window-40)/6, V);
	drawRectangle(ecran, size_window*(4.0/6)+20,size_window/4.0-40, (size_window-40)/6, B);
	drawRectangle(ecran, size_window*(5.0/6)+20,size_window/4.0-40, (size_window-40)/6, M);	
	drawRectangle(ecran, size_window/2.0+100,size_window*(3/2.0)+80, (size_window-40)/6, solveur);	
	drawRectangle(ecran, 25,size_window*(3/2.0)+40, (size_window-40)/6, menu);	
	drawRectangle(ecran, 25,size_window*(3/2.0)+135, (size_window-40)/6, rejouer);	
}


void display_SDL(SDL_Surface *ecran, matrix T, int size, int size_window, bool border_flag)
{
	RGB V = {153, 255, 0}; //vert
	RGB R = {204, 0, 51};  //Rouge
	RGB B = {0, 102, 255}; //blue
	RGB G = {102, 204, 204}; //gris
	RGB J = {255,255,102}; //jaune
	RGB M = {153, 0, 255}; //magenta

	int i, j;
	char couleur;

	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			couleur = T[i][j];
			if(border_flag==false)
				switch (couleur)
				{
					case 'B':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, B);
					break;

					case 'V':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, V);
					break;

					case 'R':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, R);
					break;

					case 'J':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, J);
					break;

					case 'M':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, M);
					break;

					case 'G':
					drawRectangle(ecran, i*size_window/size+10+i*2, j*size_window/size+size_window*(1.0/2)+j*2-size, size_window/size, G);
					break;
				}
			else
				switch (couleur)
				{
					case 'B':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, B);
					break;

					case 'V':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, V);
					break;

					case 'R':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, R);
					break;

					case 'J':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, J);
					break;

					case 'M':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, M);
					break;

					case 'G':
					drawRectangle(ecran, i*size_window/size+10, j*size_window/size+size_window*(1.0/2)-size, size_window/size+size_window%size, G);
					break;
				}
		}
	}
	SDL_Flip(ecran);
}

int loop_game(SDL_Surface *ecran, matrix T, int size, int nbr_coups_max, char *nbr_coup_texte, TTF_Font *police, int size_window, bool border_flag, int* bouton, int* out)
{
	int continuer = 1, nbr_coup = 0, exit = 0;
	SDL_Surface *texte, *texte1,*texte2;
	char solveur_info[30];
	SDL_Event event;
	SDL_Color texteNoir = {0, 0, 0, 42}, fondBlanc = {245, 240, 240, 42};
	SDL_Rect position, position1;

	position.x = 500*(3/2.0)+90;
	position.y = 500/2.0+30;
	position1.x = 80;
	position1.y = 550;

	color_box(ecran,size_window);
	
	int nbr_coups_min;
	char* chemin;
	bool flip = true;
	while(victoire(T, size, nbr_coup, nbr_coups_max) != 0 && victoire(T, size, nbr_coup, nbr_coups_max) != 2 
		&& continuer && exit == 0)
	{
		char ancienne_couleur = T[0][0];
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
			*out = 1;
			continuer = 0;
			break;

			case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				int x = event.button.x;
				int y = event.button.y;
				int cons=(size_window-40)/6;
				
	
				if(y >= (size_window*(0.0/6)+20) && y < (size_window*(0.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'G', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				if(y >= (size_window*(1.0/6)+20) && y < (size_window*(1.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'R', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				if(y >= (size_window*(2.0/6)+20) && y < (size_window*(2.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'J', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				if(y >= (size_window*(3.0/6)+20) && y < (size_window*(3.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'V', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				if(y >= (size_window*(4.0/6)+20) && y < (size_window*(4.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'B', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				if(y >= (size_window*(5.0/6)+20) && y < (size_window*(5.0/6)+20+cons) && x >= (size_window/4.0-40) && x < (size_window/4.0-40+cons))
				{
					modif_color(T, 'M', nbr_coups_max);
					nbr_coup++;
					flip = true;
				}
				// solveur
				/*
				if(y >= (size_window/2.0+100) && y < (size_window/2.0+100+cons) && x >= (size_window*(3/2.0)+80) && x < (size_window*(3/2.0)+80+cons))
				{	
					sprintf(solveur_info, "Solveur en cours...");
					texte1 = TTF_RenderUTF8_Blended(police, solveur_info, texteNoir);
					SDL_BlitSurface(texte1, NULL, ecran, &position1);
					SDL_Flip(ecran); 
				*/
					/*chemin = solveur_perf(T, size, &nbr_coups_min);*/
				/*
					SDL_FreeSurface(texte1);
				*/
					/*solveur_box(ecran,chemin,nbr_coups_min);*/
				/*
					sprintf(solveur_info, "Solution possible :");
					texte2 = TTF_RenderUTF8_Blended(police, solveur_info, texteNoir);
					SDL_BlitSurface(texte2, NULL, ecran, &position1);
					SDL_Flip(ecran);
					flip = true;
					free(chemin);
				}
				*/
				// bouton menu
				if(y >= 25 && y < (25+cons) && x >= size_window*(3/2.0)+40 && x < (size_window*(3/2.0)+40+cons))
				{
					*bouton = 1;
					exit = 1;
					break;
				}
				// bouton rejouer
				if(y >= 25 && y < (25+cons) && x >= size_window*(3/2.0)+135 && x < (size_window*(3/2.0)+135+cons))
				{
					*bouton = 2;
					exit = 1;
					break;
				}
	
			}
			break;

			case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				*out = 1;
				continuer = 0;
				break;

				default:
				break;
			}
		}

		if (flip)
		{
			flip = false;
			sprintf(nbr_coup_texte, "%d/%d", nbr_coup, nbr_coups_max);
			texte = TTF_RenderUTF8_Shaded(police, nbr_coup_texte, texteNoir, fondBlanc);
			SDL_BlitSurface(texte, NULL, ecran, &position);
			display_SDL(ecran, T, size,size_window,border_flag);
			SDL_Flip(ecran);
			SDL_FreeSurface(texte);
		}
	}
	return nbr_coup;
}

void end_game(SDL_Surface *ecran, matrix T, int size, int nbr_coup, int nbr_coups_max, TTF_Font *police)
{
	SDL_Color texteNoir = {0, 0, 0, 42};

	SDL_Surface *texte = NULL;
	SDL_Rect position;

	if (victoire(T, size, nbr_coup, nbr_coups_max) == 2)
	{
		texte = TTF_RenderUTF8_Blended(police, "GAME OVER", texteNoir);
		position.x = 350;
		position.y = 230;
		SDL_BlitSurface(texte, NULL, ecran, &position);
		SDL_Flip(ecran);
		sleep(4);
	}
	if (victoire(T, size, nbr_coup, nbr_coups_max) == 0)
	{
		texte = TTF_RenderUTF8_Blended(police, "WIN", texteNoir);
		position.x = 450;
		position.y = 230;
		SDL_BlitSurface(texte, NULL, ecran, &position);
		SDL_Flip(ecran);
		sleep(2);
	}
	SDL_FreeSurface(texte);
}



