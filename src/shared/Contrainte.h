#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>
#include "TypeContrainte.h"
#include "Shape.h"

class Contrainte
{
private:
    TypeContrainte typeContrainte;
    std::vector<Shape> shapes;
public:

    TypeContrainte & getTypeContrainte();

    void setTypeContrainte(const TypeContrainte &typeContrainte);

    std::vector<Shape> & getShapes()const;

    void setShapes(const std::vector<Shape> &shapes);

    Contrainte();
    ~Contrainte();

};


#endif // CONTRAINTE_H
