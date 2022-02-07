#pragma once
#include <math_helpers.h>

enum SHAPE_TYPE {
    CIRCLE = 0,
};

struct Circle {
    int radius;
    Coord centre;

    Circle(int x, int y, int r) : radius(r), centre(Coord(x,y)) {};
};

union shape_struct
{
    Circle circle;
    shape_struct(Circle circle): circle(circle) {};
};

struct Shape
{
    SHAPE_TYPE type;
    shape_struct shape_obj;

    Shape(SHAPE_TYPE type, Circle circle): type(type), shape_obj(shape_struct(circle)) {};
};