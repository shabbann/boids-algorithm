#pragma once
#include <SDL2/SDL.h>
#include "string"
#include "bird.hpp"
class RenderWindow{
public:
    RenderWindow();
    ~RenderWindow();
    void RenderWallpaper();
    void Display();
    void Render(bird brd);
    SDL_Texture * Loadbrd(std::string path);
    void clear();
    SDL_Renderer* renderer;
private:
    std::string title = "BOIDS";
    SDL_Window* window;

    SDL_Texture* WallPaper;
    SDL_Texture *LoadTexture(std::string path);

};
