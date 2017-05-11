#include "SDL.h"




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

SDL_Surface *regle(TTF_Font *police_texte,TTF_Font *police_colorflood,TTF_Font *police_regle, SDL_Surface *ecran, int *size)
{
	SDL_Color fondNoir = {0, 0, 0, 0}, texteBlanc = {255, 255, 255, 255};
	bool test=true;
	SDL_Event event;
	SDL_Surface *texte_1,*texte_2,*texte_3,*texte_4,*texte_5,*texte_6,*texte_7,*texte_8,*texte_9,*texte_10,*texte_11,
	*texte_12;
	SDL_Rect position_texte_1,position_texte_2,position_texte_3,position_texte_4,position_texte_5,position_texte_6,
	position_texte_7,position_texte_8,position_texte_9,position_texte_10,position_texte_11,position_texte_12;
	int taille_fenetre_regles = 600;
	ecran = SDL_SetVideoMode(taille_fenetre_regles, taille_fenetre_regles, 32, SDL_HWSURFACE); 
	SDL_WM_SetCaption("Regles du colorflood", NULL);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	position_texte_1.x= 200;
	position_texte_1.y= 0;
	position_texte_2.x= 0;
	position_texte_2.y= 50;
	position_texte_3.x= 0;
	position_texte_3.y= 100;
	position_texte_4.x= 0;
	position_texte_4.y= 150;
	position_texte_5.x= 0;
	position_texte_5.y= 180;
	position_texte_6.x= 0;
	position_texte_6.y= 230;
	position_texte_7.x= 0;
	position_texte_7.y= 260;
	position_texte_8.x= 0;
	position_texte_8.y= 310;
	position_texte_9.x= 0;
	position_texte_9.y= 340;
	position_texte_10.x= 0;
	position_texte_10.y= 370;
	position_texte_11.x= 175;
	position_texte_11.y= 470;
	position_texte_12.x= 175;
	position_texte_12.y= 500;




	texte_1 = TTF_RenderUTF8_Shaded(police_regle, "Regles Colorflood :",texteBlanc, fondNoir);
	texte_2 = TTF_RenderUTF8_Shaded(police_regle, "But : Toute la grille doit être de la même couleur",texteBlanc, fondNoir);
	texte_3 = TTF_RenderUTF8_Shaded(police_regle, "--> Votre couleur de départ est celle en haut à gauche.",texteBlanc, fondNoir);
	texte_4 = TTF_RenderUTF8_Shaded(police_regle, "--> Choisissez une couleur en cliquant sur les carrés de ",texteBlanc, fondNoir);
	texte_5 = TTF_RenderUTF8_Shaded(police_regle, "couleurs en bas de la grille",texteBlanc, fondNoir);
	texte_6 = TTF_RenderUTF8_Shaded(police_regle, "--> Les cases voisines horizontalement et verticalement ",texteBlanc, fondNoir);
	texte_7 = TTF_RenderUTF8_Shaded(police_regle, "à vous prennent alors cette couleur choisie.",texteBlanc, fondNoir);
	texte_8 = TTF_RenderUTF8_Shaded(police_regle, "--> Repeter ceci jusqu'à avoir la grille d'une seule couleur",texteBlanc, fondNoir);
	texte_9 = TTF_RenderUTF8_Shaded(police_regle, "mais attention car vous avez un nombre limité de coup !!!",texteBlanc, fondNoir);
	texte_10 = TTF_RenderUTF8_Shaded(police_regle, "(voir sur le coté droit de la grille)",texteBlanc, fondNoir);
	texte_11 = TTF_RenderUTF8_Shaded(police_regle, "Pour revenir au menu quittez cette page",texteBlanc, fondNoir);
	texte_12 = TTF_RenderUTF8_Shaded(police_regle, "(croix en haut à droite)",texteBlanc, fondNoir);


	

	SDL_Flip(ecran);
	SDL_BlitSurface(texte_1, NULL, ecran, &position_texte_1);
	SDL_BlitSurface(texte_2, NULL, ecran, &position_texte_2);
	SDL_BlitSurface(texte_3, NULL, ecran, &position_texte_3);
	SDL_BlitSurface(texte_4, NULL, ecran, &position_texte_4);
	SDL_BlitSurface(texte_5, NULL, ecran, &position_texte_5);
	SDL_BlitSurface(texte_6, NULL, ecran, &position_texte_6);
	SDL_BlitSurface(texte_7, NULL, ecran, &position_texte_7);
	SDL_BlitSurface(texte_8, NULL, ecran, &position_texte_8);
	SDL_BlitSurface(texte_9, NULL, ecran, &position_texte_9);
	SDL_BlitSurface(texte_10, NULL, ecran, &position_texte_10);
	SDL_BlitSurface(texte_11, NULL, ecran, &position_texte_11);
	SDL_BlitSurface(texte_12, NULL, ecran, &position_texte_12);
	SDL_Flip(ecran);
	

	do 
	{
		SDL_WaitEvent(&event);
		switch (event.type)
			{
				case SDL_QUIT:
				test = false;
				break;
			}

	}while(test==true);
	
	ecran = menu(police_texte, police_colorflood, police_regle, size);
	return ecran;
	
	

}


