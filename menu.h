#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 700
#define SCREEN_W 1200

typedef struct
{
	char *url;
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran;
	SDL_Surface *img;
}image;

typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt; 
	SDL_Color color_txt;
	TTF_Font *police;
}texte;
typedef struct
{
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran;
	SDL_Surface *T[2];
	int state;
}button;


typedef struct 
{ 
	SDL_Surface *images3[34];
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran;
}animated;

void toggle_fullscreen(SDL_Surface *screen, button images[]);

void initialiser_imageBACK(animated *ani);
void initialiser_imageBACKsettings(animated *ani);
void initialiser_quitSETTINGS(image *imgbtn);
void initialiser_fullscreenbutton(image *imgbtn);

void initialiser_imageBOUTON1(button *imgbtn);
void initialiser_imageBOUTON2(button *imgbtn);
void initialiser_imageBOUTON3(button *imgbtn);
void initialiser_imageBackground(image *imgbtn);
void afficher_image(SDL_Surface *screen, image imge);
void afficher_imageBTN(SDL_Surface *screen, button imge);
void liberer_image(image imge);
void free_back(animated ani);
void free_settings(animated ani);
void liberer_image1(button imge);
void initialiser_squareaudio(image *imgbtn);

void initialize_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);

void liberer_audiobref(Mix_Chunk *mus);

void initialize_texte(texte *txte);
void show_text(SDL_Surface *screen, texte txte);
void free_text(texte txte);

#endif







