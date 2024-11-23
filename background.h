#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#define SCREEN_H 700
#define SCREEN_W 1200

typedef struct
{
	SDL_Rect pos1; //fin theb taffichi el taswira
	SDL_Rect camera; //kadech theb twari mel taswira
	SDL_Surface *img;  //etaswira
	char ImgName[30]; //the name of the image
	int frameCount;
	
}backg;

typedef struct
{
	char playername[20];
	int score;
	int time;
}scoreinfo;


typedef struct
{
	SDL_Surface *button;
	SDL_Rect posButton;
}btn;

void initbackg(backg *back);
void initialiser_texte(text *txte);
void afficher(backg back,SDL_Surface *screen);

void animate_back(backg *b , SDL_Surface *screen);
void initialiser_audiobref(Mix_Music*music);
void scrolling (backg * b, int direction ); 
void init_btn(btn *b);
void display_btn(btn b, SDL_Surface *screen);
void bestScore(char *filename, scoreinfo tab[100],SDL_Surface *screen);
void showBestScore(scoreinfo t[], SDL_Surface *screen);
void screen_share(backg bg1,backg bg2,SDL_Surface *screen);
void initbackg2(backg *back);
#endif