SDL_Surface *menu(TTF_Font *police_texte, TTF_Font *police_colorflood, TTF_Font *police_regle, int *size)
{
	SDL_Color fondNoir = {0, 0, 0, 0}, texteBlanc = {255, 255, 255, 255};
	SDL_Surface *ecran,*texte_regle, *c, *o_1, *o_2, *o_3, *o_4, *l_1, *l_2, *r, *f, *d, *taille_jeu, *icone_plus, *icone_moins, *icone_jouer;
	SDL_Event event;
	SDL_Rect position_c, position_o_1, position_l_1, position_o_2, position_r, position_f, position_l_2, position_o_3, position_o_4, position_d, position_taille_jeu;
	SDL_Rect position_plus, position_moins, position_jouer,position_regle;
	SDL_Color couleur_texte_W = {255, 255, 255, 42}, couleur_texte_1 = {220, 0, 220, 50}, couleur_texte_2 = {200, 200, 10, 80},
	couleur_texte_3 = {20, 180, 180, 120}, couleur_texte_4 = {160, 50, 160, 150}, couleur_texte_5 = {0, 140, 140, 180};

	bool flip = true;
	int continuer = 1, compteur = 3;
	char compteur_txt[50];


	position_c.x = 175;
	position_c.y = 50;
	position_o_1.x = 228;
	position_o_1.y = 50;
	position_l_1.x = 275;
	position_l_1.y = 50;
	position_o_2.x = 310;
	position_o_2.y = 50;
	position_r.x = 360;       //lettres de ColorFlood
	position_r.y = 50;
	position_f.x = 425;
	position_f.y = 50;
	position_l_2.x = 475;
	position_l_2.y = 50;
	position_o_3.x = 505;
	position_o_3.y = 50;
	position_o_4.x = 550;
	position_o_4.y = 50;
	position_d.x = 595;
	position_d.y = 50;
	position_taille_jeu.x = 330;
	position_taille_jeu.y = 313;

	RGB J = {255, 255, 102}; //Jaune


	position_plus.x = 500;
	position_plus.y = 300;
	position_moins.x = 250;
	position_moins.y = 300;
	position_jouer.x = 290;
	position_jouer.y = 450;
	position_regle.x=560;
	position_regle.y=620;
	

	int taille_fenetre = 800;
	ecran = SDL_SetVideoMode(taille_fenetre, taille_fenetre, 32, SDL_HWSURFACE); /*fenêtre au début à cette taille par défaut*/
	SDL_WM_SetCaption("Menu : Choisissez la taille du jeu", NULL); //nom de la fenêtre

	texte_regle = TTF_RenderUTF8_Shaded(police_texte, "Voir regles", texteBlanc, fondNoir);
	c = TTF_RenderUTF8_Blended(police_colorflood, "C", couleur_texte_1);
	o_1 = TTF_RenderUTF8_Blended(police_colorflood, "o", couleur_texte_2);
	l_1 = TTF_RenderUTF8_Blended(police_colorflood, "l", couleur_texte_3);
	o_2 = TTF_RenderUTF8_Blended(police_colorflood, "o", couleur_texte_4);
	r = TTF_RenderUTF8_Blended(police_colorflood, "r", couleur_texte_5);
	f = TTF_RenderUTF8_Blended(police_colorflood, "F", couleur_texte_1);
	l_2 = TTF_RenderUTF8_Blended(police_colorflood, "l", couleur_texte_2);
	o_3 = TTF_RenderUTF8_Blended(police_colorflood, "o", couleur_texte_3);
	o_4 = TTF_RenderUTF8_Blended(police_colorflood, "o", couleur_texte_4);
	d = TTF_RenderUTF8_Blended(police_colorflood, "d", couleur_texte_5);

	icone_plus = SDL_LoadBMP("img/plus.bmp");
	icone_moins = SDL_LoadBMP("img/moins.bmp");      //telechargement des images 
	icone_jouer = SDL_LoadBMP("img/finalplay.bmp");

	while(continuer)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				*size = 0;
				continuer = 0;
				break;

				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:	/*touche échap*/
					*size = 0;
					continuer = 0;
					break;
					default:
					break;
				}

				case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) //clique gauche
				{
					int x = event.button.x;
					int y = event.button.y;
					if(y >= 300 && y < 344)
					{
						if(x >= 500 && x < 544 && compteur < 24)
							compteur++;
						else if(x >= 250 && x < 294 && compteur > 3)
							compteur--;
						flip = true;
					}
					else if(x >= 290 && x < 490 && y >= 450 && y < 650)
					{
						*size = compteur;
						continuer = 0;
					}

					else if(x>= 600 && x<= 700 && y>=500 && y<=600)
					{
						SDL_Flip(ecran);
						ecran = regle(police_texte,police_colorflood,police_regle, ecran, size);
						continuer=0;
						SDL_Flip(ecran);

						
					}
				}
			}
		}

		if(flip)
		{
			flip = false;
			SDL_Flip(ecran);
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); //fond noir
			sprintf(compteur_txt, "Taille : %2d", compteur);
			taille_jeu = TTF_RenderUTF8_Blended(police_texte, compteur_txt, couleur_texte_W);
			SDL_BlitSurface(texte_regle, NULL, ecran, &position_regle);
			SDL_BlitSurface(c, NULL, ecran, &position_c);
			SDL_BlitSurface(o_1, NULL, ecran, &position_o_1);
			SDL_BlitSurface(l_1, NULL, ecran, &position_l_1);
			SDL_BlitSurface(o_2, NULL, ecran, &position_o_2);
			SDL_BlitSurface(r, NULL, ecran, &position_r);
			SDL_BlitSurface(f, NULL, ecran, &position_f);
			SDL_BlitSurface(l_2, NULL, ecran, &position_l_2);
			SDL_BlitSurface(o_3, NULL, ecran, &position_o_3);
			SDL_BlitSurface(o_4, NULL, ecran, &position_o_4);
			SDL_BlitSurface(d, NULL, ecran, &position_d);
			SDL_BlitSurface(taille_jeu, NULL, ecran, &position_taille_jeu);
			SDL_BlitSurface(icone_plus, NULL, ecran, &position_plus);
			SDL_BlitSurface(icone_moins, NULL, ecran, &position_moins);
			SDL_BlitSurface(icone_jouer, NULL, ecran, &position_jouer);
			drawRectangle(ecran, 500, 600, 100, J);
			SDL_Flip(ecran);

		}

	}
	SDL_FreeSurface(c);
	SDL_FreeSurface(o_1);
	SDL_FreeSurface(o_2);
	SDL_FreeSurface(o_3);
	SDL_FreeSurface(o_4);
	SDL_FreeSurface(l_1);
	SDL_FreeSurface(l_2);
	SDL_FreeSurface(r);
	SDL_FreeSurface(f);
	SDL_FreeSurface(d);
	SDL_FreeSurface(taille_jeu);
	SDL_FreeSurface(icone_plus);
	SDL_FreeSurface(icone_moins);
	SDL_FreeSurface(icone_jouer);
	SDL_FreeSurface(texte_regle);
	return ecran;
}


