#include "ennemi.h"

void initEnnemi(Ennemi*e)
{
    e->sprite = IMG_Load("enemi.png");

    e->posScreen.x = 400;
    e->posScreen.y = 560;
    e->posScreen.h = 128;
    e->posScreen.w = 103;

    e->posSprite.x = 0;
    e->posSprite.y = 0;
    e->posSprite.w = 128;
    e->posSprite.h = 103;

    e->state = WAITING;

    e->direction = 0;

    e->posmax = 695;
    e->posmin = 484;
}

void afficherEnnemi(Ennemi *e, SDL_Surface *screen)
{
 
    SDL_BlitSurface(e->sprite, &e->posSprite, screen, &e->posScreen);
}
void animerEnnemi(Ennemi *e)
{
    e->posSprite.y = 103 * e->direction;

    if (e->posSprite.x >= 640)
        e->posSprite.x = 0;

    e->posSprite.x += 128;
}
void move(Ennemi *E)
{

    
    if (E->posScreen.x > E->posmax)
        E->direction = 2;
    if (E->posScreen.x < E->posmin)
        E->direction = 0;
    
     
    if (E->direction == 0)
        E->posScreen.x += 2;

    else if (E->direction == 2)
        E->posScreen.x -= 2;
}
void moveEnnemi(Ennemi *E, SDL_Rect posperso)
{
    if (E->posScreen.x > posperso.x)
    {
        E->posScreen.x -= 2;
    }
    if (E->posScreen.x < posperso.x)
    {
        E->posScreen.x = E->posScreen.x + 3;
    }
}
void updateEnnemiState(Ennemi *E, int dist)
{
    if (dist > 150)
        E->state = WAITING;
    else if ((50 < dist) && (dist < 150))
        E->state = FOLLOWING;
    else if ((0 < dist) && (dist < 50))
        E->state = ATTACKING;
}
void moveIA(Ennemi *E, SDL_Rect posperso)
{

    switch (E->state)
    {
    case WAITING:
       
        move(E);
        break;
    case FOLLOWING:
        
        if (E->posScreen.x > posperso.x)
            E->direction = 2;
        else
            E->direction = 0;
     
        moveEnnemi(E, posperso);

        break;

    case ATTACKING:
        
        if (E->direction == 2)
            E->direction = 3;
        else if (E->direction == 0)
            E->direction = 1;

        moveEnnemi(E, posperso);

        break;
    }
    
    int d;
    d = abs(E->posScreen.x - posperso.x);

    updateEnnemiState(E, d);
}
int collisionBB(Ennemi *E, SDL_Rect posPerso)
{

    if (E->posScreen.y > posPerso.y + posPerso.h) 
    {
        return 0;
    }
    if (E->posScreen.x > posPerso.x + posPerso.w) 
    {

        return 0;
    }
    if (E->posScreen.y + E->posScreen.h < posPerso.y) 
    {

        return 0;
    }
    if (E->posScreen.x + E->posScreen.w < posPerso.x) 
    {
        return 0;
    }

    return 1;
}

void freeEnnemi(Ennemi *e)
{
    SDL_FreeSurface(e->sprite);
}
