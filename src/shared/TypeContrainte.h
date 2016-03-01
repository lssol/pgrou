#ifndef TYPECONTRAINTE_H
#define TYPECONTRAINTE_H

enum Types{
    ANGLEDROIT;
    JOINTURE;
};

class TypeContrainte
{
private:
    Types type;
    float value;
public:
    TypeContrainte();
    ~TypeContrainte();

};

#endif // TYPECONTRAINTE_H
