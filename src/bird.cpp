
#include "vector"
#include "bird.hpp"
#include "Renderer.hpp"
#include "iostream"

v2f::v2f(float X, float Y)
:x(X),y(Y)
{
}

v2f v2f::operator+(v2f sec) {

    return v2f(x+sec.x, y+sec.y);
};

v2f v2f::operator-(v2f sec) {

    return v2f(x-sec.x, y-sec.y);
};
v2f v2f::operator*(float sec) {

    return v2f(x*sec, y*sec);
};

void v2f::SetMag(float newV) {
    float norm=GETnorm();
    if(norm!=0){
    x=x/norm;y=y/norm;
    /*std::cout<<x<<" "<<y<<" "<<norm<<std::endl;*/
    x*=newV;y*=newV;}
}

float v2f::GETnorm() {
    return sqrt(pow((x),2)+pow((y),2));
}


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

void bird::Setspeed(v2f NewV) {
    if(NewV.x<-MAXSPEED){
        Velocity.x=-MAXSPEED;
    }else if(NewV.x>MAXSPEED){
        Velocity.x=MAXSPEED;

    }
    else{
    Velocity.x=NewV.x;}
    if(NewV.y<-MAXSPEED){
        Velocity.y=-MAXSPEED;
    }else if(NewV.y>MAXSPEED){
        Velocity.y=MAXSPEED;
    }
    else{
    Velocity.y=NewV.y;}

}

