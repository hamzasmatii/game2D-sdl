#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "play.h"

SDL_Rect postionecran;
void jouer (SDL_Surface *screen)
{
 SDL_Surface *image=NULL;

 image = IMG_Load("image/menuplay.png"); 
     postionecran.x = 0;
     postionecran.y=0;
     postionecran.w= image->w;
     postionecran.w= image->h;

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));//change l'ecran
SDL_BlitSurface(image, NULL, screen, &postionecran);
  SDL_Flip(screen);  
int quit=1;
while(quit)
{
  SDL_Event event; 
  while(SDL_PollEvent(&event))
   {
     switch(event.type)
    {
      case SDL_QUIT:
      quit=0;
      
      break;

       case SDL_KEYDOWN:
        { //initialisation
          
          switch(event.key.keysym.sym)
           {
               //keybord press
             case SDLK_BACKSPACE: // boutton suprimer
               {
                 quit=0; //exit
               }
             break;
            }
          } 
      }
    }

  SDL_Flip(screen);  
 }
SDL_FreeSurface(image);
SDL_FreeSurface(screen);

}
