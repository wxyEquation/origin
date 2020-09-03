#ifndef GAMEBOTS_H
#define GAMEBOTS_H

#include "plusgame.h"

typedef struct brainfile{
    unsigned char type[2];
    unsigned int botype;
    unsigned int size;
    unsigned int mapsize;
    unsigned int offset;

    int valueMap[10][10][10][10];
} BrainFile;

class GameBot1
{
public:

    GameBot1(const GameManager* game, int searchDepth=100, const char* buff="bots1buff.br", bool readOnly=false);
    ~GameBot1();

    int getMove();
    int getMoveFrom();
    int getMoveTo();

private:

    int rounds;
    int myMove;
    int searchDepth;

    const GameManager* game;
    std::fstream brainBuff;
    bool readOnly;

    BrainFile bot1Brain;
    void setValueMap();
    void setFile(const char* brain);
};


#endif // GAMEBOTS_H
