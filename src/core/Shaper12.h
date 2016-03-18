#ifndef SHAPER12_H
#define SHAPER12_H

#include "../shared/ShapesList.h"
#include "Shaper.h"
#include "catalogue/Catalogue.h"

class Shaper12 : public Shaper
{
private:
    Catalogue catalogue;
public:
    Shaper12(ShapesList list);
    ShapesList generateOut(Catalogue shapesAllowed);
    ShapesList run();
};

#endif // SHAPER12_H
