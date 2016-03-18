//
// Created by seti on 16/03/16.
//

#ifndef PGROU_CATALOGUE_H
#define PGROU_CATALOGUE_H


#include "EntreeCatalogue.h"

class Catalogue {
protected:
    std::vector<EntreeCatalogue> catalogue;
public:

    Catalogue();

    const std::vector<EntreeCatalogue> & getCatalogue() const;
};


#endif //PGROU_CATALOGUE_H
