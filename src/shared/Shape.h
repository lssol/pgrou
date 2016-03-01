#ifndef SHAPE_H
#define SHAPE_H

#include "Coordonnees.h"

enum natureShape{
    LIGNE,
    ARC
};

class Shape
{
private:
    natureShape nature;
    Coordonnees coordonnees;
public:
    Shape();
    ~Shape();
};

#endif // SHAPE_H
