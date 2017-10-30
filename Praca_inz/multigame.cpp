#include "multigame.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <ctime>
#include <iostream>

using namespace std;

Multigame::Multigame(int players, int nr_games)
{
  srand(time(NULL));
  current = 0;
  this->players = players;
  this->nr_games = nr_games;
  for(int i=0; i<players;++i){
    p.push_back(0.5);
    nr_r.push_back(0);
  }
  time_t _tm =time(NULL);
  struct tm * curtime = localtime ( &_tm );
  string tt(asctime(curtime));
  file.open(tt+".dat");
}

Multigame::~Multigame(){
  file.close();
}

void Multigame::play(const std::chrono::duration<double, std::milli> delay){
  for(int i=0;i<nr_games;i++){
    next();
    this_thread::sleep_for(delay);
  }
}

void Multigame::next(){
  current++;
//save
  for(int i=0;i<players;i++)
    file<<p[i]<<"\t";
  file<<current<<endl;
//random choice
  for(int i=0; i<players;i++)
      if(((double) rand()/RAND_MAX) < p[i])
          nr_r[i]++;
//modify behaviour
  p[0]+= 0.1*(p[0]*(1-p[0])*(1-static_cast<double>(nr_r[1])/current-static_cast<double>(nr_r[players-1])/current));
  for(int i=1;i<players-1;i++)
    p[i]+= 0.1*(p[i]*(1-p[i])*(1-static_cast<double>(nr_r[i+1])/current-static_cast<double>(nr_r[i-1])/current));
  p[players-1]+= 0.1*(p[players-1]*(1-p[players-1])*(1-static_cast<double>(nr_r[0])/current-static_cast<double>(nr_r[players-2])/current));
}

double Multigame::checker(double r){
    if(r<0.0)
        return 0.0;
    else if(r>1.0)
        return 1.0;
    else return r;
}

