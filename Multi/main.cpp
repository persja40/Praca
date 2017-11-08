#include <iostream>
#include <fstream>

using namespace std;

#include "multigame.h"

int main(int argc, char *argv[]) {
    int games_nr = atoi(argv[1]);
    int players_nr = atoi(argv[2]);
    Multigame gra(players_nr, games_nr);
    gra.play();
}

