#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "option.h"

void sounds(SDL_Surface *screen,Mix_Music *music,Mix_Chunk  *musicsourie)
{
SDL_Surface *back=NULL;
//button sound
SDL_Surface *prem=NULL;
SDL_Surface *deux=NULL;
SDL_Surface *trois=NULL;
SDL_Surface *quatre=NULL;
SDL_Surface *sound=NULL;
SDL_Surface *pause=NULL;
SDL_Surface *play=NULL;
SDL_Surface *sound1=NULL;
SDL_Surface *sound2=NULL;
SDL_Surface *barre=NULL;
SDL_Surface *moin=NULL;
SDL_Surface *moinnor=NULL;
SDL_Surface *moinzoom=NULL;
SDL_Surface *plus=NULL;
SDL_Surface *plusnor=NULL;
SDL_Surface *pluszoom=NULL;
SDL_Surface *retour=NULL;
SDL_Surface *retournor=NULL;
SDL_Surface *retourzoom=NULL;

// sourie
SDL_Surface *premsourie=NULL;
SDL_Surface *deuxsourie=NULL;
SDL_Surface *troissourie=NULL;
SDL_Surface *quatresourie=NULL;

SDL_Surface *barresourie=NULL;
SDL_Surface *moinsourie=NULL;
SDL_Surface *moinsourienor=NULL;
SDL_Surface *moinsouriezoom=NULL;
SDL_Surface *plussourie=NULL;
SDL_Surface *plussourienor=NULL;
SDL_Surface *plussouriezoom=NULL;
// sourie
int x =0; // coordonne sourie
int y=0 ;
int comp=3;
int compsourie=3;
//position button
SDL_Rect positionprem;
SDL_Rect positiondeux;
SDL_Rect positiontrois;
SDL_Rect positionquatre;
SDL_Rect positionecran;
SDL_Rect positionpause;
SDL_Rect positionplay;
SDL_Rect positionmoin;
SDL_Rect positionplus;

//position sourie music
SDL_Rect positionpremsourie;
SDL_Rect positiondeuxsourie;
SDL_Rect positiontroissourie;
SDL_Rect positionquatresourie;
SDL_Rect positionmoinsourie;
SDL_Rect positionplussourie;
SDL_Rect positionretour;
//screen
back = SDL_LoadBMP("image/option.bmp"); 
     positionecran.x = 0;
     positionecran.y=0;
     positionecran.w= back->w;
     positionecran.w= back->h;
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));//change l'ecran
SDL_BlitSurface(back, NULL, screen, &positionecran);
//retour
retournor  = IMG_Load("image/returnzoom.png");
retourzoom  = IMG_Load("image/return.png");
positionretour.x=10;
positionretour.y=10;
positionretour.w = retournor->w;
positionretour.h = retournor->h;
retour = retournor;
SDL_BlitSurface(retour, NULL, screen, &positionretour);
//load image 
moinnor  = IMG_Load("image/moin.png");
moinzoom  = IMG_Load("image/moinzoom.png");
positionmoin.x=62;
positionmoin.y=553.3;
positionmoin.w = moinnor->w;
positionmoin.h = moinnor->h;
moin=moinnor;
SDL_BlitSurface(moinnor, NULL, screen, &positionmoin);

//plus
plusnor  = IMG_Load("image/plus.png");
pluszoom  = IMG_Load("image/pluszoom.png");
positionplus.x=354;
positionplus.y=540;
positionplus.w = plusnor->w;
positionplus.h = plusnor->h;
plus = plusnor;
SDL_BlitSurface(moinnor, NULL, screen, &positionmoin);

prem  = IMG_Load("image/1er.png");
positionprem.x=42;
positionprem.y=582.3;
positionprem.w = prem->w;
positionprem.h = prem->h;

deux = IMG_Load("image/2eme.png");
positiondeux.x=42;
positiondeux.y=582.3;
positiondeux.w = deux->w;
positiondeux.h = deux->h;

trois = IMG_Load("image/3eme.png");
positiontrois.x=42;
positiontrois.y=582.3;
positiontrois.w = trois->w;
positiontrois.h = trois->h;

quatre = IMG_Load("image/4eme.png");
positionquatre.x=42;
positionquatre.y=582.3;
positionquatre.w = quatre->w;
positionquatre.h = quatre->h;
barre=quatre;

//sourie sound
moinsourienor  = IMG_Load("image/moinsourie.png");
moinsouriezoom  = IMG_Load("image/moinzoomsourie.png");
positionmoinsourie.x=84;
positionmoinsourie.y=375;
positionmoinsourie.w = moinsourienor->w;
positionmoinsourie.h = moinsourienor->h;
moinsourie = moinsourienor;
SDL_BlitSurface(moinsourienor, NULL, screen, &positionmoinsourie);

