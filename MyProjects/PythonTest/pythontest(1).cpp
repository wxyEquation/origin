#include "pythontest.h"

int factor(int x){
    int factorNum=1;
    for(int i=1;i<=x/2;i++){
        if(x%i==0){
            factorNum++;
        }
    }
    return factorNum;
}

