#include "vector"
#include "iostream"
#include "Renderer.hpp"
#include "bird.hpp"
#include "BoidsAlgorithm.hpp"
#include "math.h"
float Getdis(bird b1,bird b2){
    return sqrt(pow((b1.postion.x-b2.postion.x),2)+pow((b1.postion.y-b2.postion.y),2));
};
void update(float dt, std::vector<bird>& birds){

    for (int i = 0; i < BIRDSCOUNT; ++i) {
        v2f accelration(0,0);
        accelration=(Separation(birds,birds[i])+Alignment(birds,birds[i])+Cohesion(birds,birds[i]));
        /*std::cout<<i<<"\t"<<accelration.GETnorm()<<"\t";*/
        accelration.SetMag(MAXACC);
        birds[i].Velocity = birds[i].Velocity+accelration;
        birds[i].Velocity.SetMag(MAXSPEED);

    }

}




v2f Separation(std::vector<bird>& birds ,const bird& curr){

        v2f REQDIR(0,0);
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(&curr !=&birds[j] and Getdis(curr,birds[j])<=100){
                if((birds[j].postion.x-curr.postion.x)!=0)
                REQDIR.x-= 1.f/(birds[j].postion.x-curr.postion.x);
                if((birds[j].postion.y-curr.postion.y)!=0)
                REQDIR.y-= 1.f/(birds[j].postion.y-curr.postion.y);
            }
        }
        REQDIR.SetMag(1);

        return REQDIR;


}
v2f Alignment(std::vector<bird>& birds,const bird& curr){

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
        REQDIR.SetMag(1);
        return REQDIR;

}



v2f  Cohesion(std::vector<bird>& birds,const bird& curr){
        v2f CenterOfMass(0,0);
        int bcount=0;
        for (int j = 0; j < BIRDSCOUNT; ++j) {
            if(&curr !=&birds[j] and Getdis(curr,birds[j])<=100){
                CenterOfMass.x+=birds[j].postion.x+6;CenterOfMass.y+=birds[j].postion.y+32.f/2.f;
                bcount++;
            }
        }
        if(bcount>0){
        CenterOfMass.x/=(float)bcount;CenterOfMass.y/=(float)bcount;}
        v2f REQDIR(CenterOfMass.x-curr.postion.x,CenterOfMass.y-curr.postion.y);
        REQDIR=REQDIR-curr.Velocity;
        REQDIR.SetMag(1);

        return REQDIR;

}