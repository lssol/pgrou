#ifndef SHAPER_H
#define SHAPER_H

#include "../shared/ShapesList.h"

class Shaper
{
protected:
    ShapesList in;
    ShapesList out;
public:
    Shaper() { }

    Shaper(ShapesList in);
    ~Shaper();
    
    ShapesList run();
};

#endif // SHAPER_H
