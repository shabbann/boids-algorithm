
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "SDL2/SDL_image.h"
#include "Renderer.hpp"
#include "bird.hpp"
#include <stdint.h>
#include <vector>
#include "BoidsAlgorithm.hpp"
#include <cstdlib>
#include "const.hpp"

int main( int argc, char* argv[] )
{
    srand (int(time(NULL)));
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window;
    std::vector<bird> birds;SDL_Point birdsize(4,5);
    std::vector<bird> predators;SDL_Point PREDsize(6,9);
    SDL_Texture *brdtri=window.Loadbrd("assets/bird.png");
    for (int i = 0; i < BIRDSCOUNT; ++i) {
        bird brd((rand())%1280,rand()%720,brdtri);
        birds.push_back(brd);
    }
    SDL_Texture *predtri=window.Loadbrd("assets/PRED.png");
    for (int i = 0; i < PREDCOUNT; ++i) {
        bird pred((rand())%1280,rand()%720,predtri);
        predators.push_back(pred);
    }
    double GlobalDeltaTime=0;
    float_t accumulated_time =0.0f;
    constexpr float_t cycle_time=1.0f/FPS;
    uint32_t last_frame_time = 0;
    ///////////////////////////////////////
    // game loob
    ///////////////////////////////////////
      SDL_Event e;
      bool quit = false;
      while(!quit){
       while( SDL_PollEvent(&e ) ){
                    if(e.type == SDL_QUIT ) quit = true;
       }
       //TODO make better delta time and fixed frame rate
        accumulated_time+=GlobalDeltaTime;
        GlobalDeltaTime = (SDL_GetTicks() - last_frame_time) / 1000.0;
        //std::cout<<int(1.0f/GlobalDeltaTime)<<std::endl;
        last_frame_time = SDL_GetTicks();
        if(cycle_time < accumulated_time) {
            accumulated_time-=cycle_time;
            if(GlobalDeltaTime>cycle_time)
                simulate(GlobalDeltaTime,birds,predators);
            else
                simulate(cycle_time,birds,predators);

        }
          window.clear();
          window.RenderWallpaper();
          for (int i = 0; i < BIRDSCOUNT; ++i) {
              window.Render(birds[i],birdsize);
          }
          for (int i = 0; i < PREDCOUNT; ++i) {
              window.Render(predators[i],PREDsize);
          }
          window.Display();
   }
    //Free resources and close SDL
    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}





