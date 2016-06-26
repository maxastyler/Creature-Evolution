#include "Helpers.h"

float rotateScaleX(float x,float y, float r, float s){
    return s*x*cos(r)-s*y*sin(r);  
};

float rotateScaleY(float x, float y, float r, float s){
    return s*x*sin(r)+s*y*cos(r);
};

using namespace std;
Polygon::Polygon(vector <float> _p_x, vector <float> _p_y, vector<int> _colour, bool _filled)
{
    p_x=_p_x;
    p_y=_p_y;
    colour = _colour;
    filled = _filled;
};

Polygon::Polygon(vector <float> _p_x, vector <float> _p_y, vector<int> _colour)
{
    p_x=_p_x;
    p_y=_p_y;
    colour = _colour;
    filled = true;
};

Polygon::Polygon(vector <float> _p_x, vector <float> _p_y)
{
    p_x=_p_x;
    p_y=_p_y;
    colour={0, 0, 0, 255};
    filled=true;
};

void Polygon::render(Camera* camera, float c_x, float c_y, float c_r, float c_s){
    vector <short> transformX;
    vector <short> transformY;
    for (unsigned i=0; i<p_x.size();i++){
        transformX.push_back(camera->getS()*(rotateScaleX(p_x[i], p_y[i],c_r, c_s )+c_x-camera->getX())+camera->getW()/2.-camera->getX()); 
        transformY.push_back(camera->getS()*(rotateScaleY(p_x[i], p_y[i], c_r, c_s)+c_y-camera->getY())+camera->getH()/2.-camera->getY());
    };
    short* arrX=&transformX[0];
    short* arrY=&transformY[0];
    if (filled) filledPolygonRGBA(camera->getRenderer(), arrX, arrY, transformX.size(), colour[0], colour[1], colour[2], colour[3]);
};
