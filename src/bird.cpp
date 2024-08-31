
#include "vector"
#include "bird.hpp"
#include "Renderer.hpp"

v2f::v2f(float X, float Y)
:x(X),y(Y)
{
};


bird::bird( float p_x, float p_y,SDL_Texture * tex)
: postion(p_x,p_y),TEX(tex), Velocity(-rand(),-rand())
{
    dim={0,0,2236,2236};
}

v2f bird::Getpostion() {
    return postion;
}

SDL_Rect bird::Getdim() {
    return dim;
}

SDL_Texture *bird::Gettex() {
    return TEX;
}

void bird::Setpostion(float x, float y) {
    postion.x=x;
    postion.y=y;

}

void bird::move(float dt) {
    postion.x+=Velocity.x*dt;
    postion.y+=Velocity.y*dt;
    if(postion.x>1280){
        postion.x=0;
    }
    if(postion.y>720){
        postion.y=0;
    }
    if(postion.x<0){
        postion.x=1280;
    }
    if(postion.y<0){
        postion.y=720;
    }


}

void bird::Setxdir(float x) {
    if(x<-60){
        Velocity.x=-60;
        return;
    }
    if(x>60){
        Velocity.x=60;
        return;
    }
    Velocity.x=x;
    return;



}

void bird::Setydir(float y) {
    if(y<-60){
        Velocity.y=-60;
        return;
    }
    if(y>60){
        Velocity.y=60;
        return;
    }
    Velocity.y=y;
    return;


}

