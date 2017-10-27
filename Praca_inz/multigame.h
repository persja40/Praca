#ifndef MULTIGAME_H
#define MULTIGAME_H

#include<vector>
#include<chrono>
#include<string>
using namespace std;
using namespace std::chrono_literals;

class Multigame
{
public:
    Multigame(int players, int nr_games, string filename);
    void next();
    void play(const std::chrono::duration<double, std::milli> delay = 0ms);
private:
    ofstream file;
    int current;
    int players;
    int nr_games;
    vector<double> p;
    vector<double> nr_r;
    double checker(double r);
};

#endif // MULTIGAME_H
