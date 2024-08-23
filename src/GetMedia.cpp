#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "iostream"

bool loadMedia(SDL_Surface** LOADED){
    //Loading success flag
    bool success = true;
    int IMG=IMG_INIT_JPG;
    if(!IMG_Init(IMG)){
        std::cout<<"IMG FAILED TO LOAD\t"<<SDL_GetError()<<std::endl;
    }


    //Load splash image
    *LOADED = IMG_Load( "/home/ahmed/Boids-sdl2/assets/Boid_wallPaper.jpeg" );
    if( LOADED == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;


};