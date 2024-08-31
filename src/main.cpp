
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include "iostream"
#include "SDL2/SDL_image.h"
#include "Renderer.hpp"
#include "bird.hpp"
#include <stdint.h>
#include "vector"
#include "BoidsAlgorithm.hpp"
#include <cstdlib>
#define FPS 144






int main( int argc, char* argv[] )
{
    srand (time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window;
    std::vector<bird> birds;
    SDL_Texture *brdtri=window.Loadbrd("/home/ahmed/Boids-sdl2/assets/bird.png");
    for (int i = 0; i < BIRDSCOUNT; ++i) {
        bird brd((rand())%1280,rand()%720,brdtri);
        birds.push_back(brd);

    }
    float GlobalDeltaTime=0;
    float accumlated_time =0.0f;
    float cycle_time=1.0f/FPS;
    uint32_t last_frame_time = 0;

    ///////////////////////////////////////
    // game loob
    ///////////////////////////////////////
   SDL_Event e;
   bool quit = false;
   while(!quit){
       accumlated_time+=GlobalDeltaTime;


       while( SDL_PollEvent(&e ) ){
                    if(e.type == SDL_QUIT ) quit = true;
       }
        GlobalDeltaTime = (SDL_GetTicks() - last_frame_time) / 1000.0;
       // Store the milliseconds of the current frame to be used in the next one
       last_frame_time = SDL_GetTicks();

        if(cycle_time<=accumlated_time) {
            accumlated_time-=cycle_time;
            window.clear();
            window.RenderWallpaper();
            update(GlobalDeltaTime, birds);
            for (int i = 0; i < BIRDSCOUNT; ++i) {
                birds[i].move(cycle_time);
                window.Render(birds[i]);
            }
            window.Display();
        }
   }


    //Free resources and close SDL

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}