void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima) {
	SDL_Rect rect;
    rect.x=px;
    rect.y=py;
	SDL_BlitSurface(ima, NULL, ecran, &rect);
	SDL_Flip(ecran);
}

SDL_Surface *initialize_screen(int taille_fenetre)
{

	SDL_Surface *ecran = NULL;
	RGB init_screen = {0,0,0};	/*Fond d'écran noir*/		

	ecran = SDL_SetVideoMode(2*taille_fenetre, taille_fenetre+120, 8, SDL_HWSURFACE);
	SDL_WM_SetCaption("ColorFlood", NULL); // nom donné à la fenêtre

	/*
	SDL_Surface *img=SDL_LoadBMP("home.bmp");
    drawTexture(ecran, 50, 50, img);
    SDL_FreeSurface(img);
    */
	
	fillScreen(ecran, init_screen); //rend l'écran noir
	
	return ecran;
}

void texte(SDL_Surface *ecran, TTF_Font *police, TTF_Font *police_coup)
{
	SDL_Rect position1,position2,position3;
	SDL_Rect position_menu, position_rejouer;
	SDL_Color fondNoir = {0, 0, 0, 0}, texteBlanc = {255, 255, 255, 255};
	SDL_Surface *texte1,*texte2,*texte3;
	SDL_Surface *menu, *rejouer;

	texte1 = TTF_RenderUTF8_Shaded(police, ": Couleur à choisir", texteBlanc, fondNoir);
	texte2 = TTF_RenderUTF8_Shaded(police, "Aide ", texteBlanc, fondNoir);
	texte3 = TTF_RenderUTF8_Shaded(police_coup, "Coup(s) Restant(s) : ", texteBlanc, fondNoir);
	menu = TTF_RenderUTF8_Shaded(police, "Menu", texteBlanc, fondNoir);
	rejouer = TTF_RenderUTF8_Shaded(police, "Rejouer", texteBlanc, fondNoir);

	position1.x = 600;
	position1.y = 570;
	position2.x = 885;
	position2.y = 560;
	position3.x = 500*(3/2.0)-110;
	position3.y = 500/2.0;

	position_menu.x = 672;
	position_menu.y = 127;
	position_rejouer.x = 865;
	position_rejouer.y = 127;

	SDL_BlitSurface(texte1, NULL, ecran, &position1);
	SDL_BlitSurface(texte2, NULL, ecran, &position2);
	SDL_BlitSurface(texte3, NULL, ecran, &position3);
	SDL_BlitSurface(menu, NULL, ecran, &position_menu);
	SDL_BlitSurface(rejouer, NULL, ecran, &position_rejouer);
	
	SDL_FreeSurface(texte1);
	SDL_FreeSurface(texte2);
	SDL_FreeSurface(texte3);
	SDL_FreeSurface(menu);
	SDL_FreeSurface(rejouer);
}

