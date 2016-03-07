#ifndef SHAPE_H
#define SHAPE_H

#include "Coordinates.h"

enum natureShape{
    LIGNE,
    ARC
};

class Shape
{
protected:
    natureShape nature;
    Coordinates coordinates;


public:
    Shape();
    Shape(natureShape nature, Coordinates c);
    Shape(natureShape nature, Point a, Point b);
    ~Shape();

    int id;
};

#endif // SHAPE_H
