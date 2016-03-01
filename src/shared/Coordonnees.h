#ifndef COORDONNEES_H
#define COORDONNEES_H

#include <vector>
#include "Point.h"

class Coordonnees
{
private:
    std::vector<Point> sommets;
public:
    Coordonnees();
    ~Coordonnees();

};

#endif // COORDONNEES_H
