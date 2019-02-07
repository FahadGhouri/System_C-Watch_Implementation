#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{
 for( int i = 0; i < 50; i++ )
 {
 ch_x.write(i);
 cout<<"stim x = "<<i<<endl;
 } 
}
void Testbench::check() // SC_METHOD
{
 for(;;)
 {
    cout<<" check: x[10]= "<<ch_s.read()<<endl;
    wait(10, SC_NS);
 } 
}
