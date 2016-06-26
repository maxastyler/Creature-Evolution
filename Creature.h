#ifndef CREATURE
#define CREATURE

#include "Helpers.h" 
#include <vector>
#include "Camera.h"

class Creature
{
    private:
        float x;
        float y;
        float r;
        float s;
        Camera *camera;
        vector <Polygon> shapes; 

    public:
        Creature(float _x, float _y, float _r, float _s, Camera *_camera); 

        float getX(){return x;};
        void setX(float _x){x=_x;};
        float getY(){return y;};
        void setY(float _y){y=_y;};
        float getR(){return r;};
        void setR(float _r){r=_r;};
        float getS(){return s;};
        void setS(float _s){s=_s;};

        void render();
};

#endif
