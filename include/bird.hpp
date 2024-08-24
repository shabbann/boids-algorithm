#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct v2f{
    float y=0;
    float x = 0;

     v2f(float x,float y);

};
class bird{
public:
    bird(float p_x, float p_y, SDL_Texture * tex);
    v2f postion;
    SDL_Texture * TEX;
    SDL_Rect dim;

private:
    /*v2f postion;
    SDL_Texture * TEX;
    SDL_Rect dim;*/
};