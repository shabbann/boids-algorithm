
#include "vector"
#include "bird.hpp"
#include "Renderer.hpp"

v2f::v2f(float X, float Y)
:x(X),y(Y)
{
};


bird::bird( float p_x, float p_y,SDL_Texture * tex)
: postion(p_x,p_y),TEX(tex)
{
    dim={0,0,2236,2236};



}
