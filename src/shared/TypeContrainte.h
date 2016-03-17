#ifndef TYPECONTRAINTE_H
#define TYPECONTRAINTE_H

enum TypesContrainte{
    ANGLEDROIT,
    JOINTURE
};

class TypeContrainte
{
private:
    TypesContrainte type;
    float value;
public:
    TypeContrainte();
    ~TypeContrainte();

};

#endif // TYPECONTRAINTE_H
