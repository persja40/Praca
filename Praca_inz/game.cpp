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

void Game::next(){
//Change mind
    current++;
    array<double,3> choices= {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
    for(int i=0; i<3; i++)
        if(choices[i]<p[i])
            nr[i]++;
    decision();
//Draw
    cout<<p[0]<<"\t\t"<<p[1]<<"\t\t"<<p[2]<<"\t\t"<<endl;
}

double Game::checker(double r){
    if(r<0.0)
        return 0.0;
    else if(r>1.0)
        return 1.0;
    else return r;
}
