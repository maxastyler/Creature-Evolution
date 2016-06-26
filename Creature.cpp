#include "Creature.h"
Creature::Creature(float _x, float _y, float _r, float _s, Camera *_camera){
    x=_x;
    y=_y;
    r=_r;
    s=_s;
    camera=_camera;
    shapes.push_back(Polygon({0, -0.5, -0.25, 0.25, 0.5},{1, -0.5, -1, -1, -0.5}, {100, 0, 255, 255}));
    shapes.push_back(Polygon({-0.25, -0.45, -1.25}, {-0.5, -1, -1.5}));
    shapes.push_back(Polygon({0.25, 0.45, 1.25}, {-0.5, -1, -1.5}));
};

void Creature::render(){
    for (unsigned i=0; i<shapes.size(); i++){
        shapes[i].render(camera, x, y, r, s);
    };
};
