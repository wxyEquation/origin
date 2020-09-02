#ifndef ANIMATION_H
#define ANIMATION_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<queue>

class Animation
{
public:
    Animation();
    void setAnimation(int width, int height, int fps, int buff_size);
    virtual ~Animation();

    int get_width();
    int get_height();
    int get_buffsize();
    int fps();

    void play(int frame_num=0, int frame_buffer=5);
    void play();
    void buff_clear();

    virtual void loadFrame()=0;

private:
    int width, height;
    int frame_rate;
    int buff_size;

    std::queue<std::string> buffer;

};

#endif
