#include "src/apis/MyScriptTOShapeList.h"
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

    Point l40(0,1);
    Point l41(0.5,2);
    Shape l4(LINE, l40, l41, 4);

    Point l50(1,1);
    Point l51(0.5,2);
    Shape l5(LINE, l50, l51, 5);

    in.addShape(l0);
    in.addShape(l1);
    in.addShape(l2);
    in.addShape(l3);
    in.addShape(l4);
    in.addShape(l5);

    //Les contraintes
    std::vector<Contrainte> contraintes;
    contraintes.push_back(*new Contrainte(JOINTURE, l0, l1) );
    contraintes.push_back(*new Contrainte(ANGLE, l0, l1) );
    contraintes.push_back(*new Contrainte(ANGLEDROIT, l0, l1) );

    contraintes.push_back(*new Contrainte(JOINTURE, l1, l2) );
    contraintes.push_back(*new Contrainte(ANGLE, l1, l2) );
    contraintes.push_back(*new Contrainte(ANGLEDROIT, l1, l2) );

    contraintes.push_back(*new Contrainte(JOINTURE, l2, l3) );
    contraintes.push_back(*new Contrainte(ANGLE, l2, l3) );
    contraintes.push_back(*new Contrainte(ANGLEDROIT, l2, l3) );

    contraintes.push_back(*new Contrainte(JOINTURE, l0, l3) );
    contraintes.push_back(*new Contrainte(ANGLE, l0, l3) );
    contraintes.push_back(*new Contrainte(ANGLEDROIT, l0, l3) );

    //1-4
    contraintes.push_back(*new Contrainte(JOINTURE, l1, l4) );
    contraintes.push_back(*new Contrainte(ANGLE, l1, l4) );

    //2-4
    contraintes.push_back(*new Contrainte(JOINTURE, l2, l4) );
    contraintes.push_back(*new Contrainte(ANGLE, l2, l4) );

    //4-5
    contraintes.push_back(*new Contrainte(JOINTURE, l5, l4) );
    contraintes.push_back(*new Contrainte(ANGLE, l5, l4) );

    //5-2
    contraintes.push_back(*new Contrainte(JOINTURE, l5, l2) );
    contraintes.push_back(*new Contrainte(ANGLE, l5, l2) );

    //5-3
    contraintes.push_back(*new Contrainte(JOINTURE, l5, l3) );
    contraintes.push_back(*new Contrainte(ANGLE, l5, l3) );

    in.setContraintes(contraintes);

    std::cout << "L'encre en entrée : " << std::endl << in;

    Shaper shaper(in);
    ShapesList out = shaper.run();

    std::cout << "L'encre en sortie : " << std::endl << out;


    // ICI on enverra out à l'application
    return 0;
}