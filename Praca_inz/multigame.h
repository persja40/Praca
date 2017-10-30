#ifndef MULTIGAME_H
#define MULTIGAME_H

#include<vector>
#include<chrono>
#include<string>
#include<fstream>

using namespace std;
using namespace std::chrono_literals;

class Multigame
{
public:
    Multigame(int players, int nr_games);
    ~Multigame();
    void next();
    void play(const std::chrono::duration<double, std::milli> delay = 0ms);
private:
    ofstream file;
    int current;
    int players;
    int nr_games;
    vector<double> p;
    vector<int> nr_r;
    double checker(double r);
};

#endif // MULTIGAME_H
