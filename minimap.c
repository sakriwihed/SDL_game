#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "minimap.h"

void initmap (minimap *m)
{	
	m->map=IMG_Load("minim.bmp");
	m->pos_map.x = 700;
	m->pos_map.y = 10;
	
}
void initmap1 (minimap *m)
{	
	m->map=IMG_Load("minim.bmp");
	m->pos_map.x = 300;
	m->pos_map.y = 10;
	
}

void animatemap(minimap *m,SDL_Surface* screen)
{


SDL_FillRect(m->miniplayer,NULL,SDL_MapRGB(screen->format,255,20,0)); 

}

void displaymap(minimap m , SDL_Surface *screen)
{
	SDL_BlitSurface(m.map, NULL, screen,&m.pos_map);
	SDL_BlitSurface(m.miniplayer, NULL, screen,&m.posminiplayer);
}
void miniplayer(minimap *m,player *p)
{
	m->posminiplayer.x=p->pos_screen.x/3+10+m->pos_map.x; 
	m->posminiplayer.y=p->pos_screen.y/12+15+m->pos_map.y;
m->miniplayer=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
}

SDL_Color getcolor(SDL_Surface *mask,int x,int y) 
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char*) mask->pixels;
	pPosition+= (mask->pitch * y);
	pPosition+= (mask->format->BytesPerPixel *x); 
	memcpy(&col ,pPosition ,mask->format->BytesPerPixel);
	SDL_GetRGB(col,mask->format, &color.r, &color.g, &color.b);
	return (color);
}

int collisionpp(player p, SDL_Surface * mask)
{
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.pos_display.x;
	tabx[1]=(p.pos_display.x)+((p.pos_display.w)/2);
	tabx[2]=(p.pos_display.x+p.pos_display.w);
	tabx[3]=p.pos_display.x;
	tabx[4]=p.pos_display.x;
	tabx[5]=(p.pos_display.x)+((p.pos_display.w)/2);
	tabx[6]=(p.pos_display.x+p.pos_display.w);
	tabx[7]=(p.pos_display.x+p.pos_display.w);
	taby[0]=p.pos_display.y;
	taby[1]=p.pos_display.y;
	taby[2]=p.pos_display.y;
	taby[3]=(p.pos_display.y)+((p.pos_display.h)/2);
	taby[4]=(p.pos_display.y+p.pos_display.h);
	taby[5]=(p.pos_display.y+p.pos_display.h);
	taby[6]=(p.pos_display.y+p.pos_display.h);
	taby[7]=(p.pos_display.y)+((p.pos_display.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getcolor(mask,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;
	}
	}
	return 10;
}

void collisionn(SDL_Surface *mask,player*p)
{	int i;
	i=collisionpp(*p,mask);
	if(mask == NULL) {
        printf("Collision image is NULL.\n");
        
    }
	switch (i)
	{
		case 0 :p->pos_display.y=p->pos_display.y+20;
			break;
		case 1 :p->pos_display.y=p->pos_display.y+20;
			 break;
		case 2 :p->pos_display.y=p->pos_display.y+20;
			break;
		case 3 :p->pos_display.x=p->pos_display.x+20;
			break;
	        case 4 :p->pos_display.y=p->pos_display.y-20;
			break;
		case 5 :p->pos_display.y=p->pos_display.y-50; 
			break;
		case 6 :p->pos_display.y=p->pos_display.y-30; 
			break;
		case 7 :p->pos_display.x=p->pos_display.x-20;
			break;
		}
}

void freemap(minimap m)
{
	if (m.map == NULL) {
        return;
    }
    if (m.map != NULL) {
        SDL_FreeSurface(m.map );
        m.map  = NULL;
    }
    free(m.map );
    m.map  = NULL;
}

//TICTACTOE
void initialiserTic (TicTakTo * t){
    t->bk.img=IMG_Load("tic/b.png");
    t->o.img=IMG_Load("tic/o.png");
    t->x.img=IMG_Load("tic/x.png");

    t->bk.pos1.x=t->w/2-t->bk.img->w/2;
    t->bk.pos1.y=t->h/2-t->bk.img->h/2;

    for (int i = 0; i < 9; i++)
        t->tabSuiv[i]=0;

    t->txt.font=TTF_OpenFont("28 Days Later.ttf",60);
    t->txt.postxt.x=t->w-300;
    t->txt.postxt.y=t->h-400;
    t->txt.col.r=255;
    t->txt.col.g=255;
    t->txt.col.b=255;

    t->nbtour=0;
    t->joueur=1;
}

void afficherTic(TicTakTo t,SDL_Surface* ecran){
    SDL_BlitSurface(t.bk.img,NULL,ecran,&t.bk.pos1);
    int j=0;
    for(int i=0;i<9;i++){
        if(i>2&&i<6)
            j=1;
        else if(i>5&&i<9)
            j=2;
        if(t.tabSuiv[i]==-1){
            t.x.pos1.x=t.bk.pos1.x+(t.bk.img->w*(i%3))/3; 
            t.x.pos1.y=t.bk.pos1.y+(t.bk.img->h*j)/3;
            SDL_BlitSurface(t.x.img,NULL,ecran,&t.x.pos1);
        }
        else if(t.tabSuiv[i]==1){
            t.o.pos1.x=t.bk.pos1.x+(t.bk.img->w*(i%3))/3;
            t.o.pos1.y=t.bk.pos1.y+(t.bk.img->h*j)/3;
            SDL_BlitSurface(t.o.img,NULL,ecran,&t.o.pos1);
        }
    }
}


// 1 1 1 0 0 0 0 0 0
// -1 -1 -1 0 0 0 0 0 0

int atilgagne(int tabSuivi[]){
    int lGagnantes[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int gameStillOn=0;
    for(int i=0;i<8;i++){
        if(tabSuivi[lGagnantes[i][0]]==tabSuivi[lGagnantes[i][1]]&&tabSuivi[lGagnantes[i][1]]==tabSuivi[lGagnantes[i][2]])
            return tabSuivi[lGagnantes[i][0]];
    }
    //return -1;
}


void Resultat(TicTakTo t,SDL_Surface* ecran){
    char message[100];
    if(atilgagne(t.tabSuiv)==1)
        strcpy(message,"computer won");
    else if(atilgagne(t.tabSuiv)==-1)
        strcpy(message,"player won");
    else 
        strcpy(message,"t3adol");


    t.txt.windtxt= TTF_RenderText_Blended(t.txt.font,message,t.txt.col);
    SDL_BlitSurface(t.txt.windtxt,NULL,ecran,&t.txt.postxt);
}


int minmax(int tabSuivi[],int joueur){
    int gagnant = atilgagne(tabSuivi);
    if (gagnant != 0)
        return gagnant * joueur;
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (tabSuivi[i] == 0)
        {
        {
            tabSuivi[i] = joueur;
            int mmscore = -minmax(tabSuivi, joueur * -1);
            if (mmscore > score)
            {
            score == mmscore;
            coup = i;
            }
            tabSuivi[i] = 0;
        }
        }
    }
    if (coup == -1)
        return 0;
    return score;
}

void calcul_coup(int tabSuivi[]){
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (tabSuivi[i] == 0)
        {
        tabSuivi[i] = 1;
        int mmscore = -minmax(tabSuivi, -1);
        tabSuivi[i] = 0;
        if (mmscore > score)
        {
            score = mmscore;
            coup = i;
        }
        }
    }
    tabSuivi[coup] = 1;
}
