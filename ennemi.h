#ifndef H
#define H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

enum STATE
{
  WAITING,
  FOLLOWING,
  ATTACKING
};
typedef enum STATE STATE;
typedef struct
{
  SDL_Surface* sprite;
  SDL_Rect posSprite; 
  SDL_Rect posScreen; 
  int direction;
   int posmax;          
  int posmin;
 STATE state;
}Ennemi;

void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi *e, SDL_Surface  * screen);
void animerEnnemi( Ennemi * e);
int collisionBB(Ennemi *E, SDL_Rect posPerso);
void move( Ennemi * e); 
void moveIA(Ennemi *E, SDL_Rect posperso);
void updateEnnemiState(Ennemi *E, int dist);

void moveEnnemi(Ennemi *E, SDL_Rect posperso);

void freeEnnemi(Ennemi *e);

#endif
