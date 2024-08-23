#include "SDL.h"
bool init(SDL_Window ** window){
    bool success=true;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        success= false;
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );

    }
    else{
        *window= SDL_CreateWindow(
                "Hello World 2",
                0,
                0,
                1280,
                720,
                SDL_WINDOW_SHOWN
        );
        if( window == nullptr )
        {
            success= false;
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }

        return success;


}}