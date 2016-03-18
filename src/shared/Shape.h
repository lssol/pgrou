#ifndef SHAPE_H
#define SHAPE_H

#include "Coordinates.h"

enum NatureShape{
    LINE,
    ARC,
    RECTANGLE,
    TRIANGLE
};

class Shape
{
protected:
    NatureShape nature;
    Coordinates coordinates;


public:
    Shape(NatureShape nature, Coordinates c, int p_id);
    Shape(NatureShape nature, Point a, Point b, int p_id);

    const NatureShape & getNature() const;

    int id;
};

#endif // SHAPE_H
