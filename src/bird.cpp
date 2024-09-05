
#include "bird.hpp"
#include "iostream"
#include "const.hpp"
v2f::v2f(float X, float Y)
:x(X),y(Y)
{
}

v2f v2f::operator+(const v2f& sec) const {

    return v2f(x+sec.x, y+sec.y);
}

v2f v2f::operator-(const v2f& sec) const {

    return v2f(x-sec.x, y-sec.y);
}
v2f v2f::operator*(const float& sec) const {

    return v2f(x*sec, y*sec);
}

void v2f::SetMag(const float& newV) {
    float norm=sqrt(pow((x),2)+pow((y),2));
    if(norm!=0){
    x=x/norm;y=y/norm;
    x*=newV;y*=newV;}
}

bird::bird( float p_x, float p_y,SDL_Texture * tex)
: postion(p_x,p_y),TEX(tex), Velocity(rand()%5-2,rand()%5-2)
{
    Velocity.SetMag(MAXSPEED);
    SDL_Point size;
    SDL_QueryTexture(tex, NULL, NULL, &size.x, &size.y);
    dim={0,0,size.x,size.y};
}

v2f bird::Getpostion() {
    return postion;
}


SDL_Texture *bird::Gettex() {
    return TEX;
}



void bird::move(const float& dt) {
    postion=postion+Velocity*dt;
    if(postion.x>1280){
        postion.x=0;
    }
    else if(postion.x<0){
        postion.x=1280;
    }
    if(postion.y<0){
        postion.y=720;
    }
    else if(postion.y>720){
        postion.y=0;
    }
}

