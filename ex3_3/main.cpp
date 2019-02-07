#include "systemc.h"
#include "counter.h"
#include "register.h"
#include "watch.h"

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
    
    Watch Watch1("Watch1");

    sc_clock clock("clock",100,SC_SEC,0.5);

    Watch1.clk(clock);    

	sc_start();

	cout << endl <<"simulation finished" << endl;
	return 0;
}



