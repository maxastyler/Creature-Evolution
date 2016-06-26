#include "Clock.h"

Clock::Clock(){
    startTime=SDL_GetTicks();
    frameTime=startTime;
    newTime=startTime;
    lastTime=startTime;
};

void Clock::update(){
    newTime=SDL_GetTicks();
    frameTime=newTime-lastTime;
    lastTime=newTime;
}

