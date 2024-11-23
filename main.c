#include "menu.h"
#include "player.h"
#include "background.h"
#include "serie.h"
#include "lot6.h"
#include "minimap.h"
#include "ennemi.h"


/**
* @file main.c
* @brief Testing Program.
* @author Janfaoui
* @version 0.1
* @date May 01, 2023
*
* main file for player task
*
*/

int main()
{
	//menu & general
	SDL_Surface *screen;
	image squareaudio, quitSETTINGS, playbackground,fullButton;
	button IMAGE_BTN1, IMAGE_BTN2,IMAGE_BTN3;
	animated aniBACK, aniSETTINGS;
	Mix_Music *music, *music1;
	Mix_Chunk *mus;
	texte txte;
	SDL_Event event;
	int loop = 1, GAMElevel = 0, fullscreen = 0, volume = 0, i = 1,j=1,selected = 1, keyboard = 0, changeX = 300, changeY = 150, counter = 0,z,gamepad = 0, players = 1;
	
	//player
	Uint32 dt=0, t_prev;
	player p, p2;
	int alter;
	printf("how many players?");
	scanf("%d",&players);
	
	//background
	backg bg1,bg2;
	text texte;
	int T=0;
	scoreinfo tab[100];
	btn b;
	

	
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
	{
		printf("Could not initialize SDL:  %s.\n",SDL_GetError());
		return -1;
	}

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("DATA PIRATES GAME", NULL);
	TTF_Init();
	
	//menu and settings
	initialiser_imageBACKsettings(&aniSETTINGS);
	initialiser_squareaudio(&squareaudio);
	initialiser_quitSETTINGS(&quitSETTINGS);
	initialiser_fullscreenbutton(&fullButton);
	
	initialiser_imageBACK(&aniBACK);
	initialiser_imageBOUTON1(&IMAGE_BTN1);
	initialiser_imageBOUTON2(&IMAGE_BTN2);
	initialiser_imageBOUTON3(&IMAGE_BTN3);
	
	initialize_texte(&txte);
	
	initialize_audio(music);
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, 2, 2048);
	mus=Mix_LoadWAV("Menu_images/simple.wav");
	if (mus == NULL) printf("%s", SDL_GetError());
	
	//play
	initPlayer(&p);
	initPlayer2(&p2);
	initialiser_imageBackground(&playbackground);
	
	
	//background
	init_btn(&b);
	initbackg(&bg1);
	initbackg2(&bg2);
		if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024) == -1)
	{
		printf("%s",SDL_GetError());	
	}
	music1 = Mix_LoadMUS("dog.mp3");
	
	//enigme2
	int reponse_1,reponse_2,reponse_3; //ki tenzel 3al p nodkhol lil parametre lehne 3 reponses 7atinehom integer 
    reponse_1=119; //w lehne code ascii bt3 bouton loula 
    reponse_2=120; //x code asci bt3 bouton 2 
    reponse_3=99; //c code ascii bt3 bouton 3
    int right=100; //d 
    int left=113; //q
    int forward=122; //z
    int back=115; //s

    int mousex,mousey; // variable pour sauvegarder les positions de la souris
    int whichscreen = 0; // keni 0 bech t affichli enigme sinon keni 1 bech t affichili menu input
    int screen_num=2; // ken 1 yod5el lel switch te3 menu ken 2 enigme ken 1 parametre 2 bch yodkhel lil lo3ba 
    
    SDL_Surface *setting,*select_key; //surface el setting
     setting=IMG_Load("setting.png");
    select_key=IMG_Load("select_key.png");
    Enigme_image enigme_img;
    puzzlegenerate (&enigme_img);
    // Set the font for the primitives drawing routines
    gfxPrimitivesSetFont(NULL, 0, 0);
    // Zoom the image by a factor of 2
    SDL_Surface *zoomed = NULL;
    //**********************input
     input joueur1;
     initialisation_background_input(&joueur1);
    //position de lettre dans  (parametre)
    SDL_Rect keybin1 ={600,483,301,65}; //lehne position exacte x y w h 
    SDL_Rect keybin2= {600,567,301,65};
    SDL_Rect keybin3 = {600,644,301,65};
    SDL_Rect pos_forward= {607,57,297,69};
    SDL_Rect pos_back= {607,155,297,69};
    SDL_Rect pos_left= {607,259,297,69};
    SDL_Rect pos_right= {607,355,297,69};
    int done = 0;
     Uint32 t_prev2=0, t_prev1=0, t_prev3=0;
     
    //XO & minimap
    minimap m,m1;
    image *backgm;
    initmap(&m);
	initmap1 (&m1);
    TicTakTo tik;
    tik.h=720;
    tik.w=1200;
    initialiserTic(&tik);
    int x,y,coup;
    int state=0;
    //ennemi
	 Uint32 start;
	 const int contr = 15; 
	 Ennemi E;
	 initEnnemi(&E);
    
	
	//joystick
	 /*char buffer[100];              

    int fd = serialport_init("/dev/ttyUSB0", 9600);
    if (fd==-1) return -1;*/

       
    

	while(loop)
	{
			
			/*serialport_read_until(fd, buffer, '\r', 10, 1);
        	for (z=0 ; buffer[z]!='\r' && z<100 ; z++);
       	buffer[z] = 0;
         printf("%s", buffer);*/
		if(GAMElevel == 0) //menu
		{
			
			alter = 1;
		if (i<34){
			if (aniBACK.images3[i] != NULL)
			{
			SDL_Delay(75);
			SDL_BlitSurface(aniBACK.images3[i], NULL, screen,&aniBACK.pos_img_ecran);
			i=i+1;			
			}
		}
		else i=1;
		display_btn(b,screen);
		afficher_imageBTN(screen, IMAGE_BTN1);
		afficher_imageBTN(screen, IMAGE_BTN2);
		afficher_imageBTN(screen, IMAGE_BTN3);
		show_text(screen,txte);
		if(counter == 1 )
		{
			Mix_PlayChannel(-1, mus, 0);
			counter = 0;
		}
		/*if(strcmp("up",buffer) == 0)
         {
         	gamepad = 1;
         	if(selected == 1) 
               {
               	selected = 3;
               	}
               else selected--;
         }
		else if(strcmp("enter",buffer) == 0)
         {
         	
         	 switch(selected)
            {
					case 1:
					GAMElevel = 1;
					break;
					case 2:
					GAMElevel = -1;
					break; 
					case 3:
					loop = 0;
					break;             
            }
         }
         if(gamepad == 1) 
				{
					switch(selected) 
					{
					case 1:
					if(counter == 0) 
					counter = 1;
					IMAGE_BTN1.state = 1;
					IMAGE_BTN2.state = 0;
		 			IMAGE_BTN3.state = 0;
					break;
					case 2:
					if(counter == 0)
					counter = 1;
					IMAGE_BTN3.state = 1;
					IMAGE_BTN1.state = 0;
		 			IMAGE_BTN2.state = 0;
					break;
					case 3:
					if(counter == 0)
					counter = 1;	 			
					IMAGE_BTN2.state = 1;
					IMAGE_BTN3.state = 0;
					IMAGE_BTN1.state = 0;
					break;
					}
				}*/
		while(SDL_PollEvent(&event))
		{
			
				if(keyboard == 1) 
				{
					switch(selected) 
					{
					case 1:
					if(counter == 0)
					counter = 1;
					IMAGE_BTN1.state = 1;
					IMAGE_BTN2.state = 0;
		 			IMAGE_BTN3.state = 0;
					break;
					case 2:
					if(counter == 0)
					counter = 1;
					IMAGE_BTN3.state = 1;
					IMAGE_BTN1.state = 0;
		 			IMAGE_BTN2.state = 0;
					break;
					case 3:
					if(counter == 0)
					counter = 1;	 			
					IMAGE_BTN2.state = 1;
					IMAGE_BTN3.state = 0;
					IMAGE_BTN1.state = 0;
					break;
					}
				}
		 	switch(event.type) {
		 		
		 		case SDL_QUIT:
		 		loop = 0;
		 		break;
		 		
		 		case SDL_MOUSEBUTTONDOWN:
		 		if(fullscreen == 1) {
		 		if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= IMAGE_BTN2.pos_img_ecran.y+150+changeY && event.motion.y >= IMAGE_BTN2.pos_img_ecran.y-50+changeY 
		 		&& event.motion.x <= IMAGE_BTN2.pos_img_ecran.x+350+changeX && event.motion.x>=IMAGE_BTN2.pos_img_ecran.x-100+changeX))
		 			loop = 0;
		 		if(event.button.button == SDL_BUTTON_LEFT &&(event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+400+changeX && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x+changeX)&&
					(event.motion.y<=IMAGE_BTN3.pos_img_ecran.y+50+changeY && event.motion.y>IMAGE_BTN3.pos_img_ecran.y+changeY) )
					GAMElevel = -1;
		 		}
		 		else {
		 			if (event.motion.x >= b.posButton.x && event.motion.x <= b.posButton.x + b.posButton.w && event.motion.y >= b.posButton.y && event.motion.y <= b.posButton.y + b.posButton.h)
            {
                bestScore("scores.txt", tab,screen);
                showBestScore(tab, screen);
            }
		 			if(event.button.button == SDL_BUTTON_LEFT &&(event.motion.x <= IMAGE_BTN3.pos_img_ecran.x+300 && event.motion.x >= IMAGE_BTN3.pos_img_ecran.x)&&
					(event.motion.y<=IMAGE_BTN3.pos_img_ecran.y+100 && event.motion.y>IMAGE_BTN3.pos_img_ecran.y) ) 
					{
					GAMElevel = -1;
					}
					if(event.button.button == SDL_BUTTON_LEFT &&(event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+300 && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x)&&
					(event.motion.y<=IMAGE_BTN1.pos_img_ecran.y+100 && event.motion.y>IMAGE_BTN1.pos_img_ecran.y) ) 
					{
					GAMElevel = 1;
					}		
		 			if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= IMAGE_BTN2.pos_img_ecran.y+100 && event.motion.y >= IMAGE_BTN2.pos_img_ecran.y 
		 		&& event.motion.x <= IMAGE_BTN2.pos_img_ecran.x+300 && event.motion.x>=IMAGE_BTN2.pos_img_ecran.x))
		 			loop = 0;
		 		}
		 			break;
		 			
		 		case SDL_MOUSEMOTION:
		 		if(fullscreen == 0) //windowed buttons
		 		{
		 			if( (event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+300 && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x)&&
		 			(event.motion.y<=IMAGE_BTN1.pos_img_ecran.y+100 && event.motion.y>IMAGE_BTN1.pos_img_ecran.y)  ) 
		 			{
		 			keyboard = 0;
		 			gamepad = 0;
		 			counter = 1;
					IMAGE_BTN1.state = 1;
					}
					
					else if((event.motion.x <= IMAGE_BTN2.pos_img_ecran.x+300 && event.motion.x >= IMAGE_BTN2.pos_img_ecran.x)&&
					(event.motion.y<=IMAGE_BTN2.pos_img_ecran.y+100 && event.motion.y>IMAGE_BTN2.pos_img_ecran.y) ) 
					{
					keyboard = 0;
					gamepad = 0;
		 			counter = 1;
					IMAGE_BTN2.state = 1;
					}
					else if((event.motion.x <= IMAGE_BTN3.pos_img_ecran.x+300 && event.motion.x >= IMAGE_BTN3.pos_img_ecran.x)&&
					(event.motion.y<=IMAGE_BTN3.pos_img_ecran.y+100 && event.motion.y>IMAGE_BTN3.pos_img_ecran.y) ) 
					{
					keyboard = 0;
					gamepad = 0;
		 			counter = 1;
					IMAGE_BTN3.state = 1;
					}	
		 		else 
		 		{
		 			IMAGE_BTN1.state = 0;
		 			IMAGE_BTN2.state = 0;
		 			IMAGE_BTN3.state = 0;
		 			SDL_Flip(screen);
		 			}
		 		}
		 		
		 		else //fullscreen buttons
		 		{
		 			if( (event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+350+changeX && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x+changeX)&&
		 			(event.motion.y<=IMAGE_BTN1.pos_img_ecran.y+50+changeY && event.motion.y>IMAGE_BTN1.pos_img_ecran.y+changeY)  ) 
		 			{
		 			keyboard = 0;
		 			counter = 1;
					IMAGE_BTN1.state = 1;
					}
					
					else if((event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+350+changeX && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x+changeX-100)&&
					(event.motion.y<=IMAGE_BTN2.pos_img_ecran.y+50+changeY && event.motion.y>IMAGE_BTN2.pos_img_ecran.y+changeY) ) 
					{
					keyboard = 0;
		 			counter = 1;
					IMAGE_BTN2.state = 1;
					}
					else if((event.motion.x <= IMAGE_BTN1.pos_img_ecran.x+400+changeX && event.motion.x >= IMAGE_BTN1.pos_img_ecran.x+changeX)&&
					(event.motion.y<=IMAGE_BTN3.pos_img_ecran.y+50+changeY && event.motion.y>IMAGE_BTN3.pos_img_ecran.y+changeY) ) 
					{
					keyboard = 0;
		 			counter = 1;
					IMAGE_BTN3.state = 1;
					}	
		 		else 
		 		{
		 			IMAGE_BTN1.state = 0;
		 			IMAGE_BTN2.state = 0;
		 			IMAGE_BTN3.state = 0;
		 			SDL_Flip(screen);
		 			}
		 			
		 			}
		 		break;
		 		
		 		case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
		 		case SDLK_f:
		 			if (fullscreen == 0)
		 			 {
               	SDL_WM_ToggleFullScreen(screen);
               	fullscreen = 1;
                }
               else 
               {
               	SDL_WM_ToggleFullScreen(screen);
               	fullscreen = 0;
               }
               break;
            case SDLK_UP:           
               if(selected == 1) 
               {
               	selected = 3;
               	}
               else selected--;
               keyboard = 1;
               break;
            case SDLK_DOWN:     
               if(selected == 3) 
               {
               	selected = 1;
               	}
               else selected++;
               keyboard = 1;
               
               break;
            case SDLK_RETURN:
            switch(selected)
            {
					case 1:
					GAMElevel = 1;
					break;
					case 2:
					GAMElevel = -1;
					break; 
					case 3:
					loop = 0;
					break;             
            }
            break;                
		 		}
                   
                    }
		}}
		else if(GAMElevel == -1) //settings screen
		{
			Mix_VolumeMusic(volume);
			if (j<9){
			if (aniSETTINGS.images3[j] != NULL)
			{
			SDL_Delay(100);
			SDL_BlitSurface(aniSETTINGS.images3[j], NULL, screen,&aniSETTINGS.pos_img_ecran);
			j++;			
			}
		}
		else j=1;
		afficher_image(screen,squareaudio);
		afficher_image(screen,quitSETTINGS);
		afficher_image(screen,fullButton);
			
		while(SDL_PollEvent(&event))
		{
			if(fullscreen == 0) {
			if(squareaudio.pos_img_ecran.x<=630) {
		 				volume = 0;
		 			}
		 			else {
		 				
		 			volume = squareaudio.pos_img_ecran.x-625;
		 			}
		 			
		 		}
		 	else {
		 		if(squareaudio.pos_img_ecran.x<=630) {
		 				volume = 0;
		 			}
		 			else {
		 				
		 			volume = squareaudio.pos_img_ecran.x-625;
		 			}
		 	}
			switch(event.type) {
				case SDL_QUIT:
		 		loop = 0;
		 		break;
				case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
					case SDLK_ESCAPE:
					if(alter == 1)
					GAMElevel = 0;
					else if(alter == 2)
					GAMElevel = 1;
					break;
					case SDLK_a:
					loop=0;
					break;		 			
		 			
		 			
		 		}
		 		break;
		 	case SDL_MOUSEBUTTONDOWN:
		 	if(fullscreen == 0) {
		 	if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 300 && event.motion.y >= 245
		 		&& event.motion.x <= 850 && event.motion.x>=640))
		 		{
		 			squareaudio.pos_img_ecran.x = event.motion.x-20;
		 			
		 			
		 		}
			if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= quitSETTINGS.pos_img_ecran.y+55&& event.motion.y >= quitSETTINGS.pos_img_ecran.y
		 		&& event.motion.x <= quitSETTINGS.pos_img_ecran.x+105 && event.motion.x>=quitSETTINGS.pos_img_ecran.x))
		 		{
		 			GAMElevel = 0;
		 			
		 			
		 		}	
		 		if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= fullButton.pos_img_ecran.y+50&& event.motion.y >= fullButton.pos_img_ecran.y
		 		&& event.motion.x <= fullButton.pos_img_ecran.x+250 && event.motion.x>=fullButton.pos_img_ecran.x))
		 		{
		 			SDL_WM_ToggleFullScreen(screen);
               fullscreen = 1;
		 				
		 	} 		
		 		}
		 	else {
		 		if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 300 +changeY&& event.motion.y >= 245+changeY
		 		&& event.motion.x <= 920+changeX && event.motion.x>=720+changeX)) 
		 		{
		 			squareaudio.pos_img_ecran.x = event.motion.x-100-changeX;
		 		
		 		}
		 		
		 		
		 		if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= quitSETTINGS.pos_img_ecran.y+45+changeY&& event.motion.y >= quitSETTINGS.pos_img_ecran.y-35+changeY
		 		&& event.motion.x <= quitSETTINGS.pos_img_ecran.x+105+changeX && event.motion.x>=quitSETTINGS.pos_img_ecran.x+changeX))
		 		{
		 			GAMElevel = 0;
		 			
		 			
		 		}
		 		if(event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= fullButton.pos_img_ecran.y+50+changeY&& event.motion.y >= fullButton.pos_img_ecran.y+changeY
		 		&& event.motion.x <= fullButton.pos_img_ecran.x+250+changeX && event.motion.x>=fullButton.pos_img_ecran.x+changeX))
		 		{
		 			SDL_WM_ToggleFullScreen(screen);
               fullscreen = 0;
		 				
		 	} 		
		 		
		 		}
		 	break;
			}
					
		}
		}
		else if(GAMElevel == 1) //main game level
		{
			if(players == 2) {
			alter = 2;
			t_prev=SDL_GetTicks();
      	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      	
      	//animate_back(&back,screen);
      	//afficher(back,screen);
      	screen_share(bg1,bg2,screen);
      	afficherEnnemi(&E, screen);
   		animerEnnemi(&E);
			moveIA(&E, p.pos_screen);
      	displaymap(m1, screen);
				miniplayer(&m1,&p);
        		animatemap(&m1,screen);
         animatePlayer(&p);
        	displayPlayer(p, screen);
        	displaymap(m, screen);
				miniplayer(&m,&p2);
        		animatemap(&m,screen);
        	animatePlayer(&p2);
        	displayPlayer(p2, screen);
        	
        	//joystick
        
         
        /* if(strcmp("left",buffer) == 0) 
         {
         	gamepad = 1;
         	 p.acceleration = -0.02;
             p.direction = 3;
             }
             else if(strcmp("right",buffer) == 0)
             {
             	gamepad = 1;
              		p.acceleration = 0.005;
             		p.direction = 0;
             }
             else if(strcmp("up",buffer) == 0)
             {
             	gamepad = 1;
              		p.direction = 1;
              		jump(&p);
             }
             else if(strcmp("quit",buffer) == 0)
             {
             	gamepad = 1;
              		loop = 0;
             }
             if(gamepad == 1) {
             	if(strcmp("none",buffer) == 0)
         {
         	p.acceleration = 0.0;
         	p.direction = 2;
         }}*/

       while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    loop = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    	case SDLK_p:
                    	Mix_PlayMusic(music1,-1);
                    	break;
                        case SDLK_LEFT:
                        gamepad = 0;
                            p.acceleration = -0.02;
                            p.direction = 3;
                            break;
                        case SDLK_RIGHT:
                        gamepad = 0;
                            p.acceleration = 0.005;
                            p.direction = 0;
                            break;
                        case SDLK_SPACE:
                        gamepad = 0;
                        p.direction = 1;
                        jump(&p);
                        break;
                        case SDLK_a:
                        
                            p2.acceleration = -0.02;
                            p2.direction = 3;
                            break;
                        case SDLK_d:
                            p2.acceleration = 0.005;
                            p2.direction = 0;
                            break;
                        case SDLK_w:
                        p2.direction = 1;
                        jump(&p2);
                        break;
                        case SDLK_ESCAPE:
								GAMElevel = -1;
								Mix_ResumeMusic();
								break;
								case SDLK_x:
								if(state == 0) state =1;
								else state = 0;
								break;
								case SDLK_c:
								 while (!done)
    {
        switch(screen_num) //case parametre w case lo3Ba
        {
            case 1:// ki tenzel 3al p nodkhel case 1 howa de base yodkhel lil 2 li hyia lo3ba bch nokhroj echap nenzel //1 fel parametre 
                SDL_GetMouseState(&mousex,&mousey);
                SDL_BlitSurface(setting,NULL,screen,NULL);
                affichage_keybind_name(screen,reponse_1,reponse_2,reponse_3,right,left,forward,back,screen_num);
//code ascii des reponses bch yaffichi ybadelha a w le z w ba3ed yaffichi 
                SDL_Flip(screen);

                if(SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        case SDL_QUIT:
                            done = 1;
                        break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    screen_num=2;
                                break;
                            }
                        break;
                    }
                    // condition ki nenzel 3al carreau te3 answer1 fel parametere ybadel el code asci te3 reponse 1 
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin1,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP) //kima sdl poll event ama lehne yestana 
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL); //afficheli tassouira select key loadit tassouira w blitsurface
                            SDL_Flip(screen);
                            //printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN) //tawa clicket 3al bouton  event.type teb3a sdl event structure 
                            reponse_1=event.key.keysym.sym; //bch tekhou code ascii bt3 bouton li nzelt 3lih zid efhemha hedhi 3a net
                            //printf("second %d\n",reponse_1);
                        }
                    }
                    // condition ki nenzel 3al carreau te3 answer2 fel parametere ybadel el code asci te3 reponse 2
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin2,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            reponse_2=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    // condition ki nenzel 3al carreau te3 answer3 fel parametere ybadel el code asci te3 reponse 3 
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin3,mousex,mousey)==1) // mafhemthech 
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP) //nzelt bsouris 3al morabe3 lehne bch yokhroj ki thez sob3ek 3a souris nch yokhoj mel while //lehne ybadel code ascii w yokhroj 
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL); //lehne yaffichili ka tassouira select key 
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_3);
                            if(event.type==SDL_KEYDOWN)
                            reponse_3=event.key.keysym.sym; // ki tenzel 3Al boutton louta evenet traj3lek code ascii bt3 boutton li nzelt 3lih 
                            printf("second %d\n",reponse_3);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_right,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            right=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_left,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            left=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_forward,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            forward=event.key.keysym.sym; //ki tenzel 3Al felsa hedhika t3tik code ascii bte3ha
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_back,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            back=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                }
            break;
            case 2:
                if (whichscreen == 0)
        {
        	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // affichage background bidha
         	   
		displayenigma(enigme_img, screen);
         affichage_keybind_name(screen,reponse_1,reponse_2,reponse_3,right,left,forward,back,screen_num);

            // Process events
          	  while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_RETURN:

                        break;
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_UP:

                        break;
                    case SDLK_p:
                            screen_num=1;

                        break;
                    
                    }
                 if(event.key.keysym.sym==reponse_1)
                 {
                    if (enigme_img.solved == 0) // tant que howa
                        {
                            Mix_HaltMusic();
                            if (enigme_img.solution==1) // kena nzelu w howa reponse s7i7a alors solved =2 sinon =3
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                 if(event.key.keysym.sym==reponse_2)
                 {
                     if (enigme_img.solved == 0)
                        {
                            Mix_HaltMusic();

                            if (enigme_img.solution==2)
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                 if(event.key.keysym.sym==reponse_3)
                 {
                    if (enigme_img.solved == 0)
                        {
                            Mix_HaltMusic();

                            if (enigme_img.solution==3)
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                    
                    break;
                }
            }

            

                               // affichage mta3 l question foo9 l background
            
            if (enigme_img.solved == 2) // keno jeweb s 7i7e
            {
                static float zoom_factor = 1.0;                                                   // nzoomi melowel b 1.0
                zoom_factor += 0.01;                                                              // zoome yemchi w yekber 0 0.01
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));            // n aficher background bidhe
                zoomed = zoomSurface(enigme_img.won.img, zoom_factor, zoom_factor, SMOOTHING_ON); // nesna3 surface jdida eli b zoom jdidee
                int x = (screen->w / 2) - (zoomed->w / 2);                                        // ne7seb l x eli fel woset
                int y = (screen->h / 2) - (zoomed->h / 2);                                        // ne7seb l y eli fel wose
                SDL_Rect dest = {x, y, zoomed->w, zoomed->h};                                     // nrake7 destination ween bech naffiche fi screen
                SDL_BlitSurface(zoomed, NULL, screen, &dest);                                     // n affichiha
            if(zoom_factor>3.039998){done=1;}
            }
            else if (enigme_img.solved == 3) // keno jeweb bel 8alet
            {
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // n aficher background bidhe
                static double angle = 0.0;
                angle += 0.1;                                                                               // nzeed fel angle de routage
                SDL_Surface *rotated_img = rotozoomSurface(enigme_img.lost.img, angle, 1.0, 0);             // nrotate l image
                SDL_Rect rect = {(screen->w - rotated_img->w) / 2, (screen->h - rotated_img->h) / 2, 0, 0}; // destination cordinate
                SDL_BlitSurface(rotated_img, NULL, screen, &rect);                                          // naffiche l image jdida b rotate
                SDL_FreeSurface(rotated_img);
            }
        }
       else if (whichscreen == 1) // hedheya l block mta3 l input
        {
            if (SDL_GetTicks() - t_prev2 > 150) // kol 150 ms n affiche l menu input
            {
                afficher_menu_input(joueur1, screen);
                t_prev2 = SDL_GetTicks();
            }
            SDL_PollEvent(&event); // retrieves the next event from the event queue
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {

                case SDLK_ESCAPE:
                    done = 1;
                    break;
                }

                break;
                // lehna na9ra fel position mta3 souris wa9tili howa ya3mel fi click w nchoof howa ween nzel w na3mel l modification mta3 l input
            case SDL_MOUSEBUTTONDOWN:
                if (joueur1.up[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 305 && event.motion.y <= 352)
                {
                    joueur1.up[0] = 1;
                }
                else if (joueur1.up[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 304 && event.motion.y <= 356)
                {
                    joueur1.up[0] = 2;
                }
                if (joueur1.down[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 389 && event.motion.y <= 441)
                {
                    joueur1.down[0] = 1;
                }
                else if (joueur1.down[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 387 && event.motion.y <= 441)
                {
                    joueur1.down[0] = 2;
                }

                if (joueur1.right[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[0] = 1;
                }
                else if (joueur1.right[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[0] = 2;
                }
                if (joueur1.left[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 389 + 84 + 84 && event.motion.y <= 441 + 84 + 84)
                {
                    joueur1.left[0] = 1;
                }
                else if (joueur1.left[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 555 && event.motion.y <= 607)
                {
                    joueur1.left[0] = 2;
                }
                //***************************************************second player
                if (joueur1.up[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 305 && event.motion.y <= 352)
                {
                    joueur1.up[1] = 1;
                }
                else if (joueur1.up[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 304 && event.motion.y <= 356)
                {
                    joueur1.up[1] = 2;
                }
                if (joueur1.down[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 389 && event.motion.y <= 441)
                {
                    joueur1.down[1] = 1;
                }
                else if (joueur1.down[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 387 && event.motion.y <= 441)
                {
                    joueur1.down[1] = 2;
                }

                if (joueur1.right[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[1] = 1;
                }
                else if (joueur1.right[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[1] = 2;
                }
                if (joueur1.left[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 389 + 84 + 84 && event.motion.y <= 441 + 84 + 84)
                {
                    joueur1.left[1] = 1;
                }
                else if (joueur1.left[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 555 && event.motion.y <= 607)
                {
                    joueur1.left[1] = 2;
                }

                break;
            }
        }
    
        

        SDL_Flip(screen); // mettre à jour la surface de l'écran
            break;
        }
    }
								break;
								case SDLK_b:
								p.score += 10;
								break;
								case SDLK_k:
								p.lives -= 1;
								break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            p.acceleration += 0.02;
                            p.direction = 2;
                            break;
                        case SDLK_RIGHT:
                        	 p.direction = 2;
                            p.acceleration -= 0.005;
                            break;
                            case SDLK_a:
                            p2.acceleration += 0.02;
                            p2.direction = 2;
                            break;
                        case SDLK_d:
                        	 p2.direction = 2;
                            p2.acceleration -= 0.005;
                            break;

                    }
                    break;
            }
        }
			if(p.direction == 2  && p.speed>0) p.speed -= 0.05; 
			if(p2.direction == 2  && p2.speed>0) p2.speed -= 0.05;
			if(state==1){
            afficherTic(tik,screen);
            if(tik.nbtour<9){
                if((tik.nbtour+tik.joueur)%2==0&&atilgagne(tik.tabSuiv)!=-1){
                    calcul_coup(tik.tabSuiv);
                    tik.nbtour++;
                }
                else{
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        x=(event.button.x-tik.bk.pos1.x)/(tik.bk.img->w/3);
                        y=(event.button.y-tik.bk.pos1.y)/(tik.bk.img->h/3);
                        coup=3*y+x;
                        if(tik.tabSuiv[coup]==0){
                            tik.tabSuiv[coup]=-1;
                            tik.nbtour++;
                        }
                    }
                }
            }
            if(atilgagne(tik.tabSuiv)!=0) {
                afficherTic(tik,screen);
                Resultat(tik,screen);
            }
        }
        movePlayer(&p, dt);
        movePlayer2(&p2, dt);
        scrolling(&bg1,p.direction);
        scrolling(&bg2,p2.direction);
        dt = SDL_GetTicks() - t_prev;
					
		}
	
		else {
			alter = 2;
			t_prev=SDL_GetTicks();
      	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      	
      	//animate_back(&back,screen);
      	afficher(bg1,screen);
      	afficherEnnemi(&E, screen);
   		animerEnnemi(&E);
			moveIA(&E, p.pos_screen);
displaymap(m1, screen);
				miniplayer(&m1,&p);
        		animatemap(&m1,screen);
         animatePlayer(&p);
        	displayPlayer(p, screen); 	
        	//joystick
        /* if(strcmp("left",buffer) == 0) 
         {
         	gamepad = 1;
         	 p.acceleration = -0.02;
             p.direction = 3;
             }
             else if(strcmp("right",buffer) == 0)
             {
             	gamepad = 1;
              		p.acceleration = 0.005;
             		p.direction = 0;
             }
             else if(strcmp("up",buffer) == 0)
             {
             	gamepad = 1;
              		p.direction = 1;
              		jump(&p);
             }
             else if(strcmp("quit",buffer) == 0)
             {
             	gamepad = 1;
              		loop = 0;
             }
             if(gamepad == 1) {
             	if(strcmp("none",buffer) == 0)
         {
         	p.acceleration = 0.0;
         	p.direction = 2;
         }}*/

       while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    loop = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    	case SDLK_p:
                    	Mix_PlayMusic(music1,-1);
                    	break;
                        case SDLK_LEFT:
                        gamepad = 0;
                            p.acceleration = -0.02;
                            p.direction = 3;
                            break;
                        case SDLK_RIGHT:
                        gamepad = 0;
                            p.acceleration = 0.005;
                            p.direction = 0;
                            break;
                        case SDLK_SPACE:
                        gamepad = 0;
                        p.direction = 1;
                        jump(&p);
                        break;
                        case SDLK_ESCAPE:
								GAMElevel = -1;
								Mix_ResumeMusic();
								break;
								case SDLK_x:
								if(state == 0) state = 1;
								else state =0;
								break;
								case SDLK_c:
								 while (!done)
    {
        switch(screen_num) //case parametre w case lo3Ba
        {
            case 1:// ki tenzel 3al p nodkhel case 1 howa de base yodkhel lil 2 li hyia lo3ba bch nokhroj echap nenzel //1 fel parametre 
                SDL_GetMouseState(&mousex,&mousey);
                SDL_BlitSurface(setting,NULL,screen,NULL);
                affichage_keybind_name(screen,reponse_1,reponse_2,reponse_3,right,left,forward,back,screen_num);
//code ascii des reponses bch yaffichi ybadelha a w le z w ba3ed yaffichi 
                SDL_Flip(screen);

                if(SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        case SDL_QUIT:
                            done = 1;
                        break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    screen_num=2;
                                break;
                            }
                        break;
                    }
                    // condition ki nenzel 3al carreau te3 answer1 fel parametere ybadel el code asci te3 reponse 1 
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin1,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP) //kima sdl poll event ama lehne yestana 
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL); //afficheli tassouira select key loadit tassouira w blitsurface
                            SDL_Flip(screen);
                            //printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN) //tawa clicket 3al bouton  event.type teb3a sdl event structure 
                            reponse_1=event.key.keysym.sym; //bch tekhou code ascii bt3 bouton li nzelt 3lih zid efhemha hedhi 3a net
                            //printf("second %d\n",reponse_1);
                        }
                    }
                    // condition ki nenzel 3al carreau te3 answer2 fel parametere ybadel el code asci te3 reponse 2
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin2,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            reponse_2=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    // condition ki nenzel 3al carreau te3 answer3 fel parametere ybadel el code asci te3 reponse 3 
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(keybin3,mousex,mousey)==1) // mafhemthech 
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP) //nzelt bsouris 3al morabe3 lehne bch yokhroj ki thez sob3ek 3a souris nch yokhoj mel while //lehne ybadel code ascii w yokhroj 
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL); //lehne yaffichili ka tassouira select key 
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_3);
                            if(event.type==SDL_KEYDOWN)
                            reponse_3=event.key.keysym.sym; // ki tenzel 3Al boutton louta evenet traj3lek code ascii bt3 boutton li nzelt 3lih 
                            printf("second %d\n",reponse_3);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_right,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            right=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_left,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            left=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_forward,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            forward=event.key.keysym.sym; //ki tenzel 3Al felsa hedhika t3tik code ascii bte3ha
                            printf("second %d\n",reponse_1);
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && intersection_souris(pos_back,mousex,mousey)==1)
                    {                    
                        while(SDL_WaitEvent(&event) && event.type!=SDL_KEYUP)
                        {
                            SDL_BlitSurface(select_key,NULL,screen,NULL);
                            SDL_Flip(screen);
                            printf("first %d\n",reponse_1);
                            if(event.type==SDL_KEYDOWN)
                            back=event.key.keysym.sym;
                            printf("second %d\n",reponse_1);
                        }
                    }
                }
            break;
            case 2:
                if (whichscreen == 0)
        {
        	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // affichage background bidha
         	   
		displayenigma(enigme_img, screen);
         affichage_keybind_name(screen,reponse_1,reponse_2,reponse_3,right,left,forward,back,screen_num);

            // Process events
          	  while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_RETURN:

                        break;
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_UP:

                        break;
                    case SDLK_p:
                            screen_num=1;

                        break;
                    
                    }
                 if(event.key.keysym.sym==reponse_1)
                 {
                    if (enigme_img.solved == 0) // tant que howa
                        {
                            Mix_HaltMusic();
                            if (enigme_img.solution==1) // kena nzelu w howa reponse s7i7a alors solved =2 sinon =3
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                 if(event.key.keysym.sym==reponse_2)
                 {
                     if (enigme_img.solved == 0)
                        {
                            Mix_HaltMusic();

                            if (enigme_img.solution==2)
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                 if(event.key.keysym.sym==reponse_3)
                 {
                    if (enigme_img.solved == 0)
                        {
                            Mix_HaltMusic();

                            if (enigme_img.solution==3)
                            {
                                enigme_img.solved = 2;
                            }
                            else
                                enigme_img.solved = 3;
                        }
                 }
                    
                    break;
                }
            }
                               // affichage mta3 l question foo9 l background
            
            if (enigme_img.solved == 2) // keno jeweb s 7i7e
            {
                static float zoom_factor = 1.0;                                                   // nzoomi melowel b 1.0
                zoom_factor += 0.01;                                                              // zoome yemchi w yekber 0 0.01
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));            // n aficher background bidhe
                zoomed = zoomSurface(enigme_img.won.img, zoom_factor, zoom_factor, SMOOTHING_ON); // nesna3 surface jdida eli b zoom jdidee
                int x = (screen->w / 2) - (zoomed->w / 2);                                        // ne7seb l x eli fel woset
                int y = (screen->h / 2) - (zoomed->h / 2);                                        // ne7seb l y eli fel wose
                SDL_Rect dest = {x, y, zoomed->w, zoomed->h};                                     // nrake7 destination ween bech naffiche fi screen
                SDL_BlitSurface(zoomed, NULL, screen, &dest);                                     // n affichiha
            if(zoom_factor>3.039998){done=1;}
            }
            else if (enigme_img.solved == 3) // keno jeweb bel 8alet
            {
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // n aficher background bidhe
                static double angle = 0.0;
                angle += 0.1;                                                                               // nzeed fel angle de routage
                SDL_Surface *rotated_img = rotozoomSurface(enigme_img.lost.img, angle, 1.0, 0);             // nrotate l image
                SDL_Rect rect = {(screen->w - rotated_img->w) / 2, (screen->h - rotated_img->h) / 2, 0, 0}; // destination cordinate
                SDL_BlitSurface(rotated_img, NULL, screen, &rect);                                          // naffiche l image jdida b rotate
                SDL_FreeSurface(rotated_img);
            }
        }
       else if (whichscreen == 1) // hedheya l block mta3 l input
        {
            if (SDL_GetTicks() - t_prev2 > 150) // kol 150 ms n affiche l menu input
            {
                afficher_menu_input(joueur1, screen);
                t_prev2 = SDL_GetTicks();
            }
            SDL_PollEvent(&event); // retrieves the next event from the event queue
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {

                case SDLK_ESCAPE:
                    done = 1;
                    break;
                }

                break;
                // lehna na9ra fel position mta3 souris wa9tili howa ya3mel fi click w nchoof howa ween nzel w na3mel l modification mta3 l input
            case SDL_MOUSEBUTTONDOWN:
                if (joueur1.up[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 305 && event.motion.y <= 352)
                {
                    joueur1.up[0] = 1;
                }
                else if (joueur1.up[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 304 && event.motion.y <= 356)
                {
                    joueur1.up[0] = 2;
                }
                if (joueur1.down[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 389 && event.motion.y <= 441)
                {
                    joueur1.down[0] = 1;
                }
                else if (joueur1.down[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 387 && event.motion.y <= 441)
                {
                    joueur1.down[0] = 2;
                }

                if (joueur1.right[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[0] = 1;
                }
                else if (joueur1.right[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[0] = 2;
                }
                if (joueur1.left[0] != 1 && event.motion.x >= 183 && event.motion.x <= 260 && event.motion.y >= 389 + 84 + 84 && event.motion.y <= 441 + 84 + 84)
                {
                    joueur1.left[0] = 1;
                }
                else if (joueur1.left[0] != 2 && event.motion.x >= 283 && event.motion.x <= 361 && event.motion.y >= 555 && event.motion.y <= 607)
                {
                    joueur1.left[0] = 2;
                }
                //***************************************************second player
                if (joueur1.up[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 305 && event.motion.y <= 352)
                {
                    joueur1.up[1] = 1;
                }
                else if (joueur1.up[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 304 && event.motion.y <= 356)
                {
                    joueur1.up[1] = 2;
                }
                if (joueur1.down[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 389 && event.motion.y <= 441)
                {
                    joueur1.down[1] = 1;
                }
                else if (joueur1.down[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 387 && event.motion.y <= 441)
                {
                    joueur1.down[1] = 2;
                }

                if (joueur1.right[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[1] = 1;
                }
                else if (joueur1.right[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 468 && event.motion.y <= 518)
                {
                    joueur1.right[1] = 2;
                }
                if (joueur1.left[1] != 1 && event.motion.x >= 916 && event.motion.x <= 990 && event.motion.y >= 389 + 84 + 84 && event.motion.y <= 441 + 84 + 84)
                {
                    joueur1.left[1] = 1;
                }
                else if (joueur1.left[1] != 2 && event.motion.x >= 1015 && event.motion.x <= 1093 && event.motion.y >= 555 && event.motion.y <= 607)
                {
                    joueur1.left[1] = 2;
                }

                break;
            }
        }
        SDL_Flip(screen); // mettre à jour la surface de l'écran
            break;
        }
    }
								break;
								case SDLK_b:
								p.score += 10;
								break;
								case SDLK_k:
								p.lives -= 1;
								break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            p.acceleration += 0.02;
                            p.direction = 2;
                            break;
                        case SDLK_RIGHT:
                        	 p.direction = 2;
                            p.acceleration -= 0.005;
                            break;
                           
                    }
                    break;
            }
        }
			if(p.direction == 2  && p.speed>0) p.speed -= 0.05; 
			if(state==1){
            afficherTic(tik,screen);
            if(tik.nbtour<9){
                if((tik.nbtour+tik.joueur)%2==0&&atilgagne(tik.tabSuiv)!=-1){
                    calcul_coup(tik.tabSuiv);
                    tik.nbtour++;
                }
                else{
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        x=(event.button.x-tik.bk.pos1.x)/(tik.bk.img->w/3);
                        y=(event.button.y-tik.bk.pos1.y)/(tik.bk.img->h/3);
                        coup=3*y+x;
                        if(tik.tabSuiv[coup]==0){
                            tik.tabSuiv[coup]=-1;
                            tik.nbtour++;
                        }
                    }
                }
            }
            if(atilgagne(tik.tabSuiv)!=0) {
                afficherTic(tik,screen);
                Resultat(tik,screen);
            }
        }
        movePlayer3(&p, dt);
        scrolling(&bg1,p.direction);
        dt = SDL_GetTicks() - t_prev;
			
			}
		}
		
	
		SDL_Flip(screen);
	}
	free_back(aniBACK);
	free_settings(aniSETTINGS);
	free_text(txte);
	liberer_image1(IMAGE_BTN1);
	liberer_image1(IMAGE_BTN2);
	liberer_image1(IMAGE_BTN3);
	TTF_Quit();
	/*serialport_flush(fd);
   serialport_close(fd);*/
	SDL_Quit();
	
	return 0;
}



