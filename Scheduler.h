#ifndef SCHEDULER
#define SCHEDULER

#include <vector>
#include <string>
#include "Messenger.h"

struct Scheduled
{
    string name;
    int timeLeft;
    Scheduled(string _name, int _timeLeft);
};

class Scheduler
{
    private:
        Messenger* messenger;
        vector <Scheduled> scheduled;
    public:
        Scheduler(Messenger* _messenger);
        void schedule(Scheduled scheduled);
        void update(int dt);
};

#endif
