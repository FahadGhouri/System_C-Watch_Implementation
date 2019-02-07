#include "adder.h"
void Adder::add()
{
    for(;;)
    {  
        s = x + y;
        wait();
    }
}