void couleur_a_choisir(SDL_Surface *ecran,int taille_fenetre)
{
	SDL_Surface *image_aide,*image_menu,*image_rejouer;
	SDL_Rect position_aide;
	SDL_Rect position_menu;
	SDL_Rect position_rejouer;

	position_aide.x = taille_fenetre*(3/2.0)+120;
	position_aide.y = taille_fenetre/2.0+225;
	position_menu.x = taille_fenetre*(3/2.0)-100;
	position_menu.y = 25;
	position_rejouer.x = taille_fenetre*(3/2.0)+100;
	position_rejouer.y = 25;

	image_aide = SDL_LoadBMP("img/ide.bmp");
	image_menu = SDL_LoadBMP("img/menu.bmp");
	image_rejouer = SDL_LoadBMP("img/rejouer.bmp");

	RGB J = {255, 255, 102}; //Jaune
	RGB R = {255, 20, 20 };  //Rouge
	RGB G = {96, 96, 96}; //Gris
	RGB V = {0, 102, 0}; //Vert
	RGB B = {30,30,150}; //Bleu
	RGB M = {102, 0, 51}; //Magenta
	drawRectangle(ecran, 553, 25, (taille_fenetre-40)/7, G);
	drawRectangle(ecran, 553, 125, (taille_fenetre-40)/7, R);
	drawRectangle(ecran, 553, 225, (taille_fenetre-40)/7, J);
	drawRectangle(ecran, 553, 325, (taille_fenetre-40)/7, V);
	drawRectangle(ecran, 553, 425, (taille_fenetre-40)/7, B);
	drawRectangle(ecran, 553, 525, (taille_fenetre-40)/7, M);
	SDL_BlitSurface(image_aide, NULL, ecran, &position_aide);
	SDL_BlitSurface(image_menu, NULL, ecran, &position_menu);
	SDL_BlitSurface(image_rejouer, NULL, ecran, &position_rejouer);	
	SDL_FreeSurface(image_aide);
	SDL_FreeSurface(image_menu);
	SDL_FreeSurface(image_rejouer);
}


