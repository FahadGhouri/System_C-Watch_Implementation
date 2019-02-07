#include "adder.h"
void Adder::add()
{
		
    for(;;)
    {  
				int dataX = x.read();
				int dataY = y.read();
			 for(int nout= 0; nout<s.size(); nout++)
			 {
					//cout << " # Adder: " << nout << endl;
					s[nout]->write(dataX + dataY);
			 }		        
    }
}
