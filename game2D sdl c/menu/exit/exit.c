#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "exit.h"


int exi (SDL_Surface *screen,Mix_Chunk  *musicsourie)
{
 SDL_Surface *image=NULL;
SDL_Surface *no=NULL;
SDL_Surface *nonor=NULL;
SDL_Surface *nozoom=NULL;
SDL_Surface *yes=NULL;
SDL_Surface *yesnor=NULL;
SDL_Surface *yeszoom=NULL;
SDL_Rect positionecran;
SDL_Rect positionno;
SDL_Rect positionyes;
 image = IMG_Load("image/exitmenu.png"); 
     positionecran.x = 0;
     positionecran.y=0;
     positionecran.w= image->w;
     positionecran.w= image->h;
//no
nonor = IMG_Load("image/no.png"); 
nozoom = IMG_Load("image/nozoom.png"); 
     positionno.x = 385;
     positionno.y=320;
     positionno.w= nonor->w;
     positionno.w= nonor->h;
no=nonor;

//yes
yesnor = IMG_Load("image/yes.png"); 
yeszoom = IMG_Load("image/yeszoom.png"); 
     positionyes.x = 604;
     positionyes.y=320;
     positionyes.w= yesnor->w;
     positionyes.w= yesnor->h;
yes=yesnor;

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));//change l'ecran
SDL_BlitSurface(image, NULL, screen, &positionecran);
  SDL_Flip(screen);  
int x = 0;
int y = 0;
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
               //keybord press
             case SDLK_y: // boutton suprimer
               {
                    Mix_PlayChannel( -1, musicsourie, 0 );
                 quit=0; //exit
                   return 0;
               }
             break;
             case SDLK_n: // boutton suprimer
               {
                   Mix_PlayChannel( -1, musicsourie, 0 );
                 quit=0; //exit
                   return 1;
               }
             break;
            }
          }
        break; //sdlkeydown 
        case SDL_MOUSEBUTTONDOWN:
      {
             Mix_PlayChannel( -1, musicsourie, 0 );
       if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
          {
            
             SDL_GetMouseState(&x, &y);// initialisation coordonne sourie
                   
             if ((x >= positionno.x ) && ( x <= (positionno.x + positionno.w) ) && (y >= positionno.y ) && ( y <= (positionno.y + positionno.h)))//no
              {
                   quit=0; //exit
                   return 1;
                 }
             if ((x >= positionyes.x ) && ( x <= (positionyes.x + positionyes.w) ) && (y >= positionyes.y ) && ( y <= (positionyes.y + positionyes.h)))//yes
              {
                     quit=0; //exit
                   return 0;
                 }
      
           }
       }//casemousedown
       case SDL_MOUSEMOTION: //si on bouge la sourie
       {
             // initialisation coordonne sourie
             if ((event.motion.x >= positionyes.x ) && ( event.motion.x <= (positionyes.x + positionyes.w) ) && (event.motion.y >= positionyes.y ) && ( event.motion.y <= (positionyes.y+positionyes.h))) //music

              {    
                 yes=yeszoom;
                 
                          SDL_Flip(screen);
               
              }
            else if ((event.motion.x >= positionno.x ) && ( event.motion.x <= (positionno.x + positionno.w) ) && (event.motion.y >= positionno.y ) && ( event.motion.y <= (positionno.y +positionno.h))) //music

              {    
                 no=nozoom;
                 
                          SDL_Flip(screen);
               
              }
           else
              {
                   yes=yesnor;
                   no = nonor;
               }
         }
      }
    }
SDL_BlitSurface(yes, NULL, screen, &positionyes);
SDL_BlitSurface(no, NULL, screen, &positionno);
  SDL_Flip(screen);  
 }
SDL_FreeSurface(image);
SDL_FreeSurface(yesnor);
SDL_FreeSurface(nonor);
SDL_FreeSurface(yeszoom);
SDL_FreeSurface(nozoom);
SDL_FreeSurface(yes);
SDL_FreeSurface(no);
SDL_FreeSurface(screen);

}
