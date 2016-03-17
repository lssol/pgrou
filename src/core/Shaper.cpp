#include "Shaper.h"
#include "../shared/ShapesList.h"
#include "Shaper12.h"
#include "Shaper23.h"
#include <vector>

Shaper::Shaper(ShapesList in)
{
    this->in = in;
}

Shaper::~Shaper()
{
}

ShapesList Shaper::run() {
    Shaper12 shaper12(in);
    Shaper23 shaper23(shaper12.run());
    out = shaper23.run();

    return out;
}

ShapesList Shaper::generateOut(std::vector<Shape> shapesAllowed) {
    for (std::vector<Shape>::const_iterator iter = shapesAllowed.cbegin(); iter != shapesAllowed.end(); iter++) {
        out.add(in.search(*iter));
    }
    return out;
}

ShapesList Shaper::funciton(ShapesList k) {
    return ShapesList();
}
