#include <stdio.h>

#include "src/apis/ObjetMyScript.h"
#include "src/apis/MyScriptTOShapeList.h"
#include "src/shared/ShapesList.h"
#include "src/core/Shaper.h"
/*
int main(ObjetMyScript donnees)
{
    MyScriptTOShapeList api(donnees);
    ShapesList in = api.toShapesList();
    
    Shaper shaper(in);
    ShapesList out = shaper.run();
    
    // ICI on enverra out à l'application
    return 0;
}
*/

// Without the ObjectMyScript
int main()
{
    // On va creer un rectangle en in
    ShapesList in;

    ///Les lignes
    Point l00(0,0);
    Point l01(1,0);
    Shape l0(LINE, l00, l01, 0);

    Point l10(0,0);
    Point l11(0,1);
    Shape l1(LINE, l10, l11, 1);

    Point l20(0,1);
    Point l21(1,1);
    Shape l2(LINE, l20, l21, 2);

    Point l30(1,1);
    Point l31(0,1);
    Shape l3(LINE, l30, l31, 3);

    in.addShape(l0);
    in.addShape(l1);
    in.addShape(l2);
    in.addShape(l3);


    Shaper shaper(in);
    ShapesList out = shaper.run();


    // ICI on enverra out à l'application
    return 0;
}