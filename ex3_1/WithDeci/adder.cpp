#include "adder.h"
void Adder::add()
{
    for(;;)
    {  
        s.write((x.read())+(y.read()));
    }
}
