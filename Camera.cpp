#include "Camera.h"

Camera::Camera(float _x, float _y, float _w, float _h, float _s, SDL_Renderer* _renderer){
    x=_x;
    y=_y;
    w=_w;
    h=_h;
    s=_s;
    renderer = _renderer;
};

