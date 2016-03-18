#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>
#include "Shape.h"


enum TypeContrainte{
    ANGLE,
    ANGLEDROIT,
    JOINTURE
};

class Contrainte
{
private:
    TypeContrainte typeContrainte;
    float value;
    std::vector<Shape> shapes;
public:

    const TypeContrainte & getTypeContrainte()const;

    void setTypeContrainte(const TypeContrainte &typeContrainte);

    std::vector<Shape> getShapes()const;

    void setShapes(const std::vector<Shape> &shapes);

    Contrainte();
    ~Contrainte();

};


#endif // CONTRAINTE_H
