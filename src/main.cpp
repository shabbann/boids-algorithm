
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include "iostream"
#include "SDL2/SDL_image.h"
#include "Renderer.hpp"
#include "bird.hpp"




int main( int argc, char* args[] )
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window;
    window.RenderWallpaper();
    window.Display();
    SDL_Texture *brdtri=window.Loadbrd("/home/ahmed/Boids-sdl2/assets/bird.png");
    bird brd(200,200,brdtri);

   //game loob
   SDL_Event e;
   bool quit = false;
   while(!quit){
       while( SDL_PollEvent(&e ) ){
                    if(e.type == SDL_QUIT ) quit = true;
       }
       window.RenderWallpaper();
       window.Render(brd);
       window.Display();

   }


    //Free resources and close SDL

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}





