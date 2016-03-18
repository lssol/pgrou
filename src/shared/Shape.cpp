#include "Shape.h"

Shape::Shape(NatureShape nature, Coordinates c, int p_id) {
    this->nature = nature;
    this->coordinates = c;
    this->id = p_id;
}

Shape::Shape(NatureShape nature, Point a, Point b, int p_id) {
    this->nature = nature;
    Coordinates c(a,b);
    this->id = p_id;
    this->coordinates = c;
}

const NatureShape &Shape::getNature() const {
    return nature;
}


