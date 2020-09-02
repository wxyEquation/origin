#ifndef PLUSGAME_H
#define PLUSGAME_H

#include "MinMaxforJeff_global.h"
#include <iostream>
#include <fstream>

class MINMAXFORJEFF_EXPORT GameManager
{
public:

    const int con = 0;
    const int drw = 1;
    const int w1n = 2;
    const int w2n = 3;

    GameManager(int f1=1, int f2=1, int s1=1, int s2=1);

    const int* operator [] (int const playerIndex) const;
    int getNum(int player, int number) const;
    int getRounds() const;
    int getPlayer() const;
    int getStatus() const;
    int checkStatus();

    int playMove(int fromNum, int toNum);
    int playMove(int moveIndex);
    int restart(int f1=1, int f2=1, int s1=1, int s2=1);

private:

    int game[2][2];
    int rounds;
    int drwrounds;
    int status;

};

#endif // PLUSGAME_H
