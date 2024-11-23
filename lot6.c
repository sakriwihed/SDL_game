/**
* @file lot6.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for lot6
*
*/

#include "lot6.h"

/**
* @brief To generate the puzzle .
* @param b Enigme_image *p
* @return Nothing
*/
void puzzlegenerate (Enigme_image *p)
{
	char ch[30];     // the future path of the puzzles image 
	char chnum[2];   // the conversion from decimal to string
	char chextention[5]; //the extention of the image to load 
	srand(time(NULL));               
	int numeroEnigme = ( rand() % 3)+1; 
	if (numeroEnigme == 1)
		p->solution =2;
	else if (numeroEnigme == 2)
		p->solution =3;
	else if (numeroEnigme == 3)
		p->solution =2;
	sprintf (chnum,"%d",numeroEnigme);
	strcpy (p->enigmeimg, "src_enigme_image/question");
	strcpy (chextention , ".png");
	strcat (p->enigmeimg,chnum);
	strcat (p->enigmeimg,chextention);
	
	printf("%s %d",p->enigmeimg,p->solution);
	
	  
	
	p->question.img = IMG_Load(p->enigmeimg);

	    if (p->question.img == NULL)
	    {
		fprintf(stderr, "error loding background img enigme%s\n", SDL_GetError());
		return;
	    }
	    p->question.posfromimg.h = p->question.img->h;
	    p->question.posfromimg.w = p->question.img->w;
	    p->question.posfromimg.x = 0;
	    p->question.posfromimg.y = 0;
	    p->question.posinscreen.h = p->question.img->h;
	    p->question.posinscreen.w = p->question.img->w;
	    p->question.posinscreen.x = 400;
	    p->question.posinscreen.y = 0;
	
	
	p->won.img = IMG_Load("src_enigme_image/winenigme.png");
	    if (p->won.img == NULL)
	    {
		fprintf(stderr, "error loding won img %s\n", SDL_GetError());
		return;
	    }

	    p->won.posfromimg.h = p->won.img->h;
	    p->won.posfromimg.w = p->won.img->w;
	    p->won.posfromimg.x = 0;
	    p->won.posfromimg.y = 0;

	    p->won.posinscreen.h = p->won.img->h;
	    p->won.posinscreen.w = p->won.img->w;
	    p->won.posinscreen.x = 400;
	    p->won.posinscreen.y = 0;
   	
   	p->lost.img = IMG_Load("src_enigme_image/lost.png");
	    if (p->lost.img == NULL)
	    {
		fprintf(stderr, "error loding lost img %s\n", SDL_GetError());
		return;
	    }

	    p->lost.posfromimg.h = p->lost.img->h;
	    p->lost.posfromimg.w = p->lost.img->w;
	    p->lost.posfromimg.x = 0;
	    p->lost.posfromimg.y = 0;

	    p->lost.posinscreen.h = p->lost.img->h;
	    p->lost.posinscreen.w = p->lost.img->w;
	    p->lost.posinscreen.x = 400;
	    p->lost.posinscreen.y = 0;
   	 
   	p->backgroundenigme.img = IMG_Load("src_enigme_image/background_enigme_imagee.png");
   	 if (p->backgroundenigme.img == NULL)
   	 {
        	fprintf(stderr, "error loding background img enigme%s\n", SDL_GetError());
        	return;
   	 }
    	p->backgroundenigme.posfromimg.h = p->backgroundenigme.img->h;
	 p->backgroundenigme.posfromimg.w = p->backgroundenigme.img->w;
	    p->backgroundenigme.posfromimg.x = 0;
	    p->backgroundenigme.posfromimg.y = 0;
	    p->backgroundenigme.posinscreen.h = p->backgroundenigme.img->h;
	    p->backgroundenigme.posinscreen.w = p->backgroundenigme.img->w;
	    p->backgroundenigme.posinscreen.x = 400;
	    p->backgroundenigme.posinscreen.y = 0;
   	
   	  
	
	
	     
	p->solved=0;
	
	
	
}
/**
* @brief To display image .
* @param b Image c, SDL_Surface *screen
* @return Nothing
*/ 
void affiche_image(Image c, SDL_Surface *screen)
{

    SDL_BlitSurface(c.img, &c.posfromimg, screen, &c.posinscreen);
}

