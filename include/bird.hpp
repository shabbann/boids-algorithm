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
    v2f Getpostion();
    SDL_Rect Getdim();
    SDL_Texture *Gettex();

    void Setpostion(float x,float y);
    v2f postion;
    SDL_Rect dim;
    v2f Velocity;
    void Setxdir(float x);
    void Setydir(float y);
    void move(float dt);
private:
    SDL_Texture * TEX;





};