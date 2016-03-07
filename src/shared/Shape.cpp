#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

Shape::Shape(natureShape nature, Coordinates c) {
    this->nature = nature;
    this->coordinates = c;
}

Shape::Shape(natureShape nature, Point a, Point b) {
    this->nature = nature;
    Coordinates c(a,b);

    this->coordinates = c;
}
