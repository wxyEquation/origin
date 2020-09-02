#include <iostream>
#include "Mandel.h"

using namespace std;

int main()
{
    Mandel* test = new Mandel;

    cout<<test->iteration(-2,2)<<endl;

    test->redraw(false);

    ColorCustomize::whiteglow();
    test->colorpolicy=ColorCustomize::getGradient;

    test->redraw();
    Color get = test->getColor(0,0);
    double buff[2];
    test->getCoord(512,512,buff);
    cout<<buff[0]<<endl;
    cout<<buff[1]<<endl;
    cout<<test->iteration(buff[0],buff[1])<<endl;
    cout<<(int)get.green<<endl;


    delete test;

    return 0;
}
