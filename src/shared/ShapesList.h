#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <vector>
#include <bits/basic_string.h>
#include "Shape.h"
#include "Contrainte.h"
#include "../core/ShapesForAnalysis.h"
#include <string>

class ShapesList {
protected:
    std::vector<Shape> shapes;
    std::vector<Contrainte> contraintes;

    std::vector<ShapesForAnalysis> buildGroups();

    std::vector<Contrainte> getTypeContrainte(TypesContrainte nomContraintes);
    std::vector<Contrainte> getContraintesConcerningShapes(std::vector<Shape> shapesConcerned);

public:
    ShapesList();

    ~ShapesList();

    ShapesList search(const Shape &shape);

    /*
 * Concatener deux ShapesList
 */
    void add(ShapesList list);

    std::vector<Shape> &getShapes();

    std::vector<Contrainte> &getContraintes();

    void setShapes(const std::vector<Shape> &shapes);

    void setContraintes(const std::vector<Contrainte> &contraintes);

    Shape getShapeByID(int id);

    std::vector<Contrainte> getContraintesConcerningShapes(const std::vector<Shape> &shapesConcerned);
};



#endif // SHAPELIST_H
