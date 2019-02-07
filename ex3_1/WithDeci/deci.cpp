#include "deci.h"
void Deci::decimator()
{
    int out;    
    for(;;)
    {  
        for(int i=1;i<=10;i++){
            if(i==10)
            s.write(x.read());
            else
            out=x.read();
        }
    }
}
