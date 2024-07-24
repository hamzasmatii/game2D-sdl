#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu/play/play.h"
#include "menu/option/option.h"
#include "menu/exit/exit.h"



int main (void)
{
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
//music
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}
Mix_Music *music;
Mix_Chunk  *musicsourie;
musicsourie=Mix_LoadWAV("music/sourie.wav");
music=Mix_LoadMUS("music/music.mp3");
Mix_PlayMusic(music,-1);

Mix_VolumeMusic(MIX_MAX_VOLUME);
SDL_Surface *screen=NULL; //reference the backbuffer 
SDL_Surface *image=NULL; //reference our background
SDL_Surface *play=NULL ;// rference our play
SDL_Surface *option=NULL ;// rference our option
SDL_Surface *exit=NULL ;// rference our exit
SDL_Surface *size=NULL;
SDL_Surface *full=NULL;
SDL_Surface *res=NULL;
SDL_Surface *fullnor=NULL;
SDL_Surface *fullzoom=NULL;
SDL_Rect positionecran; //rect to describe the source destination region of our blit
SDL_Rect positionplay; // position icon play
SDL_Rect positionoption; //position icon option
SDL_Rect positionexit; // position icon exit
SDL_Rect positionsize; 
    SDL_Rect positiontext;//text
int a=1;
int b=1;

//gif


//pour changement boutton menu
SDL_Surface *buttonplay=NULL;
SDL_Surface *buttonoption=NULL;
SDL_Surface *buttonexit=NULL;

//zoom button
SDL_Surface *playzoom=NULL ;
SDL_Surface *optionzoom=NULL ;
SDL_Surface *exitzoom=NULL ;

SDL_Rect positionplayzoom;
SDL_Rect positionoptionzoom;
SDL_Rect positionexitzoom;
char pause;
int x =0; // coordonne sourie
int y=0 ;
//text
SDL_Surface *text=NULL;
TTF_Font *font=NULL;
SDL_Color couleur = {0,0,55};//couleur texte


if (SDL_Init(SDL_INIT_VIDEO) !=0)
{
printf("Unable to initialize SDL : %s\n",SDL_GetError());
return 1;
}

 //SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));//change l'ecran
