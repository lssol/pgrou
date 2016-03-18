#include "Contrainte.h"
#include <iostream>

Contrainte::~Contrainte()
{
}

void Contrainte::setTypeContrainte(const TypeContrainte &typeContrainte) {
    Contrainte::typeContrainte = typeContrainte;
}

void Contrainte::setShapes(const std::vector<Shape> &shapes) {
    Contrainte::shapes = shapes;
}

std::vector<Shape> Contrainte::getShapes() const{
    return shapes;
}

const TypeContrainte & Contrainte::getTypeContrainte()const {
    return typeContrainte;
}

std::ostream& operator<<(std::ostream&, const Contrainte& c){
    std::cout << "-- Nom contrainte : " << contraintesNames[c.getTypeContrainte()] << std::endl;
    std::cout << "-- ID des shapes concernées" << std::endl;
    for(const auto & shape : c.getShapes()) {
        std::cout << "-- --> ";
        std::cout << shape << std::endl;
    }
}

Contrainte::Contrainte(TypeContrainte type, Shape s1, Shape s2) {
    this->typeContrainte = type;
    this->shapes.push_back(s1);
    this->shapes.push_back(s2);
}
