#include "menu.h"


void initialiser_imageBackground(image *imgbtn)
{
imgbtn-> url="Menu_images/BackgroundPlay.png";
	imgbtn->img=IMG_Load(imgbtn->url);
	if(imgbtn->img == NULL)
	{
		printf("unable to load menu button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=50;
	imgbtn->pos_img_affiche.y=50;
	imgbtn->pos_img_affiche.h=700;
	imgbtn->pos_img_affiche.w=1200;
	imgbtn->pos_img_ecran.x=0;
	imgbtn->pos_img_ecran.y=0;

}
void initialiser_imageBACK(animated *ani)
{
	int i;
	for (i=1;i<34;i++)
	{	
		char ch[30]="";
		sprintf(ch,"animatedBackground/%d.bmp",i);
		ani->images3[i]=IMG_Load(ch);
	}
	ani->pos_img_ecran.x=30;
	ani->pos_img_ecran.y=0;
	ani->pos_img_affiche.x=0;
	ani->pos_img_affiche.y=0;
	ani->pos_img_affiche.h=700;
	ani->pos_img_affiche.w=1200;
}

void initialiser_imageBACKsettings(animated *ani)
{
	int i;
	for (i=1;i<9;i++){	
		char ch[40]="";
		sprintf(ch,"animatedBackgroundSETTINGS/%d.png",i);
		ani->images3[i]=IMG_Load(ch);
}
	ani->pos_img_ecran.x=300;
	ani->pos_img_ecran.y=150;
	ani->pos_img_affiche.x=0;
	ani->pos_img_affiche.y=0;
	ani->pos_img_affiche.h=400;
	ani->pos_img_affiche.w=600;
}

void free_back(animated ani)
{
	for(int i=1;i<34;i++)
	SDL_FreeSurface(ani.images3[i]);

}

void free_settings(animated ani)
{
	for(int i=1;i<9;i++)
	SDL_FreeSurface(ani.images3[i]);

}

void initialiser_imageBOUTON1(button *imgbtn)
{
	imgbtn->T[0]=SDL_LoadBMP("Menu_images/play.bmp");
	imgbtn->T[1]=SDL_LoadBMP("Menu_images/play2.bmp");
	imgbtn->state = 0;
	if(imgbtn->T[0] == NULL && imgbtn->T[1] == NULL )
	{
		printf("unable to load play button image %s\n",SDL_GetError());
		return;	
	}
		
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=150;
	imgbtn->pos_img_affiche.w=150;
	imgbtn->pos_img_ecran.x=100;
	imgbtn->pos_img_ecran.y=SCREEN_H/4+50;
}

void initialiser_imageBOUTON2(button *imgbtn)
{
	imgbtn->T[0]=SDL_LoadBMP("Menu_images/quit.bmp");
	imgbtn->T[1]=SDL_LoadBMP("Menu_images/quit2.bmp");
	imgbtn->state = 0;
	if(imgbtn->T[0] == NULL && imgbtn->T[1] == NULL )
	{
		printf("unable to load quit button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=150;
	imgbtn->pos_img_affiche.w=150;
	imgbtn->pos_img_ecran.x=100;
	imgbtn->pos_img_ecran.y=SCREEN_H-175;
}
void initialiser_imageBOUTON3(button *imgbtn)
{
	imgbtn->T[0]=SDL_LoadBMP("Menu_images/settings.bmp");
	imgbtn->T[1]=SDL_LoadBMP("Menu_images/settings2.bmp");
	imgbtn->state = 0;
	if(imgbtn->T[0] == NULL && imgbtn->T[1] == NULL )
	{
		printf("unable to load settings button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=150;
	imgbtn->pos_img_affiche.w=150;
	imgbtn->pos_img_ecran.x=100;
	imgbtn->pos_img_ecran.y=SCREEN_H/2+25;
}
void initialiser_squareaudio(image *imgbtn)
{
	imgbtn-> url="Menu_images/soundSquare.png";
	imgbtn->img=IMG_Load(imgbtn->url);
	if(imgbtn->img == NULL)
	{
		printf("unable to load menu button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=100;
	imgbtn->pos_img_affiche.w=430;
	imgbtn->pos_img_ecran.x=800;
	imgbtn->pos_img_ecran.y=263;
}
void initialiser_fullscreenbutton(image *imgbtn)
{
	imgbtn-> url="Menu_images/FULLSCREEN.png";
	imgbtn->img=IMG_Load(imgbtn->url);
	if(imgbtn->img == NULL)
	{
		printf("unable to load menu button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=100;
	imgbtn->pos_img_affiche.w=430;
	imgbtn->pos_img_ecran.x=610;
	imgbtn->pos_img_ecran.y=360;
}
void initialiser_quitSETTINGS(image *imgbtn)
{
	imgbtn-> url="Menu_images/quitSETTINGS.png";
	imgbtn->img=IMG_Load(imgbtn->url);
	if(imgbtn->img == NULL)
	{
		printf("unable to load menu button image %s\n",SDL_GetError());
		return;	
	}
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=100;
	imgbtn->pos_img_affiche.w=430;
	imgbtn->pos_img_ecran.x=795;
	imgbtn->pos_img_ecran.y=150;
}
void afficher_image(SDL_Surface *screen, image imge)
{
	SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN(SDL_Surface *screen, button imge)
{
	
	switch(imge.state)
	{
		case 0:
		SDL_BlitSurface(imge.T[0], NULL, screen, &imge.pos_img_ecran);
		break;
		case 1:
		SDL_BlitSurface(imge.T[1], NULL, screen, &imge.pos_img_ecran);
		break;
	}
	
}
void liberer_image(image imge)
{	
	SDL_FreeSurface(imge.img);
}

void liberer_image1(button imge)
{
	SDL_FreeSurface(imge.T[0]);
	SDL_FreeSurface(imge.T[1]);
}

void initialize_audio(Mix_Music *music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024) == -1)
	{
		printf("%s",SDL_GetError());	
	}
	music = Mix_LoadMUS("Menu_images/song.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
void liberer_musique(Mix_Music *music)
{
	Mix_FreeMusic(music);
}


void liberer_audiobref(Mix_Chunk *mus)
{
	Mix_FreeChunk(mus);
}

void initialize_texte(texte *txte)
{
	txte->police = TTF_OpenFont("Menu_images/Nexa-XBold.ttf", 55 );
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=255;
	txte->pos_txt.x=100;
	txte->pos_txt.y=100;
	
}

void show_text(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Maya VS the world", txte.color_txt);
	SDL_BlitSurface(txte.txt, NULL,screen, &txte.pos_txt);
}

void free_text(texte txte)
{
	TTF_CloseFont(txte.police);
	TTF_Quit();
}
