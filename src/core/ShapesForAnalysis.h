//
// Created by seti on 07/03/16.
//

#ifndef PGROU_SHAPESFORANALYSIS_H
#define PGROU_SHAPESFORANALYSIS_H


#include <bits/stl_bvector.h>
#include "../shared/Shape.h"
#include "../shared/Contrainte.h"

class ShapesForAnalysis {
public:
    std::vector<Shape> shapes;
    std::vector<Contrainte> contraintes;
};


#endif //PGROU_SHAPESFORANALYSIS_H
