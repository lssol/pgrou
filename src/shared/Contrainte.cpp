#include "Contrainte.h"

Contrainte::Contrainte()
{
}

Contrainte::~Contrainte()
{
}

void Contrainte::setTypeContrainte(const TypeContrainte &typeContrainte) {
    Contrainte::typeContrainte = typeContrainte;
}

void Contrainte::setShapes(const std::vector<Shape> &shapes) {
    Contrainte::shapes = shapes;
}

std::vector<Shape> & Contrainte::getShapes()const {
    return shapes;
}

TypeContrainte &Contrainte::getTypeContrainte() {
    return typeContrainte;
}