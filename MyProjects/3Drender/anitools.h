#ifndef ANITOOLS_H
#define ANITOOLS_H

#include "animation.h"

class Frame_writer
{
public:
    Frame_writer(int width, int height);

    int get_width();
    int get_height();
    std::string get_frame();
    bool isTrimed();

    int get(int x, int y);
    void stamp(char c, int x, int y);
    void write(std::string str, int x, int y);
    void trim();
    void detrim();
    void clear();

    void instr(std::string frame);
    std::string outstr();

private:
    int width, height;
    bool trimflag;

    std::string frame;

};

#endif // ANITOOLS_H
