#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "adder.h"
#include "mult.h"
#include "deci.h"
#include "src.h"
#include "dst.h"
SC_MODULE(Testbench)
{ 									
  sc_fifo<int> src1,src2,src3,add1,add2,add3,add4_1,add4_2,add4_3,mult1,mult2,dec1;          // channels
  
  src Src1;
  dst Dst1;
  Mult Mult1,Mult2;
  Adder adder1,adder2,adder3,adder4;
  Deci deci;						    
  
    void go();
  SC_CTOR(Testbench)
  :Src1("Src1"),Dst1("Dst1"),Mult1("Mult1"),Mult2("Mult2"),adder1("adder1"),adder2("adder2"),adder3("adder3"),adder4("adder4"),deci("deci")
  {   
        Src1.output(src1);
        Src1.output(src2);
        Src1.output(src3);
        adder1.x(src1);
        adder1.y(src2);
        adder1.s(add1);
        adder2.x(add1);
        adder2.y(src3);
        adder2.s(add2);
        adder3.x(add2);
        adder3.y(mult2);
        adder3.s(add3);
        adder4.x(add3);
        adder4.y(mult1);
        adder4.s(add4_1);
        adder4.s(add4_2);
        adder4.s(add4_3);
        Mult1.p=-2;
        Mult2.p=-3;
        Mult1.x(add4_2);
        Mult1.s(mult1);
        Mult2.x(add4_3);
        Mult2.s(mult2);
        deci.x(add4_1);
        deci.s(dec1);
        Dst1.input(dec1);

        SC_THREAD(go);

  }
};

#endif

