#include "Shaper.h"
#include "Shaper12.h"
#include "Shaper23.h"


Shaper::Shaper(ShapesList in)
{
    this->in = in;
}

Shaper::~Shaper()
{
}

ShapesList Shaper::run() {
    Shaper12 shaper12(in);
   /* Shaper23 shaper23(shaper12.run());
    out = shaper23.run();

    return out;*/

    //Test forme simple
    return shaper12.run();
}
