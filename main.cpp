#include <stdio.h>

#include "src/apis/ObjetMyScript.h"
#include "src/apis/MyScriptTOShapeList.h"
#include "src/shared/ShapesList.h"
#include "src/core/Shaper.h"

int main(ObjetMyScript donnees)
{
    MyScriptTOShapeList api(donnees);
    ShapesList in = api.toShapesList();
    
    Shaper shaper(in);
    ShapesList out = shaper.run();
    
    // ICI on enverra out à l'application
    return 0;
}
