#ifndef GAME_H
#define GAME_H

#include<vector>
#include<tuple>

using namespace std;

class Game
{
public:
    Game();
    void next();
    void print();
private:
    vector<tuple<double,double,double>> history;
    int current;
};

#endif // GAME_H
