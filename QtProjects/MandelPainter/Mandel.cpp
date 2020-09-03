#include "Mandel.h"
#include <cmath>

Mandel::Mandel(double offsetX, double offsetY, double width, double height):
    offsetX(offsetX),
    offsetY(offsetY),
    resolution(256),
    upperBound(256),
    width(width),
    height(height),
    colorpolicy(ColorCustomize::blackstamp),
    colored(false)
{
    window.resize(height*resolution);
    for(int i=0; i<height*resolution; i++){
        window[i].resize(width*resolution);
    for(int j=0; j<width*resolution; j++){
        window[i][j].iterationTimes = 0;
    }}
}

void Mandel::redraw(bool colored)
{
    this->colored = colored;
    if(colorpolicy==NULL){this->colored=false;}
    double coordtemp[2]={0,0};

    window.resize(height*resolution);
    if(colored){
        for(int i=0; i<height*resolution; i++){
            window[i].resize(width*resolution);
        for(int j=0; j<width*resolution; j++){
            getCoord(i, j, coordtemp);
            window[i][j].color = (*colorpolicy)(iteration(coordtemp[0], coordtemp[1]), upperBound);
        }}
    }else{
        for(int i=0; i<height*resolution; i++){
            window[i].resize(width*resolution);
        for(int j=0; j<width*resolution; j++){
            getCoord(i, j, coordtemp);
            window[i][j].iterationTimes = iteration(coordtemp[0], coordtemp[1]);
        }}
    }
}

int Mandel::iteration(double cx, double cy) const
{
    if(std::hypot(cx,cy)<0.5){
        return upperBound;
    }

    int iterTimes = 0;
    double x = cx;
    double y = cy;

    while(iterTimes<upperBound&&std::hypot(x,y)<2){
        x = x*x-y*y+cx;
        y = 2*x*y+cy;
        iterTimes++;
    }

    return iterTimes;
}

double Mandel::getCoord(int index, char coord) const
{

    switch (coord) {
        case 'x':
        case 'X': return  -width/2.0+(0.5+index)/resolution+offsetX; break;

        case 'y':
        case 'Y': return  height/2.0-(0.5+index)/resolution+offsetY; break;

        default:  return 0;
    }
}

Color Mandel::getColor(int row, int col) const
{
    if(colored){return window[row][col].color;}
    else{return {0,0,0,0};}
}

int Mandel::getIterTimes(int row, int col) const
{
    if(!colored){return window[row][col].iterationTimes;}
    else{return 0;}
}

bool Mandel::isColored() const {return colored;}

void Mandel::getCoord(int row, int col, double coordbuff[2]) const
{
    coordbuff[0] = -width/2.0+(0.5+col)/resolution+offsetX;
    coordbuff[1] = height/2.0-(0.5+row)/resolution+offsetY;
}