void display_SDL(SDL_Surface *ecran, matrix T, int size, int taille_fenetre, bool separation)
{
	RGB J = {255, 255, 102}; //Jaune
	RGB R = {255, 20, 20};  //Rouge
	RGB G = {96, 96, 96}; //Gris
	RGB V = {0, 102, 0}; //Vert
	RGB B = {30,30,150}; //Bleu
	RGB M = {102, 0, 51}; //Magenta
	int i, j;
	char couleur;

	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			couleur = T[i][j];
			if(separation==false) //carré du jeu non collé
				switch (couleur)
				{
					case 'B':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5, (j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, B);
					break;

					case 'V':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5, (j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, V);
					break;

					case 'R':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5, (j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, R);
					break;

					case 'J':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5, (j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, J);
					break;

					case 'M':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5, (j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, M);
					break;

					case 'G':
					drawRectangle(ecran, (i*taille_fenetre/size+10+i*2)-5,(j*taille_fenetre/size+taille_fenetre*(1.0/2)+j*2-size)-200, taille_fenetre/size, G);
					break;
				}
			else //carré du jeu collé
				switch (couleur)
				{
					case 'B':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, B);
					break;

					case 'V':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, V);
					break;

					case 'R':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, R);
					break;

					case 'J':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, J);
					break;

					case 'M':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, M);
					break;

					case 'G':
					drawRectangle(ecran, i*taille_fenetre/size+10, j*taille_fenetre/size+taille_fenetre*(1.0/2)-size, taille_fenetre/size+taille_fenetre%size, G);
					break;
				}
		}
	}
	SDL_Flip(ecran);
}

