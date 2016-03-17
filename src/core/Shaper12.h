#ifndef SHAPER12_H
#define SHAPER12_H

#include "../shared/ShapesList.h"
#include "Shaper.h"

class Shaper12 : public Shaper
{
public:
    Shaper12(ShapesList list);
    ~Shaper12();

    ShapesList run();
};

#endif // SHAPER12_H
