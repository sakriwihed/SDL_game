#ifndef MINIMAP_H
#define MINIMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "player.h"

typedef struct 
{	
	SDL_Surface *map ;
	SDL_Rect pos_map;
	SDL_Surface *miniplayer;
	SDL_Rect posminiplayer;

}minimap;

typedef struct{
SDL_Rect pos1,pos2;
SDL_Surface *img;
}IMAGE;


typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;

typedef struct{
    IMAGE  x,o,bk;
    int tabSuiv[10];
    int joueur ;
    int nbtour;
    TEXT txt;
    int w,h;
}TicTakTo;

/*typedef struct
{
  	SDL_Surface *player_image;
  	SDL_Rect pos_player;
}player;*/


void initmap (minimap *m) ;
void initmap1 (minimap *m);
void animatemap(minimap *m,SDL_Surface *screen);
void miniplayer(minimap *m,player *p);
void displaymap(minimap m, SDL_Surface *screen);
void freemap(minimap m);

SDL_Color getcolor(SDL_Surface *mask,int x,int y);
int collisionpp(player p, SDL_Surface * mask);
void collisionn(SDL_Surface *mask,player *p);

void initialiserTic (TicTakTo * t);
void afficherTic(TicTakTo t,SDL_Surface* ecran);
int atilgagne(int tabSuivi[]);
void Resultat (TicTakTo t,SDL_Surface* ecran);
void liberer( TicTakTo t);
int minmax(int tabSuivi[], int joueur);
void calcul_coup(int tabSuivi[]);


#endif