int boucle_jeu(SDL_Surface *ecran, matrix T, int size, int nb_coup_max, char *nbr_coup_texte, TTF_Font *police, int taille_fenetre, bool separation, int* bouton, int* out)
{
	int continuer = 1, nbr_coup = 0, exit = 0;
	SDL_Surface *texte;
	SDL_Event event;
	SDL_Color fondNoir = {0, 0, 0, 42}, texteBlanc = {255, 255, 255, 42};
	SDL_Rect position;

	position.x = 500*(3/2.0)+40;
	position.y = 500/2.0+70;
	




	couleur_a_choisir(ecran,taille_fenetre); //disposition des couleurs pouvant être choisies
	
	bool flip = true;
	while(victoire(T, size, nbr_coup, nb_coup_max) != 0 && victoire(T, size, nbr_coup, nb_coup_max) != 2 
		&& continuer && exit == 0) //tant que le jeu continu
	{
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
				int cons=(taille_fenetre-40)/5;

				if((y >= 553) && (y <= 619)) //position case grise
				{
					if((x>= 25) && (x<=91))
					{
						modif_color(T, 'G', size);
						nbr_coup++;
						flip = true;
					}
					if((x>= 125) && (x<=191)) //rouge
					{
						modif_color(T, 'R', size);
						nbr_coup++;
						flip = true;
					}
					if((x>= 225) && (x<=291)) //jaune
					{
						modif_color(T, 'J', size);
						nbr_coup++;
						flip = true;
					}
					if((x>= 325) && (x<=391)) //vert
					{
						modif_color(T, 'V', size);
						nbr_coup++;
						flip = true;
					}
					if((x>= 425) && (x<=491)) //bleu
					{
						modif_color(T, 'B', size);
						nbr_coup++;
						flip = true;
					}
					if((x>= 525) && (x<=591)) //magenta
					{
						modif_color(T, 'M', size);
						nbr_coup++;
						flip = true;
					}
				}
				// solveur
				/*
				if(y >= (taille_fenetre/2.0+100) && y < (taille_fenetre/2.0+100+cons) && x >= (taille_fenetre*(3/2.0)+80) && x < (taille_fenetre*(3/2.0)+80+cons))
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

				//menu
		
				if(y >= 25 && y < (25+cons) && x >= taille_fenetre*(3/2.0)-100 && x < (taille_fenetre*(3/2.0)-100+cons))
				{
					*bouton = 1;
					exit = 1;
					break;
				}
				//rejouer
				if(y >= 25 && y < (25+cons) && x >= taille_fenetre*(3/2.0)+100 && x < (taille_fenetre*(3/2.0)+100+cons))
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
			SDL_Flip(ecran);
			SDL_FillRect(ecran, &position , SDL_MapRGB(ecran->format, 0, 0, 0));
			sprintf(nbr_coup_texte, "%d", nb_coup_max-nbr_coup);
			texte = TTF_RenderUTF8_Shaded(police, nbr_coup_texte, texteBlanc, fondNoir);
			SDL_BlitSurface(texte, NULL, ecran, &position);
			display_SDL(ecran, T, size,taille_fenetre,separation);
			SDL_Flip(ecran);
			SDL_FreeSurface(texte);
		}

	}
	return nbr_coup;
}

void fin_jeu(SDL_Surface *ecran, matrix T, int size, int nbr_coup, int nb_coup_max, TTF_Font *police)
{
	SDL_Color texteBlanc = {255, 255, 255, 42};

	SDL_Surface *texte = NULL, *image_gameover;
	SDL_Rect position;

	SDL_Rect position_gameover;

	position_gameover.x = 48;
	position_gameover.y = 5;

	image_gameover = SDL_LoadBMP("img/game-over.bmp");

	if (victoire(T, size, nbr_coup, nb_coup_max) == 2) //defaite
	{
		SDL_BlitSurface(image_gameover, NULL, ecran, &position_gameover);
		SDL_Flip(ecran);
		sleep(4);
	}
	if (victoire(T, size, nbr_coup, nb_coup_max) == 0) //victoire
	{
		texte = TTF_RenderUTF8_Blended(police, "WIN", texteBlanc);
		position.x = 215;
		position.y = 230;
		SDL_BlitSurface(texte, NULL, ecran, &position);
		SDL_Flip(ecran);
		sleep(2);
	}
	SDL_FreeSurface(image_gameover);
	SDL_FreeSurface(texte);
}



