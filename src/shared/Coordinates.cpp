#include "Coordinates.h"
#include "ShapesList.h"


Coordinates::Coordinates()
{

}

Coordinates::~Coordinates()
{
}

Coordinates::Coordinates(Point a, Point b) {
    this->sommets.push_back(a);
    this->sommets.push_back(b);
}
