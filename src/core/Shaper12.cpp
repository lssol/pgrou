#include "Shaper12.h"
#include "data/shapes.h"

Shaper12::Shaper12(ShapesList in)
{
    this->in = in;
}

Shaper12::~Shaper12()
{
}

ShapesList Shaper12::run() {
    generateOut(simpleShapes);
    return out;
}