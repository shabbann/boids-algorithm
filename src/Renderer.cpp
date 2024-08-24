#include "Renderer.hpp"
#include "SDL2/SDL_image.h"
#include "iostream"
#include "vector"


RenderWindow::RenderWindow() : window(NULL), renderer(NULL)
{

    window= SDL_CreateWindow(title.c_str(),0,0,1280,720,SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    WallPaper= LoadTexture("/home/ahmed/Boids-sdl2/assets/wallpaper.png");
}

SDL_Texture *RenderWindow::LoadTexture(std::string path) {
    //The final texture
    SDL_Texture* newTexture = NULL;
    newTexture = IMG_LoadTexture(renderer,path.c_str());
    if( newTexture == NULL )
    {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return newTexture;

}

void RenderWindow::RenderWallpaper() {
    SDL_RenderCopy( renderer, WallPaper, NULL, NULL );
}

void RenderWindow::Display() {
    SDL_RenderPresent( renderer );

}



RenderWindow::~RenderWindow() {

    SDL_DestroyWindow( window );
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer= nullptr;
    SDL_DestroyTexture(WallPaper);
    WallPaper= nullptr;


}

void RenderWindow::Render(bird brd) {

    SDL_SetRenderDrawColor( renderer, 0, 0, 139, SDL_ALPHA_OPAQUE );
    SDL_Rect src={0,0,2236,2236};

    SDL_Rect dst={int(brd.postion.y),int(brd.postion.y),16,32};

    SDL_RenderCopy(renderer,brd.TEX,&src,&dst);

}

SDL_Texture * RenderWindow::Loadbrd(std::string path){

    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
    }
    newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    return newTexture;
}

