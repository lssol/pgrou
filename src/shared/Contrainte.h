#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>
#include <iostream>
#include "Shape.h"


enum TypeContrainte{
    ANGLE = 0,
    ANGLEDROIT,
    JOINTURE
};
static const char* contraintesNames[] = {"Angle", "Angle Droit", "Jointure"};

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
    friend std::ostream& operator<<(std::ostream&, const Contrainte& c);
    void setShapes(const std::vector<Shape> &shapes);

    Contrainte(TypeContrainte type, Shape s1, Shape s2);
    ~Contrainte();

};


#endif // CONTRAINTE_H
