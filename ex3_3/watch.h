#ifndef _WATCH_H_
#define _WATCH_H_
#include "systemc.h"
#include "counter.h"
#include "register.h"

SC_MODULE(Watch)
{
    Counter Seconds;
    Counter Minutes;
    Counter Hours;
    
    void clock();
    void seconds_count();
    void minutes_count();
    void hours_count();
    void display(); 

    sc_event update_second,update_minute,update_hour,post;
    
    sc_in<bool> clk;

SC_CTOR(Watch):Seconds(60),Minutes(60),Hours(24){
    SC_METHOD(clock);
    sensitive<<clk;
    SC_THREAD(seconds_count);
    SC_THREAD(minutes_count);
    SC_THREAD(hours_count);
    SC_THREAD(display);
}

};
#endif
