#ifndef HELPERS
#define HELPERS

#include <vector>
#include "Camera.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <cmath>
#include <iostream>
class Camera;

using namespace std;
struct Polygon {
    vector <float> p_x;
    vector <float> p_y;
    vector <int> colour;
    bool filled;
    Polygon(vector <float> _p_x, vector <float> _p_y, vector<int> _colour, bool _filled);
    Polygon(vector <float> _p_x, vector<float> _p_y, vector<int> _colour);
    Polygon(vector <float> _p_x, vector<float> _p_y); 
    void render(Camera *camera, float c_x,float c_y,float c_r,float c_s);
    void setColour(vector<int> _colour){colour=_colour;};
    vector <int> getColour(){return colour;};
};

float rotateScaleX(float x,float y, float r, float s);
float rotateScaleY(float x, float y, float r, float s);


#endif
