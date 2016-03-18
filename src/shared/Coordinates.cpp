#include "Coordinates.h"
#include "ShapesList.h"


Coordinates::Coordinates()
{

}

Coordinates::~Coordinates()
{
}

Coordinates::Coordinates(Point a, Point b) {
    this->sommets[0] = a;
    this->sommets[1] = b;
}
