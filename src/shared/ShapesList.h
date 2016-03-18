#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <vector>
#include <string>
#include "Shape.h"
#include "Contrainte.h"
#include "../core/catalogue/EntreeCatalogue.h"
#include <string>

class ShapesList {
protected:
    std::vector<Shape> shapes;
    std::vector<Contrainte> contraintes;

    std::vector<ShapesList> buildGroups();

    std::vector<Contrainte> getTypeContrainte(TypeContrainte nomContraintes)const;
    std::vector<Contrainte> getContraintesConcerningShapes(const std::vector<Shape> &shapesConcerned);
    int getNumberTypeContrainte(TypeContrainte nomContraintes)const;

public:
    ShapesList();

    ~ShapesList();

    ShapesList* search(const EntreeCatalogue &entreeCatalogue);

    /*
     * Concatener deux ShapesList
     */
    void add( ShapesList &list);
    void addShape(const Shape &shape);
    std::vector<Shape> & getShapes();

    std::vector<Contrainte> & getContraintes();

    void setShapes(const std::vector<Shape> &shapes);

    void setContraintes(const std::vector<Contrainte> &contraintes);

    Shape* getShapeByID(int id);


    bool isContain(const std::vector<Shape> &shapes, const std::vector<Shape> &shapesConcerned);
};



#endif // SHAPELIST_H
