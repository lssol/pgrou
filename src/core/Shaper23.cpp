//
// Created by Killian on 03/03/2016.
//

#include "Shaper23.h"
#include "Contrainte.h"
#include "Coordonnees.h"
#include "Point.h"
#include "Shape.h"
#include "ShapesList.h"
#include "TypeContrainte"
#include "GeometryModel.h"

class Shaper23::Shaper{

private:
    Shaper23();
    ~shaper23();
    Shape



    bool forme (ShapeList Liste_Shapes){
        bool a := FALSE;
        bool b := FALSE;
        for (int i=0;Liste_Shapes.shapes.length();i++){
            if (Liste_Shapes.shapes.get(i).nature='CARRE'){
                a = TRUE;
            }
            if (Liste_Shapes.shapes.get(i).nature='TRIANGLE'){
                b = TRUE;
            }
        }
        return(a&&b);
    }

    bool jointure (ShapeList Liste_Shapes, ShapeList &Maison){
        bool a := FALSE;
        bool b := FALSE;

        ShapeList Carre := new ShapeList();
        ShapeList Triangle := new ShapeList();
        for (int i=0;Liste_Shapes.shapes.size();i++){
            if (Liste_Shapes.shapes[i].nature=='CARRE'){
                Carre.shapes.push_back(Liste_Shapes.shapes.get(i));
                a = TRUE;
            }
            if (Liste_Shapes.shapes.get(i).nature=='TRIANGLE'){
                Triangle.shapes.push_back(Liste_Shapes.shapes.get(i));
                b = TRUE;
            }
        }
        ShapeList Maison;
        for (int i=0;Carre.shapes.size();i++){
            for (int j=0;Triangle.shapes.size();j++){
                for (int k=0;Carre.shapes[i].;k++){
                    for (int l=0;Traingle.shapes[j];l++){
                        if (Carre.shapes[i].==Traingle.shapes[j].){
                            Maison.shapes.push_back(Carre.shapes[i]);
                            Maison.shapes.push_back(Triangle.shapes[i]);
                        }
                    }
                }
            }
        }
        return(a&&b);
    }

    bool orientation(ShapeL){


    }

public:
    void run(ShapeList Liste_Shapes) {
        if (forme(Liste_Shapes)) {
            int a: = FALSE;
            int b: = FALSE;
            ShapeList Maison : = new Shapelist();
            if (jointure(Liste_Shapes, Maison)) {
                if (orientation(Maison)) {

                }

            }
        }
    }
};


