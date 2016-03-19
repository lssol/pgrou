//
// Created by seti on 16/03/16.
//

#include "Catalogue.h"

const std::vector<EntreeCatalogue> &Catalogue::getCatalogue() const {
    return catalogue;
}

Catalogue::Catalogue() {
    EntreeCatalogue rectangle(RECTANGLE, 4);
    rectangle.addContrainte(ANGLEDROIT, 4);

    catalogue.push_back(rectangle);

    EntreeCatalogue triangle(TRIANGLE, 3);

    catalogue.push_back(triangle);
}