//plus
plussourienor  = IMG_Load("image/plussourie.png");
plussouriezoom  = IMG_Load("image/pluszoomsourie.png");
positionplussourie.x=374;
positionplussourie.y=370;
positionplussourie.w = plussourienor->w;
positionplussourie.h = plussourienor->h;
plussourie=plussourienor;
SDL_BlitSurface(plussourie, NULL, screen, &positionplussourie);

premsourie  = IMG_Load("image/1ersourie.png");
positionpremsourie.x=62;
positionpremsourie.y=412.3;
positionpremsourie.w = premsourie->w;
positionpremsourie.h = premsourie->h;

deuxsourie = IMG_Load("image/2emesourie.png");
positiondeuxsourie.x=62;
positiondeuxsourie.y=412.3;
positiondeuxsourie.w = deuxsourie->w;
positiondeuxsourie.h = deuxsourie->h;

troissourie = IMG_Load("image/3emesourie.png");
positiontroissourie.x=62;
positiontroissourie.y=412.3;
positiontroissourie.w = troissourie->w;
positiontroissourie.h = troissourie->h;

quatresourie = IMG_Load("image/4emesourie.png");
positionquatresourie.x=62;
positionquatresourie.y=412.3;
positionquatresourie.w = quatresourie->w;
positionquatresourie.h = quatresourie->h;
barresourie=quatresourie;

int z=4; //pour les fleche
//SDL_BlitSurface(quatre, NULL, screen, &positionquatre);

pause = IMG_Load("image/soundcoup.png");
positionpause.x=1000;
positionpause.y=10;
positionpause.w = pause->w;
positionpause.h = pause->h;

play = IMG_Load("image/sound.png");
positionplay.x=1000;
positionplay.y=10;
positionplay.w = play->w;
positionplay.h = play->h;
sound=play;

sound2 = IMG_Load("image/sound1.png");
positionplay.x=1000;
positionplay.y=10;
positionplay.w = play->w;
positionplay.h = play->h;


sound1 = IMG_Load("image/sound2.png");
positionplay.x=1000;
positionplay.y=10;
positionplay.w = play->w;
positionplay.h = play->h;
SDL_Flip(screen);
int contu=1;
 
