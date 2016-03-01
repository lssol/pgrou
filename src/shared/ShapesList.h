#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <vector>

class ShapesList
{
private:
    std::vector<Shape> shapes;
    std::vector<Contrainte> contraintes;
public:
    ShapesList();
    ~ShapesList();

};

#endif // SHAPELIST_H
