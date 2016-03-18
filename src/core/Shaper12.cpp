#include "Shaper12.h"
#include "catalogue/Catalogue.h"

Shaper12::Shaper12(ShapesList in)
{
    this->in = in;
}


ShapesList Shaper12::run() {
    generateOut(catalogue);
    return out;
}

ShapesList Shaper12::generateOut(Catalogue shapesAllowed) {
    for (std::vector<EntreeCatalogue>::const_iterator iter = shapesAllowed.getCatalogue().cbegin(); iter != shapesAllowed.getCatalogue().end(); iter++) {
        out.add(*in.search(*iter));
    }
    return out;
}
