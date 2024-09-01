
#include "bird.hpp"
#include "iostream"
#include "const.hpp"
v2f::v2f(float X, float Y)
:x(X),y(Y)
{
}

v2f v2f::operator+(v2f sec) {

    return v2f(x+sec.x, y+sec.y);
}

v2f v2f::operator-(v2f sec) {

    return v2f(x-sec.x, y-sec.y);
}
v2f v2f::operator*(float sec) {

    return v2f(x*sec, y*sec);
}

void v2f::SetMag(float newV) {
    float norm=sqrt(pow((x),2)+pow((y),2));
    if(norm!=0){
    x=x/norm;y=y/norm;
    x*=newV;y*=newV;}
}

bird::bird( float p_x, float p_y,SDL_Texture * tex)
: postion(p_x,p_y),TEX(tex), Velocity(-rand(),-rand())
{
    dim={0,0,2236,2236};
}

v2f bird::Getpostion() {
    return postion;
}


SDL_Texture *bird::Gettex() {
    return TEX;
}



void bird::move(float dt) {
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



