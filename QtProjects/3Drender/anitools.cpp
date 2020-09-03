#include "anitools.h"

Frame_writer::Frame_writer(int width, int height):
    width(width),
    height(height),
    trimflag(false)
{
    //here goes nothing
}

int Frame_writer::get_width() {return width;}

int Frame_writer::get_height(){return height;}

std::string Frame_writer::get_frame() {return frame;}

bool Frame_writer::isTrimed() {return trimflag;}

int Frame_writer::get(int x, int y)
{
    int count=y*width+x;

    //ascii 9 : tab
    //ascii 10 : linefeed
    if(trimflag){
        int pos=0;
        for(int i=0;i<(int)frame.length();i++){
            switch (frame[i]) {
                case 9:  pos+=4; break;
                case 10: pos+=((pos+1)%width!=0||pos==0)?(width-(pos%width)):0; break;
                defalt: pos++;
            }

        }
    }

    return count;
}

