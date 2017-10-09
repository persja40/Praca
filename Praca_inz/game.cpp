#include "game.h"
#include <stdlib.h>
#include <time.h>

#include<iostream>

Game::Game()
{
    current= 0;
    srand(time(NULL));
    history.push_back( tuple<double,double,double>((double) rand() / (RAND_MAX),(double) rand() / (RAND_MAX),(double) rand() / (RAND_MAX)) );
//    cout<<std::get<0>(history[0])<<std::endl;
//    cout<<std::get<1>(history[0])<<std::endl;
//    cout<<std::get<2>(history[0])<<std::endl;
//    cout<<"ALALALALLALALALALLALALALLALA";
}

void Game::next(){
//Change mind

//Draw

}
