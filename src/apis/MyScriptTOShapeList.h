#ifndef MYSCRIPTTOSHAPELIST_H
#define MYSCRIPTTOSHAPELIST_H

#include "../shared/ShapesList.h"
#include "ObjetMyScript.h"

class MyScriptTOShapeList
{
public:
    MyScriptTOShapeList(ObjetMyScript toTransform);
    ~MyScriptTOShapeList();
    
    ShapesList toShapesList();
};


#endif // MYSCRIPTTOSHAPELIST_H
