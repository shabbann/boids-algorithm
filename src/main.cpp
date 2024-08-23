/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include "iostream"
#include "SDL2/SDL_image.h"
#include "Renderer.hpp"



int main( int argc, char* args[] )
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window;
    window.RenderWallpaper();
    window.Display();
   //game loob
   SDL_Event e;
   bool quit = false;
   while(!quit){
       while( SDL_PollEvent(&e ) ){
                    if(e.type == SDL_QUIT ) quit = true;
       }



   }


    //Free resources and close SDL


    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}