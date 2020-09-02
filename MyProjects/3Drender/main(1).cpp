#include <iostream>
#include "animation.h"

using namespace std;

class Test: public Animation
{
public:
    void loadFrame() override;
    string cycle[8];
};

int main(int argc, char *argv[])
{
    system("mode con cols=20 lines=20");
    char c=10;
    cout<<c;
    cout<<"09876543210987654321";
    cout<<c<<c;
    cout<<"end";

    return 0;
}
