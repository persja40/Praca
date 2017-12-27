#include "game.h"
#include <stdlib.h>
#include <time.h>

Game::Game(int f)
{
    srand(time(NULL));
    p= {0.5,0.5,0.5};
    current=0;
    nr={0,0,0};
    decision = decision_funs[f];
}

tup3<double> Game::next(){
//Change mind
    pre= make_tuple(p[0],p[1],p[2]);
    current++;
    array<double,3> choices= {static_cast<double>(rand())/RAND_MAX, static_cast<double>(rand())/RAND_MAX, static_cast<double>(rand())/RAND_MAX};
    for(int i=0; i<3; i++)
        if(choices[i]<p[i])
            nr[i]++;
    decision();
    //cout<<p[0]<<"\t\t"<<p[1]<<"\t\t"<<p[2]<<"\t\t"<<endl;
    return make_tuple(p[0],p[1],p[2]);
}

int Game::getCurrent(){
    return current;
}

tup3<double> Game::prelast(){
    return pre;
}

double Game::checker(double r){
    if(r<0.0)
        return 0.0;
    else if(r>1.0)
        return 1.0;
    else return r;
}
