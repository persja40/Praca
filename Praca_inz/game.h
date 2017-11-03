#ifndef GAME_H
#define GAME_H
#include <expressions.h>

class Game //3 players game
{
public:
    Game(int f);
    void next();
private:
    array<double,3> p;
    int current;
    array<int,3> nr;
    double checker(double r);
    function<void()> decision;
    array<function<void()>,2>decision_funs={
      [this](){//simple
        array<double,3> result= {
            0.1*( 1 - static_cast<double>(nr[1])/current - static_cast<double>(nr[2])/current),
            0.1*( 1 - static_cast<double>(nr[2])/current - static_cast<double>(nr[0])/current ),
            0.1*( 1 - static_cast<double>(nr[0])/current - static_cast<double>(nr[1])/current )
        };
        for(int i=0; i<3; i++)
            p[i]= checker(p[i]+result[i]);
      },
      [this](){//replicators
        array<double,3> result= {
            0.1*(p[0]*(1-p[0])*(1-static_cast<double>(nr[1])/current-static_cast<double>(nr[2])/current)),
            0.1*(p[1]*(1-p[1])*(1-static_cast<double>(nr[0])/current-static_cast<double>(nr[2])/current)),
            0.1*(p[2]*(1-p[2])*(1-static_cast<double>(nr[0])/current-static_cast<double>(nr[1])/current))
        };
        for(int i=0; i<3; i++)
            p[i]= checker(p[i]+result[i]);
      }
    };
};

#endif // GAME_H
