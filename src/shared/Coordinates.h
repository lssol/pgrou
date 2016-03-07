#ifndef COORDONNEES_H
#define COORDONNEES_H

#include <vector>
#include "Point.h"

class Coordinates
{
private:
    std::vector<Point> sommets;
public:
    Coordinates();
    Coordinates(Point a, Point b);
    ~Coordinates();

};

#endif // COORDONNEES_H
