#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_joystick.h>
#include <string.h>
#define SCREEN_H 700
#define SCREEN_W 1200


/**
* @struct text
* @brief struct for player text
*/
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect textpos; 
	SDL_Color textColor;
	TTF_Font *font;
}text;

/**
* @struct player
* @brief struct for player
*/
typedef struct
{
	SDL_Rect pos_display;
	SDL_Rect pos_screen;
	SDL_Surface *img[4][4];
	int direction,up, score, lives, anim,frameCount, dx;
	double speed, acceleration,spd_y;
	text t;
}player;

void initPlayer(player *p);
void initPlayer2(player *p);
void displayPlayer(player p, SDL_Surface *screen);
void movePlayer(player *p, Uint32 dt);
void movePlayer2(player *p,Uint32 dt);
void movePlayer3(player *p,Uint32 dt);
void animatePlayer(player *p);
void jump(player *p);

#endif