#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>

class Contrainte
{
private:
    TypeContrainte typeContrainte;
    std::vector<Shape> shapes;
public:
    Contrainte();
    ~Contrainte();

};

#endif // CONTRAINTE_H
