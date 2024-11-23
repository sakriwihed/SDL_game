#include "background.h"
#include "player.h"




/*-------------------------------------------------------FONCTIONS INITIALISATION----------------------------------------------------------*/

//Backg
void initbackg(backg *back)
{    
    back->img=IMG_Load("background_images/1.bmp");
    strcpy(back->ImgName,"background_images/1.bmp");
    back->pos1.x=0;
    back->pos1.y=0;
    back->pos1.w=3360;
    back->pos1.h=512;

    back->camera.x=100;
    back->camera.y=60;
    back->camera.w=1200;
    back->camera.h=700;
}
void initbackg2(backg *back)
{    
    back->img=IMG_Load("background_images/1.bmp");
    strcpy(back->ImgName,"background_images/1.bmp");
    back->pos1.x=SCREEN_W/2;
    back->pos1.y=0;
    back->pos1.w=3700;
    back->pos1.h=512;

    back->camera.x=100;
    back->camera.y=60;
    back->camera.w=1200;
    back->camera.h=700;
}
void screen_share(backg bg1,backg bg2,SDL_Surface *screen)
{
//SDL_BlitSurface(bg1.img,&bg1.camera,screen,NULL);
SDL_BlitSurface(bg1.img,&bg1.camera,screen,&bg1.pos1);
bg2.pos1.x=(screen->w/2)+10;
SDL_BlitSurface(bg2.img,&bg2.camera,screen,&bg2.pos1);
}
void initialiser_audiobref(Mix_Music*music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024) == -1)
	{
		printf("%s",SDL_GetError());	
	}
	music = Mix_LoadMUS("dog.mp3");

	Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
void afficher(backg back,SDL_Surface *screen)
{
 SDL_BlitSurface(back.img,&back.camera,screen,&back.pos1); // bliter background fouk screen 
 
 
 
}
void scrolling (backg * back, int direction )
{
	switch(direction) 
	{
		case 3 :
		if(back->camera.x>=120) 
			back->camera.x-=20;
		break;
		case 0 :
		if (back->camera.x<=2400)
			back->camera.x += 20;
		break;


	}
}
void animate_back(backg *back, SDL_Surface *screen)
{
	int i;
	
	if (strcmp(&back->ImgName[1],".")==0	)
   	i = atoi(&back->ImgName[0]);
   else 
   {
		char temp[2];
		strncpy(temp,back->ImgName,2);   	
   	i = atoi(temp);
   }
   	
   if (i > 33)
   	i = 1;
   else
		i = i +1;
		
	char ch[30]="";
	sprintf(ch,"background_images/%d.bmp",i);
	back->img=IMG_Load(ch);
	strcpy(back->ImgName,ch);
	
	//SDL_Delay(75);
	//SDL_BlitSurface(back->img,&back->camera,screen,&back->pos1);

}

void initialiser_texte(text *txte)
{
	
	txte->font = TTF_OpenFont("arial.ttf", 12);
	txte->textColor.r=255;
	txte->textColor.g=255;
	txte->textColor.b=255;
	txte->textpos.x=350;
	txte->textpos.y=0;
}
void bestScore(char *filename, scoreinfo tab[100],SDL_Surface *screen) {
	
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error : can't open %s\n", filename);
        
    }

    // nhez les info ml file w n7othom fe tab 
    int i = 0;
    while (fscanf(fp, "%d %d %s", &tab[i].score, &tab[i].time, tab[i].playername) !=EOF ) {
        i++;
    }

    
    fclose(fp);

    // Trie 
    int n = i;
    for (i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++)
        {
            if (tab[j].score > tab[i].score ||(tab[j].score == tab[i].score && tab[j].time < tab[i].time)) 
            {
                scoreinfo tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }

    
}
void showBestScore(scoreinfo t[], SDL_Surface *screen)
{

    SDL_Surface *leader;
    leader = IMG_Load("background_images/best.png");

    int loop = 1;
    SDL_Event event;
	 text texte,texte1 ;
    //SDL_FillRect(screen, NULL, 0x000000);
    SDL_BlitSurface(leader, NULL, screen, NULL);
    int y = 170;
    initialiser_texte(&texte);
    initialiser_texte(&texte1);

    for (int i = 0; i < 3; i++)
    {
        char name[100];
        char info[100];
        
        sprintf(name, "player name: %s", t[i].playername);
        sprintf(info, "Score : %d, time : %d", t[i].score, t[i].time);
        texte.textpos.y += 150;
        texte1.textpos.y =texte.textpos.y+50;
        texte.txt=TTF_RenderText_Blended(texte.font,name,texte.textColor);
        texte1.txt=TTF_RenderText_Blended(texte.font,info,texte.textColor);
        
        SDL_BlitSurface(texte.txt, NULL, screen, &texte.textpos);
        SDL_BlitSurface(texte1.txt, NULL, screen, &texte1.textpos);
        

    }
    SDL_Flip(screen);
    while (loop)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
             case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                loop = 0;
                break;
                }
             }
            }
        }
    }

void display_btn(btn b, SDL_Surface *screen)
{
	SDL_BlitSurface(b.button, NULL, screen, &b.posButton);
}
void init_btn(btn *b)
{
	b->button = IMG_Load("background_images/button.png");
	b->posButton.x = 800;
	b->posButton.y = 500;
   b->posButton.w = 350;
   b->posButton.h = 186;
}