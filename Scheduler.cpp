#include "Scheduler.h"
#include <iostream>

Scheduled::Scheduled(string _name, int _timeLeft){
    name=_name;
    timeLeft=_timeLeft;
};

Scheduler::Scheduler(Messenger* _messenger){
    messenger=_messenger;
};

void Scheduler::schedule(Scheduled _scheduled){
    scheduled.push_back(_scheduled);    
};

void Scheduler::update(int dt){
    for (unsigned i=scheduled.size();i-->0;){
        scheduled[i].timeLeft-=dt;
        if (scheduled[i].timeLeft<=0) 
        {
            messenger->addMessage(scheduled[i].name);
            scheduled.erase(scheduled.begin()+i);
        };    
    };
};
