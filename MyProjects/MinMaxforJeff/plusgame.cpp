#include "plusgame.h"

GameManager::GameManager(int f1, int f2, int s1, int s2)
{
    game[0][0]=f1%10;
    game[0][1]=f2%10;
    game[1][0]=s1%10;
    game[1][1]=s2%10;

    rounds=0;
    drwrounds=0;
    checkStatus();
}

const int* GameManager::operator [](const int playerIndex) const
{
    return game[playerIndex];
}

int GameManager::getNum(int player, int number) const {return game[player-1][number-1];}

int GameManager::getRounds() const {return rounds;}

int GameManager::getPlayer() const {return rounds%2+1;}

int GameManager::getStatus() const {return status;}

int GameManager::checkStatus()
{
    bool player1 = (game[0][0]+game[0][1])==0;
    bool player2 = (game[1][0]+game[1][1])==0;

    if(drwrounds>50||(player1&&player2)){
        status=drw;
    }else if(player1){
        status=w1n;
    }else if(player2){
        status=w2n;
    }else{
        status=con;
    }

    return status;
}

int GameManager::playMove(int fromNum, int toNum)
{
    int plyindex=rounds%2;
    int waitindex=(rounds+1)%2;

    if(status==con&&game[plyindex][fromNum-1]!=0&&game[waitindex][toNum-1]){

        game[plyindex][fromNum-1]+=game[waitindex][toNum-1];
        game[plyindex][fromNum-1]%=10;

        rounds++;

        if(game[plyindex][fromNum-1]==0){
            drwrounds=0;
        }else{
            drwrounds++;
        }
        checkStatus();
    }

    return status;
}

int GameManager::playMove(int moveIndex)
{
    int to=moveIndex%2;
    int from=(moveIndex-to)/2;
    playMove(from+1, to+1);
    return status;
}



int GameManager::restart(int f1, int f2, int s1, int s2)
{
    int ret=status;

    game[0][0]=f1%10;
    game[0][1]=f2%10;
    game[1][0]=s1%10;
    game[1][1]=s2%10;

    rounds=0;
    checkStatus();
    drwrounds=0;

    return ret;
}