while(contu)
{
  SDL_Event event; 
  while(SDL_PollEvent(&event))
   {
     switch(event.type)
    {
      case SDL_QUIT:
      contu=0;
      
      break;

       case SDL_KEYDOWN:
        { //initialisation
         
          switch(event.key.keysym.sym)
           {
               //keybord press
             case SDLK_BACKSPACE: // boutton suprimer
               {
                 contu=0; //exit
               }
             break;
              case SDLK_p:
                {
                    Mix_PlayChannel( -1, musicsourie, 0 );
                  if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                       
                        Mix_ResumeMusic(); //Reprendre la musique
                           Mix_Resume(-1);

                      Mix_VolumeMusic(MIX_MAX_VOLUME);
                        sound=play;
                         barre=quatre;
                       comp=3;//compteur moin
                    }
                    else
                    {
                        Mix_Pause(-1);//chunk 

                      Mix_PauseMusic(); //Mettre en pause la musique
                        sound=pause;
                         barre=prem;
                           comp=1;
                    }
                }
             break;
              case SDLK_KP1:
                {
                        Mix_PlayChannel( -1, musicsourie, 0 );
                 
                        comp=1;//pour moin
                        sound=pause;                   
                      barre=prem;
                          Mix_PauseMusic(); //Mettre en pause la musique
                       

                 }
               break;
             case SDLK_KP2:
              {
                    Mix_PlayChannel( -1, musicsourie, 0 );
                 if(Mix_PausedMusic() == 1)//Si la musique est en pause
                         {
                       
                        Mix_ResumeMusic(); //Reprendre la musique

                         }
                               
                                   sound=sound1;
                 Mix_VolumeMusic(MIX_MAX_VOLUME/6);
                      barre=deux;
                   comp=1;

               }
               break;
             case SDLK_KP3:
                {
                      Mix_PlayChannel( -1, musicsourie, 0 );
                    if(Mix_PausedMusic() == 1)//Si la musique est en pause
                         {
                       
                        Mix_ResumeMusic(); //Reprendre la musique
                         
                         }
                            sound=sound2;
                 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
                      barre=trois;   
                      comp=2;  
                 }
               break;
               case SDLK_KP4:
                   {
                       Mix_PlayChannel( -1, musicsourie, 0 );
                                      if(Mix_PausedMusic() == 1)//Si la musique est en pause
                         {
                       
                        Mix_ResumeMusic(); //Reprendre la musique

                         }
          
                       Mix_VolumeMusic(MIX_MAX_VOLUME);
                      sound=play;
                      barre=quatre; 
                         comp=3;    
                    }
               break;
                  
               
            }//switch keyboard
          } //sdl key
       break;
        case SDL_MOUSEBUTTONDOWN:
      {
             Mix_PlayChannel( -1, musicsourie, 0 );
       if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
          {
            
             SDL_GetMouseState(&x, &y);// initialisation coordonne sourie
                   //music
             if ((x >= positionplay.x ) && ( x <= (positionplay.x + positionplay.w) ) && (y >= positionplay.y ) && ( y <= (positionplay.y + positionplay.h)))//si en pause
              {
                   if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                       
                        Mix_ResumeMusic(); //Reprendre la musique
                         Mix_VolumeMusic(MIX_MAX_VOLUME);
                        sound=play;
                         barre=quatre;
                    }
                    else
                    {
                      Mix_PauseMusic(); //Mettre en pause la musique
                         sound=pause;
                         barre=prem;
                    }

             }
          if ((x >= positionmoin.x ) && ( x <= (positionmoin.x + positionmoin.w) ) && (y >= positionmoin.y ) && ( y <= (positionmoin.y + positionmoin.h)))//moin
                        {
                            
                            if(comp==1)
                                   {
                                      sound=pause;                   
                                    barre=prem;
                                  comp=1;
                          Mix_PauseMusic(); //Mettre en pause la musique
                       
                                   }
                              else if(comp==2)
                                 {
                                    if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                   {
                                        Mix_ResumeMusic(); //Reprendre la musique
                                      }
                                  sound=sound1;
                               Mix_VolumeMusic(MIX_MAX_VOLUME/6);
                                barre=deux;
                                 comp=1;
                                  }
                              else if(comp==3)
                                 {
                                   if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                    {
                                       Mix_ResumeMusic(); //Reprendre la musique
                         
                                       }
                                sound=sound2;
                            Mix_VolumeMusic(MIX_MAX_VOLUME/3);
                                barre=trois;     
                                    comp=2;
                                 }
            }//moin
          if ((x >= positionplus.x ) && ( x <= (positionplus.x + positionplus.w) ) && (y >= positionplus.y ) && ( y <= (positionplus.y + positionplus.h)))//plus
                        {
                            
                            if(comp==1)
                                   {
                                    if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                   {
                                        Mix_ResumeMusic(); //Reprendre la musique
                                     }
         
                                  sound=sound1;
                              Mix_VolumeMusic(MIX_MAX_VOLUME/6);
                                  barre=deux;
                                   comp=2;
                       
                                   }
                              else if(comp==2)
                                 {
                                    if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                   {
                                        Mix_ResumeMusic(); //Reprendre la musique
                                     }
                                sound=sound2;
                                Mix_VolumeMusic(MIX_MAX_VOLUME/3);
                                  barre=trois;   
                                   comp=3;  
                                  }
                              else if(comp==3)
                                 {
                                   if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                    {
                                       Mix_ResumeMusic(); //Reprendre la musique
                         
                                       }
                                 
                         Mix_VolumeMusic(MIX_MAX_VOLUME);
                        sound=play;
                         barre=quatre;
                             comp=3;
                                }
            }//plus
               //sourie
          if ((x >= positionmoinsourie.x ) && ( x <= (positionmoinsourie.x + positionmoinsourie.w) ) && (y >= positionmoinsourie.y ) && ( y <= (positionmoinsourie.y + positionmoinsourie.h)))//moin
                        {
                            
                            if(compsourie==1)
                                   {
                                                        
                                    barresourie=premsourie;
                                  compsourie=1;
                          Mix_Pause(-1); //Mettre en pause la musique
                       
                                   }
                              else if(compsourie==2)
                                 {

                                   
                                        Mix_Resume(-1); //Reprendre la musique
                                      
                                  
                               Mix_VolumeChunk(musicsourie,MIX_MAX_VOLUME/6);
                                barresourie=deuxsourie;
                                 compsourie=1;
                                  }
                              else if(compsourie==3)
                                 {


                                       Mix_Resume(-1); //Reprendre la musique
                         
                                       

                            Mix_VolumeChunk(musicsourie,MIX_MAX_VOLUME/3);
                                barresourie=troissourie;     
                                    compsourie=2;
                                 }
            }//moin
          if ((x >= positionplussourie.x ) && ( x <= (positionplussourie.x + positionplussourie.w) ) && (y >= positionplussourie.y ) && ( y <= (positionplussourie.y + positionplussourie.h)))//plus
                        {
                            
                            if(compsourie==1)
                                   {


                                        Mix_Resume(-1); //Reprendre la musique
                                     
         

                              Mix_VolumeChunk(musicsourie,MIX_MAX_VOLUME/6);
                                  barresourie=deuxsourie;
                                   compsourie=2;
                       
                                   }
                              else if(compsourie==2)
                                 {

                                   
                                        Mix_Resume(-1); //Reprendre la musique
                                     

                                Mix_VolumeChunk(musicsourie,MIX_MAX_VOLUME/3);
                                  barresourie=troissourie;   
                                   compsourie=3;  
                                  }
                              else if(comp==3)
                                 {

                                    
                                      Mix_Resume(-1);   //Reprendre la musique
                         
                                       
                                 
                         Mix_VolumeChunk(musicsourie,MIX_MAX_VOLUME);

                         barresourie=quatresourie;
                             compsourie=3;
                                }
            }//moin
                      //return to menu
          if ((x >= positionretour.x ) && ( x <= (positionretour.x + positionretour.w) ) && (y >= positionretour.y ) && ( y <= (positionretour.y + positionretour.h)))//plus
                        {
                            
                         contu=0;   
            }            

          }// if clic gauche
       }//case sourie
      break;
       case SDL_MOUSEMOTION: //si on bouge la sourie
       {
             // initialisation coordonne sourie
             if ((event.motion.x >= positionplus.x ) && ( event.motion.x <= (positionplus.x + positionplus.w) ) && (event.motion.y >= positionplus.y ) && ( event.motion.y <= (positionplus.y +positionplus.h))) //music

              {    
                 plus=pluszoom;
                 
                          SDL_Flip(screen);
               
              }
            else if ((event.motion.x >= positionmoin.x ) && ( event.motion.x <= (positionmoin.x + positionmoin.w) ) && (event.motion.y >= positionmoin.y ) && ( event.motion.y <= (positionmoin.y + positionmoin.h)))//moinmusic

              {    
                 moin=moinzoom;
                 
                          SDL_Flip(screen);
               
              }
          
                //sound sourie
            else if ((event.motion.x >= positionplussourie.x ) && ( event.motion.x <= (positionplussourie.x + positionplussourie.w) ) && (event.motion.y >= positionplussourie.y ) && ( event.motion.y <= (positionplussourie.y + positionplussourie.h)))//plus

              {    
                 plussourie=plussouriezoom;
                 
                          SDL_Flip(screen);
               
              }
              
           else  if ((event.motion.x >= positionmoinsourie.x ) && ( event.motion.x <= (positionmoinsourie.x + positionmoinsourie.w) ) && (event.motion.y >= positionmoinsourie.y ) && ( event.motion.y <= (positionmoinsourie.y + positionmoinsourie.h)))//moin

              {    
                 moinsourie=moinsouriezoom;
                 
                          SDL_Flip(screen);
               
              }
           else  if ((event.motion.x >= positionretour.x ) && ( event.motion.x <= (positionretour.x + positionretour.w) ) && (event.motion.y >= positionretour.y ) && ( event.motion.y <= (positionretour.y + positionretour.h)))//moin

              {    
                 retour=retournor;
                 
                          SDL_Flip(screen);
               
              }

         else 
            {
            plus=plusnor;
                 moin=moinnor;  
                 plussourie=plussourienor;   
                 moinsourie=moinsourienor; 
             retour=retourzoom ;     
                                   SDL_Flip(screen);
             }
        }
       break;
      }//switch event
   }//while 2 = event

    SDL_BlitSurface(back, NULL, screen, &positionecran);

SDL_BlitSurface(moin, NULL, screen, &positionmoin);
SDL_BlitSurface(barre, NULL, screen, &positionprem);
SDL_BlitSurface(plussourie, NULL, screen, &positionplussourie);
SDL_BlitSurface(moinsourie, NULL, screen, &positionmoinsourie);
SDL_BlitSurface(barresourie, NULL, screen, &positionpremsourie);
  SDL_BlitSurface(sound, NULL, screen, &positionplay);
SDL_BlitSurface(retour, NULL, screen, &positionretour);
SDL_BlitSurface(plus, NULL, screen, &positionplus);
  SDL_Flip(screen);  
}//while done

//SDL_FreeSurface(image);

SDL_FreeSurface(prem);
SDL_FreeSurface(deux);
SDL_FreeSurface(trois);
SDL_FreeSurface(quatre);
SDL_FreeSurface(premsourie);
SDL_FreeSurface(deuxsourie);
SDL_FreeSurface(troissourie);
SDL_FreeSurface(quatresourie);
SDL_FreeSurface(back);



}
