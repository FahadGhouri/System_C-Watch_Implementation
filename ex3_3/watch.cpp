#include "watch.h"
#include "systemc.h"

void Watch :: clock(){
        if(clk.posedge())
        {
            update_second.notify();
        }
        else if(clk.negedge())
        {
            post.notify();   
        }
}

void Watch :: seconds_count(){
    for(;;){    
        wait(update_second);
        Seconds.count();
        if(Seconds.overflow())        
        update_minute.notify();
    }
}

void Watch :: minutes_count(){
    for(;;){    
        wait(update_minute);
        Minutes.count();
        if(Minutes.overflow())
        update_hour.notify();
    }
}

void Watch :: hours_count(){
    for(;;){    
        wait(update_hour);
        Hours.count();
    }
}

void Watch :: display(){
    for(;;){
        wait(post); 
        cout<<Hours.read()<<":"<<Minutes.read()<<":"<<Seconds.read()<<endl;
    }
}
