#include "vector"
#include "bird.hpp"
#include "BoidsAlgorithm.hpp"
#include "math.h"

float Getdis(const bird& b1,const bird&  b2){
    return (float)sqrt(pow((b1.postion.x-b2.postion.x),2)+pow((b1.postion.y-b2.postion.y),2));
};
void simulate(const float& dt,std::vector<bird>& birds,std::vector<bird>& predators){
    for (int i = 0; i < BIRDSCOUNT; ++i) {
        v2f accelration(0,0);
        accelration=(Separation(birds,birds[i])
                +Alignment(birds,birds[i])
                +Cohesion(birds,birds[i])
                +Avoid(predators,birds[i]));
        accelration.SetMag(MAXACC);
        birds[i].Velocity = birds[i].Velocity+accelration;
        birds[i].Velocity.SetMag(MAXSPEED);
        birds[i].move(dt);
    }

    for (int i = 0; i < PREDCOUNT; ++i) {
        v2f accelration(0,0);
        accelration = Hunt(birds,predators[i]);
        predators[i].Velocity=predators[i].Velocity+accelration;
        predators[i].Velocity.SetMag(MAXSPEED-20);
        predators[i].move(dt);
    }

}

//TODO Quadtrees
v2f Separation(const std::vector<bird>& birds ,const bird& curr){

        v2f REQDIR(0,0);
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(&curr !=&birds[j] and Getdis(curr,birds[j])<=100){
                if((birds[j].postion.x-curr.postion.x)!=0){
                    REQDIR.x-= 1.f/(birds[j].postion.x-curr.postion.x);}
                if((birds[j].postion.y-curr.postion.y)!=0){
                    REQDIR.y-= 1.f/(birds[j].postion.y-curr.postion.y);}
            }
        }
        REQDIR.SetMag(MAXSPEED*3);

        return REQDIR;


}
v2f Alignment(const std::vector<bird>& birds,const bird& curr){

        v2f Alivec(0,0);
        int bcount=0;
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if( &curr !=&birds[j] and Getdis(curr,birds[j])<=100){
                Alivec =Alivec + birds[j].Velocity;
                bcount++;
            }
        }
        if(bcount>0){
        Alivec.x/=float(bcount);Alivec.y/=float(bcount);}
        v2f REQDIR=Alivec-curr.Velocity;
        REQDIR.SetMag(MAXSPEED*3);
        return REQDIR;

}
v2f  Cohesion(const std::vector<bird>& birds,const bird& curr){
        v2f CenterOfMass(0,0);
        int bcount=0;
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(&curr !=&birds[j] and Getdis(curr,birds[j])<=100){
                CenterOfMass.x+=birds[j].postion.x;CenterOfMass.y+=birds[j].postion.y;
                bcount++;
            }
        }
        if(bcount>0){
        CenterOfMass.x/=(float)bcount;CenterOfMass.y/=(float)bcount;}
        v2f REQDIR(CenterOfMass.x-curr.postion.x,CenterOfMass.y-curr.postion.y);
        REQDIR=REQDIR-curr.Velocity;
        REQDIR.SetMag(MAXSPEED*3);

        return REQDIR;

}
v2f Avoid( const std::vector<bird>& predators ,const bird& currbird){
    v2f REQDIR(0,0);
        for (int j = 0; j < PREDCOUNT; ++j) {
            if( Getdis(currbird,predators[j])<=100){
                if((predators[j].postion.x-currbird.postion.x)!=0){
                    REQDIR.x-= 1.f/(predators[j].postion.x-currbird.postion.x);}
                if((predators[j].postion.y-currbird.postion.y)!=0){
                    REQDIR.y-= 1.f/(predators[j].postion.y-currbird.postion.y);}
            }
    }
    REQDIR.SetMag(MAXSPEED*7);
    return REQDIR;

}
v2f Hunt(const std::vector<bird>& birds , const bird& currPRED){
    v2f REQDIR(0,0);
    for (int i = 0; i < BIRDSCOUNT; ++i) {
        if( Getdis(currPRED,birds[i])<=100){
            REQDIR=v2f(birds[i].postion.x-currPRED.postion.x,birds[i].postion.y-currPRED.postion.y);
            break;
        }
    }
    REQDIR.SetMag(MAXSPEED/100);
    return REQDIR;
}