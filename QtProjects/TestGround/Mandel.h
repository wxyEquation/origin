#ifndef MANDEL_H
#define MANDEL_H

#include <vector>

typedef struct _color{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} Color;


#define RED Color{255,0,0,255}
#define GREEN Color{0,255,0,255}
#define BLUE Color{0,0,255,255}
#define YELLOW Color{255,255,0,255}
#define CYAN Color{0,255,255,255}
#define MAGENTA Color{255,0,255,255}
#define BLACK Color{0,0,0,255}
#define WHITE Color{255,255,255,255}


class ColorCustomize
{
public:
    static Color blackstamp(int iterTimes, int upperBound);

    static void whiteglow();
    static void fireball();
    static void supernova();
    static Color getGradient(int iterTimes, int upperBound);

    static int rainbowWidth;
    static void rosepeddal();
    static void oceanblue();
    static Color getRainbow(int iterTimes, int upperBound);

    static std::vector<Color> points;

private:

    ColorCustomize();

};


class Mandel
{
public:

    Mandel(double offsetX=0, double offsetY=0, double width=4, double height=4);

    void redraw(bool colored=true); //.............get you the iteration times instead of color if false
    int iteration(double x, double y) const;//......return iteration times to get (x, y) out the circle

    void getCoord(int row, int col, double coordbuff[2]) const;
    double getCoord(int index, char coord) const;//.....coord can be 'x', 'y' or 'X', 'Y'
    Color getColor(int row, int col)       const;//.....if not colored, return 0
    int getIterTimes(int row, int col)     const;//.....if colored, return 0
    bool isColored()                       const;

    double offsetX;    //- The coordinate of
    double offsetY;    //centre of the window

    double resolution; //- Pixel per unit length
    int upperBound;    //- Max iteration times

    double width;      //- Size of the window
    double height;

    Color (*colorpolicy) (int iterTimes, int upperBound);

private:

    bool colored;

    typedef union _mandelData{
        Color color;
        int iterationTimes;
    } MandelData;

    std::vector< std::vector<MandelData> > window;

};

#endif // MANDEL_H
