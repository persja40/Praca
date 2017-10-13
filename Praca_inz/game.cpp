#include "game.h"
#include <stdlib.h>
#include <time.h>

#include<iostream>

using tuple3 = tuple<double,double,double>;

Game::Game()
{
    srand(time(NULL));
    p= {0.5,0.5,0.5};
    current=0;
    nr={0,0,0};
}

void Game::next(){
//Change mind
    current++;
    array<double,3> choices= {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
    for(int i=0; i<3; i++){
        if(choices[i]<p[i])
            nr[i]++;
    }
    decision();
//Draw
    cout<<p[0]<<"\t\t"<<p[1]<<"\t\t"<<p[2]<<"\t\t"<<endl;
}

void Game::decision(){
    array<double,3> result= { 0.1*( 1 - static_cast<double>(nr[1])/current + 1 - static_cast<double>(nr[2])/current - 1.0),
        0.1*( 1 - static_cast<double>(nr[2])/current + 1 - static_cast<double>(nr[0])/current - 1.0),
        0.1*( 1 - static_cast<double>(nr[0])/current + 1 - static_cast<double>(nr[1])/current - 1.0)
    };
    for(int i=0; i<3; i++)
        p[i]= checker(p[i]+result[i]);
}

double Game::checker(double r){
    if(r<0.0)
        return 0.0;
    else if(r>1.0)
        return 1.0;
    else return r;
}
