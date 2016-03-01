#ifndef SHAPE_H
#define SHAPE_H

enum natureShape{
    CARRE;
    TRIANGLE;
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