screen=SDL_SetVideoMode( 1100, 807, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
if (screen==NULL)

{printf("Unable to set video mode :%s\n",SDL_GetError());
return 1;
}

//load the bitmap into the image surface, and check for success
  image = SDL_LoadBMP("image/background.bmp"); //you can use IMG_Load
    positionecran.x = 0;
     positionecran.y=0;
positionecran.w= image->w;
positionecran.w= image->h;
SDL_BlitSurface(image, NULL, screen, &positionecran);


 //text

positiontext.x =300;
     positiontext.y=40;
font=TTF_OpenFont("AIRLOCK.TTF",32);//1er paramettre font et 2eme taille
text=TTF_RenderText_Solid(font,"DONT FORGET TO COME BACK",couleur);//ecrire txt
SDL_BlitSurface(text, NULL, screen, &positiontext);
SDL_Flip(screen);
//play
play=IMG_Load("image/play.png");
positionplay.x=300;
positionplay.y=170;
positionplay.w = play->w;
positionplay.h = play->h;
buttonplay=play;
SDL_BlitSurface(buttonplay, NULL, screen,&positionplay); 
//option
option=IMG_Load("image/option.png");
positionoption.x=300;
positionoption.y=400;
positionoption.w = option->w;
positionoption.h = option->h;
buttonoption=option;
SDL_BlitSurface(buttonoption, NULL, screen,&positionoption); 

//exit
exit=IMG_Load("image/exit.png");
positionexit.x=300;
positionexit.y=630;
positionexit.w = exit->w;
positionexit.h = exit->h;
buttonexit=exit;
SDL_BlitSurface(buttonexit, NULL, screen,&positionexit); 
//playzoom
playzoom=IMG_Load("image/playzoom.png");
positionplayzoom.x=300;
positionplayzoom.y=170;
positionplayzoom.w = playzoom->w;
positionplayzoom.h = playzoom->h;
//optionzoom
optionzoom=IMG_Load("image/optionzoom.png");
positionoptionzoom.x=300;
positionoptionzoom.y=400;
positionoptionzoom.w = optionzoom->w;
positionoptionzoom.h = optionzoom->h;
//exitzoom
exitzoom=IMG_Load("image/exitzoom.png");
positionexitzoom.x=300;
positionexitzoom.y=630;
positionexitzoom.w = exitzoom->w;
positionexitzoom.h = exitzoom->h;
//full
fullnor=IMG_Load("image/full.png");
fullzoom=IMG_Load("image/fullzoom.png");
full=fullnor;
//res

res=IMG_Load("image/res.png");
positionsize.x=1000;
positionsize.y=10;
positionsize.w = full->w;
positionsize.h = full->h;
 size=full;

  SDL_BlitSurface(size, NULL, screen,&positionsize);
//flip the backbuffer to the primary hardware vidio memory 
     SDL_Flip(screen);
//release the surface 
    
pause = getchar();
//control

int done=1;

while(done)
{
  SDL_Event event; 
  while(SDL_PollEvent(&event))
   {
     switch(event.type)
    {
      case SDL_QUIT:
      done=0;
      
      break;

       case SDL_KEYDOWN:
        { 
                 
          switch(event.key.keysym.sym)
           {
               //keybord press
             case SDLK_ESCAPE: // boutton echap
               {
                  done= exi (screen,musicsourie);
               }
             break;

             case SDLK_p: // boutton "p" pour play
               {
                 Mix_PlayChannel( -1, musicsourie, 0 );
                 jouer(screen);
                         SDL_Flip(screen);
               }
             break;
        
            case SDLK_o: //boutton "o" pour option
              {
                      Mix_PlayChannel( -1, musicsourie, 0 );
                  sounds(screen,music,musicsourie);  
                              SDL_Flip(screen);          
              }
            break;

            case SDLK_e: //boutton "e" pour exit
             {
                done= exi (screen,musicsourie); //exit
             }
           break;
               case SDLK_f:
                    {
                       Mix_PlayChannel( -1, musicsourie, 0 );
                      screen=SDL_SetVideoMode( 1100, 807, 24, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
                       x =0;
                     y = 0;
                     SDL_GetMouseState(&x, &y);
                      size=res;
                     }
                    break;
                     case SDLK_r:
                    { 
                          Mix_PlayChannel( -1, musicsourie, 0 );
                    screen=SDL_SetVideoMode( 1100, 807, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
                    x =0;
                     y = 0;
                     SDL_GetMouseState(&x, &y);
                      size=full;
                      }
                     break;
                 case SDLK_DOWN:
                    {
                              Mix_PlayChannel( -1, musicsourie, 0 );
            		if(a==1)
			
				{
					 buttonplay=playzoom;
                                    buttonoption=option;
                               buttonexit=exit;

                          SDL_Flip(screen);
					a=2,b=1;
					
				}
			
			else  if(a==2)
				{
                                    buttonplay=play;
                                      buttonoption=option;
					buttonoption=optionzoom;  
                                       SDL_Flip(screen); 						
					a=3,b=2;		
				}
			else if(a==3)
					{
                                                        buttonplay=play;
                                       buttonoption=option;
				  	  buttonexit=exitzoom;
                                        SDL_Flip(screen);
					a=1,b=3;			
					}
                     else {
                            buttonplay=play;
                          buttonoption=option;
                           buttonexit=exit;
               
                      SDL_Flip(screen);
             
                           }
                     }
                   break;

               case SDLK_RETURN:
                  {
                     Mix_PlayChannel( -1, musicsourie, 0 );
             		if(b==1)
			
				{
					jouer(screen);
                         SDL_Flip(screen);
					
					
				}
			
			else  if(b==2)
				{
					  sounds(screen,music,musicsourie); 
                        SDL_Flip(screen);						
							
				}
			else if(b==3)
					{
					done= exi (screen,musicsourie);
                        SDL_Flip(screen);
								
					}
                     else {
                            buttonplay=play;
               buttonoption=option;
               buttonexit=exit;
               
                      SDL_Flip(screen);
             
                           }
                    }
                   break;                
          }//switch keybord
        }//case keydown
      break;

      //sourie press
     case SDL_MOUSEBUTTONDOWN:
      {
           Mix_PlayChannel( -1, musicsourie, 0 );
       if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
          {
            
             SDL_GetMouseState(&x, &y);// initialisation coordonne sourie
             if ((x >= positionplay.x ) && ( x <= (positionplay.x + positionplay.w) ) && (y >= positionplay.y ) && ( y <= (positionplay.y + positionplay.h)))//play

              {   
                      
                    jouer(screen);//fonction jouer
                              SDL_Flip(screen);
              }
             else if ((x >= positionoption.x ) && ( x <= (positionoption.x + positionoption.w) ) && (y >= positionoption.y ) && ( y <= (positionoption.y + positionoption.h)))//option
              {
                  sounds(screen,music,musicsourie);
                           SDL_Flip(screen);
              
              }
            else if ((x >= positionexit.x ) && ( x <= (positionexit.x + positionexit.w) ) && (y >= positionexit.y ) && ( y <= (positionexit.y + positionexit.h)))//quitter

             {
    
              done= exi (screen,musicsourie); //exit
             }  
            else if ((x >= positionsize.x ) && ( x <= (positionsize.x + positionsize.w) ) && (y >= positionsize.y ) && ( y <= (positionsize.y + positionsize.h)))//size

             { 
                  if(size==res)
                         {
                             screen=SDL_SetVideoMode( 1100, 807, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
                                 size=full;
                              
                            }
                  else if(size==full)
                        {
                      screen=SDL_SetVideoMode( 1100, 807, 24, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
                 size=res;
                             }
               }
          
                
          }// if clic gauche
       }//case sourie
       break;
          //sourie effet (si on bouge la sourie)
       case SDL_MOUSEMOTION: //si on bouge la sourie
       {
             // initialisation coordonne sourie
             if ((event.motion.x >= positionplay.x ) && ( event.motion.x <= (positionplay.x + positionplay.w) ) && (event.motion.y >= positionplay.y ) && ( event.motion.y <= (positionplay.y + positionplay.h)))//play

              {    
                 buttonplay=playzoom;
                          SDL_Flip(screen);
               
              }
            
             else if ((event.motion.x >= positionoption.x ) && ( event.motion.x <= (positionoption.x + positionoption.w) ) && (event.motion.y >= positionoption.y ) && ( event.motion.y <= (positionoption.y + positionoption.h)))//option
              {
                 buttonoption=optionzoom;
                        SDL_Flip(screen);
              }
            else if ((event.motion.x >= positionexit.x ) && ( event.motion.x <= (positionexit.x + positionexit.w) ) && (event.motion.y >= positionexit.y ) && ( event.motion.y <= (positionexit.y + positionexit.h)))//quitter

             {
               
                 buttonexit=exitzoom;
	
                        SDL_Flip(screen);
                  
             } 
            else if ((event.motion.x >= positionsize.x ) && ( event.motion.x <= (positionsize.x + positionsize.w) ) && (event.motion.y >= positionsize.y ) && ( event.motion.y <= (positionsize.y + positionsize.h)))//quitter

             {
               
                 full=fullzoom;
	
                        SDL_Flip(screen);
                  
             } 
            
            else
            {
                 
               buttonplay=play;
               buttonoption=option;
               buttonexit=exit;
                full=fullnor;
                      SDL_Flip(screen);
            }
            
       } //case sourie  
        break;
    } //switch = event.type
  }//while2 = event

SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_BlitSurface(text, NULL, screen, &positiontext);
SDL_BlitSurface(buttonplay, NULL, screen,&positionplay); 
SDL_BlitSurface(buttonoption, NULL, screen,&positionoption); 
SDL_BlitSurface(buttonexit, NULL, screen,&positionexit);
      SDL_BlitSurface(full, NULL, screen,&positionsize); 
     SDL_BlitSurface(size, NULL, screen,&positionsize); 
SDL_Flip(screen);
}//while1 = done
//release the surface
SDL_FreeSurface(screen); 
SDL_FreeSurface(option);
SDL_FreeSurface(size);
SDL_FreeSurface(exit);
SDL_FreeSurface(play);
SDL_FreeSurface(buttonplay);
SDL_FreeSurface(buttonoption);
SDL_FreeSurface(buttonexit);
SDL_FreeSurface(playzoom);
SDL_FreeSurface(optionzoom);
SDL_FreeSurface(exitzoom);
SDL_FreeSurface(full);
Mix_FreeMusic(music);


SDL_FreeSurface(text);
SDL_Quit();
//return success!
return 0;
}
