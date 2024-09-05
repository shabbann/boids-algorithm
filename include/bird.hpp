#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct v2f{
    float y=0;
    float x = 0;
     v2f(float x,float y);
     v2f operator+(const v2f& sec) const;
     v2f operator-(const v2f& sec) const;
    v2f operator*(const float& sec) const;
     void SetMag(const float& newV);

};

class bird{
public:
    bird(float p_x, float p_y, SDL_Texture * tex);
    v2f Getpostion();

    SDL_Texture *Gettex();
    v2f postion;
    SDL_Rect dim;
    v2f Velocity;
    void move(const float& dt);
protected:
    SDL_Texture * TEX;






};