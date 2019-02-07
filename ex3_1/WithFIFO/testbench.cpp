#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{
 for( int i = 0; i < 10; i++ )
 {
 ch_x.write(i); ch_y.write(30-2*i);
 cout<<"stim x = "<<i<<", y = "<<30-2*i<<endl;
 } 
}
void Testbench::check() // SC_METHOD
{
 for(;;)
 {
    cout<<" check: x + y = "<<ch_s.read()<<endl;
    wait(10, SC_NS);
 } 
}
