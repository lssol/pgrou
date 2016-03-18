//
// Created by seti on 15/03/16.
//

#ifndef PGROU_ENTREECATALOGUE_H
#define PGROU_ENTREECATALOGUE_H


#include <map>
#include "../../shared/Shape.h"
#include "../../shared/Contrainte.h"

class EntreeCatalogue {
public:
    NatureShape nature;
    std::map<TypeContrainte, int> contraintes;
    int nbAngles;

    EntreeCatalogue(const NatureShape &nature, int nbAngles) : nature(nature), nbAngles(nbAngles){ }

    void addContrainte(TypeContrainte type, int nb);
};


#endif //PGROU_ENTREECATALOGUE_H
