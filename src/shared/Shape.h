#ifndef SHAPE_H
#define SHAPE_H

#include "Coordinates.h"
#include <iostream>

enum NatureShape{
    LINE = 0,
    ARC,
    RECTANGLE,
    TRIANGLE
};
static const char* shapesNames[] = {"LINE", "ARC", "RECTANGLE", "TRIANGLE"};

class Shape
{
protected:
    NatureShape nature;
    Coordinates coordinates;


public:
    Shape(NatureShape nature, Coordinates c, int p_id);
    Shape(NatureShape nature, Point a, Point b, int p_id);
    friend std::ostream& operator<<(std::ostream&, const Shape& shape);
    const NatureShape & getNature() const;

    int id;
};

#endif // SHAPE_H
