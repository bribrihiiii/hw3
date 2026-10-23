#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(const Event* e1, const Event* e2) const {
            // smaller time goes first (min heap)
            //return e1.time < e2.time;   <- doesnt compile, theyre pointers
            uint64_t t1 = e1->time;
            uint64_t t2 = e2->time;
            if(t1 < t2){
                return true;
            }
            
            else {
                return false;
            }
        }
} EventLess;
	
#endif
