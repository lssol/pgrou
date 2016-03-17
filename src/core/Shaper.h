#ifndef SHAPER_H
#define SHAPER_H

#include "../shared/ShapesList.h"
#include "../shared/Shape.h"

class Shaper
{
protected:
    ShapesList in;
    ShapesList out;
    ShapesList generateOut(std::vector<Shape> shapesAllowed);
    ShapesList funciton(ShapesList k);
public:
    Shaper() { }
    Shaper(ShapesList in);
    ~Shaper();
    ShapesList run();
};

#endif // SHAPER_H
