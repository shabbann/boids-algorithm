#pragma once
#include <SDL2/SDL.h>
#include "string"
class RenderWindow{
public:
    RenderWindow();
    ~RenderWindow();
    void RenderWallpaper();
    void Display();
private:
    std::string title = "BOIDS";
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* WallPaper;
    SDL_Texture *LoadTexture(std::string path);
};