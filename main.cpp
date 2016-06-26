#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <vector>
#include "Camera.h"
#include "Creature.h"
#include "Messenger.h"
#include "Scheduler.h"
#include "Clock.h"
#include <cstdlib>

SDL_Window* window;
SDL_Renderer* renderer;
const int WINDOW_WIDTH=640;
const int WINDOW_HEIGHT=480;

bool init();
void close();

int main(int argc, char* args[]){

    if (!init()){
        printf("Failed to initialise!\n");
    }
    else{
        SDL_Event e;
        Camera camera=Camera(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, renderer);
        vector <Creature> creatures;
        for (int i=0; i<100;i++){
            creatures.push_back(Creature(rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT, rand()%360, 100, &camera));
        };
        Messenger messenger = Messenger();
        Message message;
        Clock clock = Clock();
        Scheduler scheduler=Scheduler(&messenger);
        bool running=true;
        int mouse_x;
        int mouse_y;
        int mouse_mask=SDL_GetRelativeMouseState(&mouse_x, &mouse_y);
        while (running){
            clock.update();
            while (SDL_PollEvent(&e)!=0){
                if (e.type==SDL_QUIT){
                    running = false;
                }
            };
            while (messenger.pollMessage(&message)){
            };
            scheduler.update(clock.getFrameTime());
            const Uint8* currentKeyStates=SDL_GetKeyboardState(NULL);
            int mouse_mask=SDL_GetRelativeMouseState(&mouse_x, &mouse_y);
            if (mouse_mask==4){
                camera.setX(camera.getX()-mouse_x);
                camera.setY(camera.getY()-mouse_y);
            }
            if (currentKeyStates[SDL_SCANCODE_UP]) camera.setS(camera.getS()*1.01);
            if (currentKeyStates[SDL_SCANCODE_DOWN]) camera.setS(camera.getS()*0.99);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            for (unsigned i=0; i<creatures.size();i++){
                creatures[i].render();
                creatures[i].setR(creatures[i].getR()+clock.getFrameTime()*0.01);
            };
            SDL_RenderPresent(renderer);
        }
    }
    close();
    return 0;
}; 

bool init(){
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError() );
        success=false;
    }
    else 
    {
        window=SDL_CreateWindow("Evolution", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (window==NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success=false;
        }
        else
        {
            renderer=SDL_CreateRenderer(window, -1, 0);
        }
    }

    return success;
};

void close(){
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
};
