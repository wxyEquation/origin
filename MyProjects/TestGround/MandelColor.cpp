#include "Mandel.h"

int ColorCustomize::rainbowWidth = 100;
std::vector<Color> ColorCustomize::points;

Color ColorCustomize::blackstamp(int iterTimes, int upperBound)
{
    unsigned char isBlack = iterTimes==upperBound?0:255;
    return {isBlack, isBlack, isBlack, 255};
}

void ColorCustomize::whiteglow()
{
    points.clear();
    points.push_back(BLACK);
    points.push_back(WHITE);
}

void ColorCustomize::fireball()
{
    points.clear();
    points.push_back(BLACK);
    points.push_back(RED);
    points.push_back(YELLOW);
    points.push_back(WHITE);

}

void ColorCustomize::supernova()
{
    points.clear();
    points.push_back(BLACK);
    points.push_back(BLUE);
    points.push_back(MAGENTA);
    points.push_back(RED);
    points.push_back(YELLOW);
    points.push_back(WHITE);
}

Color ColorCustomize::getGradient(int iterTimes, int upperBound)
{
    if(points.size()<=1){
        return {0,0,0,0};
    }
    int pieceNum = points.size()-1;
    double pieceLen = upperBound/(double)pieceNum;
    int pieceInd = (int)(iterTimes/pieceLen);
    if(pieceInd>=pieceNum){
        return points[pieceNum];
    }

    const Color& from = points[pieceInd];
    const Color& to   = points[pieceInd+1];
    double ratio = iterTimes/pieceLen-pieceInd;
    unsigned char r = from.red+ratio*(to.red-from.red);
    unsigned char g = from.green+ratio*(to.green-from.green);
    unsigned char b = from.blue+ratio*(to.blue-from.blue);
    unsigned char a = from.alpha+ratio*(to.alpha-from.alpha);

    return {r,g,b,a};
}

void ColorCustomize::rosepeddal()
{
    points.clear();
    points.push_back({180,25,25,255});
    points.push_back({60,20,20,255});
}

void ColorCustomize::oceanblue()
{
    points.clear();
    points.push_back({230,230,200,255});
    points.push_back({100,200,200,255});
    points.push_back({50 ,150,200,255});
    points.push_back({40 ,60 ,100,255});
    points.push_back({25 ,50 ,75 ,255});

}

Color ColorCustomize::getRainbow(int iterTimes, int upperBound)
{
    if(points.size()<=1){
        return {0,0,0,0};
    }

    if(iterTimes==upperBound){
        return BLACK;
    }

    int modTimes=iterTimes%rainbowWidth;
    int pieceNum = points.size()-1;
    double pieceLen = rainbowWidth/(double)pieceNum;
    int pieceInd = (int)(modTimes/pieceLen);
    if(pieceInd>=pieceNum){
        return points[pieceNum];
    }

    const Color& from = points[pieceInd];
    const Color& to   = points[pieceInd+1];
    double ratio = modTimes/pieceLen-pieceInd;
    unsigned char r = from.red+ratio*(to.red-from.red);
    unsigned char g = from.green+ratio*(to.green-from.green);
    unsigned char b = from.blue+ratio*(to.blue-from.blue);
    unsigned char a = from.alpha+ratio*(to.alpha-from.alpha);

    return {r,g,b,a};
}
