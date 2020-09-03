#include "gamebots.h"

void GameBot1::setValueMap(){
    for(int i=0; i<10*10*10*10; i++){
        *(&bot1Brain.valueMap[0][0][0][0]+i)=404;
    }

    for(int i=0; i<10; i++){
    for(int j=0; j>10; j++){
        bot1Brain.valueMap[0][0][i][j]=250; //player 1 : Max
        bot1Brain.valueMap[i][j][0][0]=-250;//player 2 : Min
    }}

    bot1Brain.valueMap[0][0][0][0]=404;
}

void GameBot1::setFile(const char *brain){
    using namespace std;

    brainBuff.open(brain, ios::in|ios::out|ios::binary);
    if(!brainBuff){

        bot1Brain.type[0]='B';
        bot1Brain.type[1]='R';
        bot1Brain.botype=1;
        bot1Brain.size=sizeof(bot1Brain);
        bot1Brain.mapsize=sizeof(bot1Brain.valueMap);

        setValueMap();
        bot1Brain.offset=bot1Brain.size-bot1Brain.mapsize;

        if(!readOnly){
            brainBuff.close();
            brainBuff.open(brain, ios::in|ios::out|ios::trunc|ios::binary);

            brainBuff.seekp(0, ios::beg);
            brainBuff.write((char*)&bot1Brain, bot1Brain.size);
        }

    }else{

        brainBuff.seekg(0, ios::beg);
        brainBuff.read((char*)&bot1Brain, sizeof(bot1Brain));

        if(readOnly){
            brainBuff.close();
            brainBuff.open(brain, ios::in|ios::binary);
        }

    }


}

GameBot1::GameBot1(const GameManager *game, int searchDepth, const char *buff, bool readOnly):
    searchDepth(searchDepth),
    game(game),
    readOnly(buff==NULL||readOnly)
{
    rounds=game->getRounds();
    myMove=-1;
    setFile(buff);
}

GameBot1::~GameBot1()
{
    if(!readOnly){
        brainBuff.seekp(bot1Brain.offset, std::ios::beg);
        brainBuff.write((char*)bot1Brain.valueMap, bot1Brain.mapsize);
    }
    brainBuff.close();
}

int GameBot1::getMove()
{
    //TO DO:
    return 0;
}
