#include "vector"
#include "iostream"
#include "Renderer.hpp"
#include "bird.hpp"
#include "BoidsAlgorithm.hpp"
#include "math.h"
#include "algorithm"
#include <queue>


float Getdis(bird b1,bird b2){
    return sqrt(pow((b1.postion.x-b2.postion.x),2)+pow((b1.postion.y-b2.postion.y),2));
};
void UpdateRespectToSeparation(std::vector<bird>& birds ,float dt){
    for (int i = 0; i <BIRDSCOUNT; ++i) {

        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(Getdis(birds[i],birds[j])<=200){
                if((birds[j].postion.x-birds[i].postion.x)!=0)
                {birds[i].Setxdir(birds[i].Velocity.x - 1.f/(birds[j].postion.x-birds[i].postion.x));}
                if((birds[j].postion.y-birds[i].postion.y)!=0)
                {birds[i].Setydir(birds[i].Velocity.y - 1.f/(birds[j].postion.y-birds[i].postion.y));
                    }
            }

        }
    }


}
void UpdateRespectToAlignment(std::vector<bird>& birds,float dt){
    for (int i = 0; i <BIRDSCOUNT; ++i) {
        float Aliangle=0;
        int bcount=0;
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(Getdis(birds[i],birds[j])<=300){
                Aliangle+= fmod((atan2(birds[j].Velocity.y,birds[j].Velocity.x)*180/M_PI ),360);
                bcount++;
            }
        }
        Aliangle/=float(bcount);
        birds[i].Setxdir(birds[i].Velocity.x+ (birds[i].Velocity.y/tan(Aliangle*M_PI/180))/1000.f);
        birds[i].Setydir(birds[i].Velocity.y+ (birds[i].Velocity.x*tan(Aliangle*M_PI/180))/1000.f);

    }

}



void UpdateRespectToCohesion(std::vector<bird>& birds,float dt){
    for (int i = 0; i <BIRDSCOUNT; ++i) {
        v2f CenterOfMass(0,0);
        int bcount=0;
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(Getdis(birds[i],birds[j])<=200){
                CenterOfMass.x+=birds[j].postion.x+6;CenterOfMass.y+=birds[j].postion.y+32/2;
                bcount++;
            }
        }
        CenterOfMass.x/=(float)bcount;CenterOfMass.y/=(float)bcount;
        std::cout<<CenterOfMass.x<<" \t\t "<<CenterOfMass.y<<std::endl;
        v2f REQDIR(CenterOfMass.x-birds[i].postion.x,CenterOfMass.y-birds[i].postion.y);

        birds[i].Setxdir(birds[i].Velocity.x+(REQDIR.x-birds[i].Velocity.x)/500.f);
        birds[i].Setydir(birds[i].Velocity.y+(REQDIR.y-birds[i].Velocity.y)/500.f);


    }


}