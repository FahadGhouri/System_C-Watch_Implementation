#ifndef _DECI_H_
#define _DECI_H_

#include "systemc.h"
SC_MODULE(Deci)
{
  sc_fifo_in<int> x;
  sc_fifo_out<int> s;

  void decimator();
  SC_CTOR(Deci)
  {
    SC_THREAD(decimator);
  }
};
#endif
