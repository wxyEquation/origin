#include "animation.h"

Animation::Animation():
    width(40),
    height(40),
    frame_rate(12),
    buff_size(5)
{
    //here goes nothing
}

void Animation::setAnimation(int width, int height, int fps, int buff_size)
{
    this->width=width;
    this->height=height;
    frame_rate=fps;
    this->buff_size=buff_size;
}

Animation::~Animation()
{
    buff_clear();
}

inline int Animation::get_width() {return width;}

inline int Animation::get_height() {return height;}

inline int Animation::get_buffsize() {return buff_size;}

inline int Animation::fps() {return frame_rate;}



void Animation::play(int frame_num, int frame_buffer)
{
    std::ostringstream ostr;
    ostr<<"mode con cols="<<width*2<<"lines="<<height;
    std::string init=ostr.str();

    long time;
    int loaded;
    system(init.c_str());
    if(frame_num==0){
        while(1){
            time=clock();
            std::cout<<buffer.front();
            buffer.pop();
            loaded=0;
            while(time>clock()-CLOCKS_PER_SEC/frame_rate||buffer.empty())
            {
                if(loaded<frame_buffer)
                {loadFrame();
                loaded++;}
            }
            system("cls");
        }
    }else{
        for(int i=0; i<frame_num; i++){
            time=clock();
            std::cout<<buffer.front();
            buffer.pop();
            loaded=0;
            while(time>clock()-CLOCKS_PER_SEC/frame_rate||buffer.empty())
            {
                if(loaded<frame_buffer)
                {loadFrame();
                loaded++;}
            }
            system("cls");
        }
    }
}

void Animation::play()
{
    std::ostringstream ostr;
    ostr<<"mode con cols="<<width*2<<"lines="<<height;
    std::string init=ostr.str();

    long time;
    system(init.c_str());

    while(!buffer.empty()){
        time=clock();
        std::cout<<buffer.front();
        buffer.pop();
        while(time>clock()-CLOCKS_PER_SEC/frame_rate){}
        system("cls");
    }
}

void Animation::buff_clear()
{
    while(!buffer.empty()){
        buffer.pop();
    }
}


