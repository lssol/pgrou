//
// Created by seti on 15/03/16.
//

#include "EntreeCatalogue.h"

void EntreeCatalogue::addContrainte(TypeContrainte type, int nb) {
    this->contraintes[type] = nb;
}
