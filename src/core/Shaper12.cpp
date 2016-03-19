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
    ShapesList* result;
    for (std::vector<EntreeCatalogue>::const_iterator iter = shapesAllowed.getCatalogue().begin(); iter != shapesAllowed.getCatalogue().end(); iter++) {
        result = in.search(*iter);
        if(result != NULL)
            out.add(*result);
    }
    return out;
}
