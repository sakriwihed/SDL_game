#include "player.h"


/**
* @file player.c
* @brief Testing Program.
* @author Janfaoui
* @version 0.1
* @date May 01, 2023
*
* functions file for player task
*
*/

/**
* @brief To initialize the player p.
* @param p player
* @return Nothing
*/
void initPlayer(player *p)
{
	int i,j,c=1;
	char ch[30];
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++)
		{
			sprintf(ch,"player/%d.png",c);
			p->img[i][j] = IMG_Load(ch);
			c++;
			if(p->img[i][j] == NULL)
			{
				printf("unable to load player image %s\n",SDL_GetError());
				return;	
			}
		}
	}
	p->anim=0;
	p->frameCount = 0;
	p->direction = 2;
	p->acceleration = 0.0;
	p->speed = 0.0;
	p->up =0;
	p->score = 0;
	p->lives = 3;
	p->pos_screen.x = 30;
	p->pos_screen.y = 460;
	p->pos_display.h = 150;
	p->pos_display.w = 120;
	p->pos_display.x = 0;
	p->pos_display.y = 0;
p->t.font = TTF_OpenFont("Menu_images/Nexa-XBold.ttf",30);
p->t.textColor.r=255;
p->t.textColor.g=0;
p->t.textColor.b=0;
p->t.textpos.x=10;
p->t.textpos.y=10;
}

/**
* @brief To initialize the second player p.
* @param p player
* @return Nothing
*/
void initPlayer2(player *p)
{
	int i,j,c=1;
	char ch[30];
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++)
		{
			sprintf(ch,"player/%d.png",c);
			p->img[i][j] = IMG_Load(ch);
			c++;
			if(p->img[i][j] == NULL)
			{
				printf("unable to load player image %s\n",SDL_GetError());
				return;	
			}
		}
	}
	p->anim=0;
	p->frameCount = 0;
	p->direction = 2;
	p->acceleration = 0.0;
	p->speed = 0.0;
	p->up =0;
	p->score = 0;
	p->lives = 3;
	p->pos_screen.x = 730;
	p->pos_screen.y = 460;
	p->pos_display.h = 150;
	p->pos_display.w = 120;
	p->pos_display.x = 0;
	p->pos_display.y = 0;
p->t.font = TTF_OpenFont("Menu_images/Nexa-XBold.ttf",30);
p->t.textColor.r=255;
p->t.textColor.g=0;
p->t.textColor.b=0;
p->t.textpos.x=610;
p->t.textpos.y=10;
}

/**
* @brief To display the player p.
* @param p player
* @param screen pointer to SDL_Surface
* @return Nothing
*/
void displayPlayer(player p, SDL_Surface *screen)
{
	SDL_BlitSurface(p.img[p.direction][p.anim], NULL, screen, &p.pos_screen);
	
	char ch[30];
	sprintf(ch,"score: %d lives: %d",p.score,p.lives);
	p.t.txt=TTF_RenderText_Blended(p.t.font,ch,p.t.textColor);
	SDL_BlitSurface(p.t.txt, NULL,screen, &p.t.textpos);
}

/**
* @brief To move the player p.
* @param p pointer to player
* @param dt unsingned integer
* @return Nothing
*/
void movePlayer(player *p,Uint32 dt)
{ 
if(p->pos_screen.x >470){ p->pos_screen.x = 470;}
if(p->pos_screen.x <0){ p->pos_screen.x = 0;}
    double new_speed = p->speed + p->acceleration * dt;
    if (new_speed < 0) new_speed = 0; 
    if (new_speed > 0.2) new_speed = 0.2;
    double dx = p->speed * dt + p->acceleration * dt * dt;
    p->pos_screen.x += dx;
    p->speed = new_speed;
    
    if( p->pos_screen.y>=180)
    {
    	p->pos_screen.y += p->spd_y;
    	p->pos_screen.x += dx*2;
    }
    
    else
		p->spd_y = (-p->spd_y)*2;
	 
	 p->pos_screen.y += p->spd_y;
    if(p->pos_screen.y>460) 
    { 
     p->pos_screen.y = 460;
     p->spd_y=0;
    }
}
void movePlayer2(player *p,Uint32 dt)
{ 
if(p->pos_screen.x >1080){ p->pos_screen.x = 1080;}
else if(p->pos_screen.x <700){ p->pos_screen.x = 700;}
    double new_speed = p->speed + p->acceleration * dt;
    if (new_speed < 0) new_speed = 0; 
    if (new_speed > 0.2) new_speed = 0.2;
    double dx = p->speed * dt + p->acceleration * dt * dt;
    p->pos_screen.x += dx;
    p->speed = new_speed;
    
    if( p->pos_screen.y>=180)
    {
    	p->pos_screen.y += p->spd_y;
    	p->pos_screen.x += dx*2;
    }
    
    else
		p->spd_y = (-p->spd_y)*2;
	 
	 p->pos_screen.y += p->spd_y;
    if(p->pos_screen.y>460) 
    { 
     p->pos_screen.y =460;
     p->spd_y=0;
    }
}

void movePlayer3(player *p,Uint32 dt)
{ 
if(p->pos_screen.x >1080){ p->pos_screen.x = 1080;}
if(p->pos_screen.x <0){ p->pos_screen.x = 0;}
    double new_speed = p->speed + p->acceleration * dt;
    if (new_speed < 0) new_speed = 0; 
    if (new_speed > 0.2) new_speed = 0.2;
    double dx = p->speed * dt + p->acceleration * dt * dt;
    p->pos_screen.x += dx;
    p->speed = new_speed;
    
    if( p->pos_screen.y>=180)
    {
    	p->pos_screen.y += p->spd_y;
    	p->pos_screen.x += dx*2;
    }
    
    else
		p->spd_y = (-p->spd_y)*2;
	 
	 p->pos_screen.y += p->spd_y;
    if(p->pos_screen.y>520) 
    { 
     p->pos_screen.y =460;
     p->spd_y=0;
    }
}

/**
* @brief jump for the player p.
* @param p pointer to player
* @return Nothing
*/
void jump(player *p)
{
        p->spd_y = -5.2;
}

/**
* @brief animate the player p.
* @param p pointer to player
* @return Nothing
*/
void animatePlayer(player *p)
{
    int animationSpeed = 15;

        p->frameCount++;
        if (p->frameCount >= animationSpeed) {
            p->anim++;
            if (p->anim == 4) p->anim = 0;
            p->frameCount = 0;
        }
    
}