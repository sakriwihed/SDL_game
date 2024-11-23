/**
* @file lot6.h
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for lot6 scrollilng
*
*/
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>


typedef struct Image
{
    SDL_Rect posfromimg;  
    SDL_Rect posinscreen; 
    SDL_Surface *img;     
} Image;


 typedef struct Enigme_image
{
    int  solution; 
    int solved;
    char enigmeimg[256];
    Image backgroundenigme, question;
    Image won, lost;
 } Enigme_image;
 
 
 
 typedef struct input
{
int up[2];
int down[2];
int right[2];
int left[2];
Image background_input,curseur;
 
 } input;



void displayenigma(Enigme_image p, SDL_Surface * screen);

void puzzlegenerate (Enigme_image *p);
 
 void affiche_image(Image c,SDL_Surface *screen);
void afficher_menu_input(input c,SDL_Surface *screen);
int intersection_souris(SDL_Rect poscarre,int mousex,int mousey);
void affichage_keybind_name(SDL_Surface *screen,int rep1,int rep2,int rep3,int right,int left,int forward,int back,int screen_num);

void initialisation_background_input(input *c);
