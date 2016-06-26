#ifndef CAMERA
#define CAMERA

#include "Helpers.h"
#include <SDL2/SDL.h>

class Camera{
    
    private:
        float x;
        float y;
        float w;
        float h;
        float s;
        SDL_Renderer* renderer;

    public:
        Camera(float _x, float _y, float _w, float _h, float _s, SDL_Renderer* _renderer);
        float getX(){return x;};
        void  setX(float _x){x=_x;};
        float getY(){return y;};
        void  setY(float _y){y=_y;};
        float getS(){return s;};
        void  setS(float _s){s=_s;};
        float getW(){return w;};
        float getH(){return h;};
        SDL_Renderer* getRenderer(){return renderer;};

};

#endif