/**
* @brief To display the puzzle.
* @param b Enigme_image p, SDL_Surface * screen
* @return Nothing
*/
void displayenigma(Enigme_image p, SDL_Surface * screen)
{
	affiche_image(p.backgroundenigme, screen);                    
        affiche_image(p.question, screen);         
}


/**
* @brief To display menu input .
* @param b input c, SDL_Surface *screen
* @return Nothing
*/
void afficher_menu_input(input c, SDL_Surface *screen)
{
    affiche_image(c.background_input, screen);printf("\nhello");

    c.curseur.posinscreen.x = 200;
    c.curseur.posinscreen.y = 271;
   
    if (c.up[0] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.down[0] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 82;
    if (c.right[0] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.left[0] == 1)
    {
        affiche_image(c.curseur, screen);
    }
    
    c.curseur.posinscreen.x = 307;

    c.curseur.posinscreen.y = 271;

    if (c.up[0] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.down[0] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 82;
    if (c.right[0] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.left[0] != 1)
    {
        affiche_image(c.curseur, screen);
    }
   




   
    c.curseur.posinscreen.x = 940;
    c.curseur.posinscreen.y = 271;

    if (c.up[1] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.down[1] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 82;
    if (c.right[1] == 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.left[1] == 1)
    {
        affiche_image(c.curseur, screen);
    }
    //
    c.curseur.posinscreen.x = 1047;

    c.curseur.posinscreen.y = 271;

    if (c.up[1] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.down[1] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 82;
    if (c.right[1] != 1)
    {
        affiche_image(c.curseur, screen);
    }

    c.curseur.posinscreen.y += 85;
    if (c.left[1] != 1)
    {
        affiche_image(c.curseur, screen);
    }
}

/**
* @brief To initialise the background .
* @param b input *c
* @return Nothing
*/
void initialisation_background_input(input *c)
{
    c->up[0] = 1;
    c->down[0] = 2;
    c->right[0] = 2;
    c->left[0] = 2;

    c->up[1] = 1;
    c->down[1] = 2;
    c->right[1] = 2;
    c->left[1] = 1;
    c->background_input.img = IMG_Load("src_enigme_image/BACKGROUND INPUT.png");
    if (c->background_input.img == NULL)
    {
        fprintf(stderr, "error loding lost img %s\n", TTF_GetError());
        return;
    }

    c->background_input.posfromimg.x = 0;
    c->background_input.posfromimg.y = 0;
    c->background_input.posfromimg.w = c->background_input.img->w;
    c->background_input.posfromimg.h = c->background_input.img->h;

    c->background_input.posinscreen.x = 400;
    c->background_input.posinscreen.y = 0;
    c->curseur.img = IMG_Load("src_enigme_image/CURSEUR.png");
    c->curseur.posfromimg.x = 0;
    c->curseur.posfromimg.y = 0;
    c->curseur.posfromimg.w = c->curseur.img->w;
    c->curseur.posfromimg.h = c->curseur.img->h;

    c->curseur.posinscreen.x = 400;
    c->curseur.posinscreen.y = 0;
}
/**
* @brief To input the mouse intersection and its positions .
* @param b SDL_Rect poscarre,int mousex,int mousey
* @return integer
*/
int intersection_souris(SDL_Rect poscarre,int mousex,int mousey)
{
	if((mousex>poscarre.x && mousex < poscarre.x+poscarre.w) && (mousey>poscarre.y && mousey<poscarre.y+poscarre.h) )
	{
		return 1;
	}
	else 
    {
    return 0;
    }
}
/**
* @brief To print all the boutons.
* @param b SDL_Surface *screen,int rep1,int rep2,int rep3,int right,int left,int forward,int back,int screen_num
* @return nothing
*/
void affichage_keybind_name(SDL_Surface *screen,int rep1,int rep2,int rep3,int right,int left,int forward,int back,int screen_num)
{
    TTF_Init(); //ma7abitch nuploadi 27 photo  lehne code ascii bch iwali 
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Rect pos3;
    SDL_Rect pos_right;
    SDL_Rect pos_left;
    SDL_Rect pos_forward;
    SDL_Rect pos_back;
    char txt1[2] = { (char)rep1, '\0' }; //lehne code ascii bch yekhou 7aref mte3ou tableau de chaine de caractere fih 2 (char)rep1 bch iwali code ascii num bersmi 
    char txt2[2] = { (char)rep2, '\0' }; 
    char txt3[2] = { (char)rep3, '\0' };
    char txt_right[2] = { (char)right, '\0' };
    char txt_left[2] = { (char)left, '\0' };
    char txt_forward[2] = { (char)forward, '\0' };
    char txt_back[2] = { (char)back, '\0' };




    
    


    TTF_Font *police ; //loadi font size 
    police = TTF_OpenFont("avocado.ttf", 30); //size bt3 ktiba 
    SDL_Surface *texte1,*texte2,*texte3,*right1,*left1,*forward1,*back1; //3 surface 7atit feha 7rouf bte3i 
    SDL_Color couleurBlanche = {0, 0, 255}; //lehne couleur rgb red green blue
    texte1 = TTF_RenderUTF8_Solid(police, txt1, couleurBlanche); //lehne bch nreturni nekhou font w nreturni text  fih 7aref bte3i bch n7oto fi surface bt3 texte 1 w ba3ed afficher bt3 7rouf 
    texte2 = TTF_RenderUTF8_Solid(police, txt2, couleurBlanche);
    texte3 = TTF_RenderUTF8_Solid(police, txt3, couleurBlanche);
    right1 = TTF_RenderUTF8_Solid(police, txt_right, couleurBlanche); // returni min texte dakhlou fi surface 
    left1 = TTF_RenderUTF8_Solid(police, txt_left, couleurBlanche);
    forward1 = TTF_RenderUTF8_Solid(police, txt_forward, couleurBlanche);
    back1 = TTF_RenderUTF8_Solid(police, txt_back, couleurBlanche);


    if(screen_num==1){
    SDL_Rect pos1={724,502,39,32}; //lehne position bt3 kal carreauet hedhoma x y w h 
    SDL_Rect pos2={724,582,39,32};
    SDL_Rect pos3={724,662,39,32};
    SDL_Rect pos_right={726,370,44,34};
    SDL_Rect pos_left={726,276,44,34};
    SDL_Rect pos_forward={726,75,44,34};
    SDL_Rect pos_back={726,170,44,34};
    SDL_BlitSurface(texte1,NULL,screen,&pos1);
    SDL_BlitSurface(texte2,NULL,screen,&pos2);
    SDL_BlitSurface(texte3,NULL,screen,&pos3);
    SDL_BlitSurface(right1,NULL,screen,&pos_right); //bch nupladi beha image or text 
        SDL_BlitSurface(left1,NULL,screen,&pos_left);
        SDL_BlitSurface(forward1,NULL,screen,&pos_forward);
        SDL_BlitSurface(back1,NULL,screen,&pos_back);
    }
    else{
    SDL_Rect pos1 ={90+400,441,31,32}; // lehne zedt 400pixels  
    SDL_Rect pos2 = {254+400,441,31,32};
    SDL_Rect pos3 = {400+400,441,31,32};
        SDL_BlitSurface(texte1,NULL,screen,&pos1);
    SDL_BlitSurface(texte2,NULL,screen,&pos2);
    SDL_BlitSurface(texte3,NULL,screen,&pos3); //afficher keybin 
    }



}
