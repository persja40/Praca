#ifndef GAME_H
#define GAME_H

#include<array>

using namespace std;

class Game
{
public:
    Game();
    void next();
private:
    array<double,3> p;
    void decision();
    int current;
    array<int,3> nr;
    double checker(double r);
};

#endif // GAME_H
