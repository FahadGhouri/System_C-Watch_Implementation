#ifndef _MULT_H_
#define _MULT_H_

#include "systemc.h"
SC_MODULE(Mult)
{
  sc_fifo_in<int> x;
  sc_fifo_out<int> s;

  int p;

  void multiply();
  SC_CTOR(Mult)
  {
    SC_THREAD(multiply);
  }
};
#endif
