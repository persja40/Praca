#include "game.h"
#include <stdlib.h>
#include <time.h>

#include<iostream>

using tuple3 = tuple<double,double,double>;

Game::Game()
{
    current= 0;
    srand(time(NULL));
    history.push_back( tuple3((double) rand() / (RAND_MAX),(double) rand() / (RAND_MAX),(double) rand() / (RAND_MAX)) );
}

void Game::next(){
//Change mind
    double dWier= 1.0 - std::get<1>(history[current]) - std::get<2>(history[current]);
    double dKol= 1.0 - std::get<0>(history[current]) - std::get<2>(history[current]);
    double dWar= 1.0 - std::get<0>(history[current]) - std::get<1>(history[current]);
    cout<<dWier<<"\t\t"<<dKol<<"\t\t"<<dWar<<endl;
    history.push_back( tuple3(std::get<0>(history[current])+dWier, std::get<1>(history[current])+dKol,std::get<2>(history[current])+dWar));
    current++;
//Draw
}

void Game::print(){
    for(tuple3 a:history)
        std::cout<<std::get<0>(a)<<"\t\t"<<std::get<1>(a)<<"\t\t"<<std::get<2>(a)<<"\t"<<std::endl;
}
