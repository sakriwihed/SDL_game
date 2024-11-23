prog:player.o serie.o main.o lot6.o ennemi.o minimap.o menu.o background.o
	gcc player.o serie.o menu.o lot6.o ennemi.o minimap.o background.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm -g
main.o:main.c player.h background.h menu.h
	gcc -c main.c -I. -g
player.o:player.c player.h 
	gcc -c player.c -I. -g
menu.o:menu.c menu.h 
	gcc -c menu.c -I. -g
background.o:background.c background.h player.h
	gcc -c background.c -I. -g
serie.o:serie.c serie.h
	gcc -c serie.c -I. -g
lot6.o:lot6.c lot6.h
	gcc -c lot6.c -I. -g
minimap.o:minimap.c minimap.h
	gcc -c minimap.c -I. -g
ennemi.o:ennemi.c ennemi.h
	gcc -c ennemi.c -I. -g
