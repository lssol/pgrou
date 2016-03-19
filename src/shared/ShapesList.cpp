#include <map>
#include "ShapesList.h"
#include "../core/graph/Graph.h"
#include <iostream>
using namespace std;
ShapesList::ShapesList()
{
}

ShapesList::~ShapesList()
{
}

/**
 * Prend un type de Forme shape et renvoit la liste des shape présents dans la liste des shapes (attribut) CONTRAINTES?????
 */
ShapesList* ShapesList::search(const EntreeCatalogue &entreeCatalogue) {
    ShapesList* result = new ShapesList();
    int n;
    int i = 0;
    bool somethingDone = false;

    Coordinates temp;

    // On construit le vector de formes fermées à analyser
    std::vector<ShapesList> toAnalyse = buildGroups();

    //Pour chaque forme fermée à analyser on veut verifier si elle correspond à l'entrée catalogue
    for(ShapesList const &currentClosedShape : toAnalyse){
        if(currentClosedShape.getNumberTypeContrainte(ANGLE) == entreeCatalogue.nbAngles){

            // Pour chaque contrainte à verifier de l'entrée du catalogue
            std::map<TypeContrainte, int>::const_iterator contrainteAVerifier;
            for (contrainteAVerifier = entreeCatalogue.contraintes.begin();
                 contrainteAVerifier != entreeCatalogue.contraintes.end(); ++contrainteAVerifier) {
                n = currentClosedShape.getNumberTypeContrainte(
                        contrainteAVerifier->first); // Nombre de contraintes de type contrainte à verifier
                if (n < contrainteAVerifier->second) {
                    break;
                }
            }
            // Si on arrive ici sans faire de break, forcement, la currentCloseShape est présente
            result->addShape(*(new Shape(entreeCatalogue.nature, temp, i)));
            somethingDone = true;
            i++;
        }
    }
    if(somethingDone)
        return result;
    else
        return NULL;
}


void ShapesList::add(ShapesList list) {
    std::vector<Shape> s = list.getShapes();
    shapes.reserve(s.size());
    shapes.insert(shapes.end(), s.begin() , s.end());

    std::vector<Contrainte> c = list.getContraintes();
    contraintes.reserve(c.size());
    contraintes.insert(contraintes.end(), c.begin(), c.end());
}

std::vector<Shape> ShapesList::getShapes()const {
    return shapes;
}

std::vector<Contrainte> ShapesList::getContraintes()const {
    return contraintes;
}

void ShapesList::setShapes(const std::vector<Shape> &shapes) {
    ShapesList::shapes = shapes;
}

void ShapesList::setContraintes(const std::vector<Contrainte> &contraintes) {
    ShapesList::contraintes = contraintes;
}

/**
 * Build groups of lines that form a close shape with constraints linked to it
 */
std::vector<ShapesList> ShapesList::buildGroups() {
    std::vector<Contrainte> contraintes = getTypeContrainte(JOINTURE);
    Graph g(shapes.size());
    //cout << endl << "dans le vecteur de contraintes de type jointure, ya : " << contraintes.size() << endl;
    for(Contrainte & c : contraintes){
        //cout << endl <<  "On ajoute l'edge :" << c.getShapes()[0].id << ", " << c.getShapes()[1].id << endl;
        g.addEdge(c.getShapes()[0].id, c.getShapes()[1].id);
    }

    std::vector<std::vector<int>> resultDFS = g.DFS();
    std::vector<ShapesList> result;

    // Peut yavoir un problème ici avec la gestion des pointeurs
    for(std::vector<int> const& shape : resultDFS){ // on boucle sur la liste des formes fermées renvoyées par le DFS
        result.push_back(ShapesList());
        for(auto const& element : shape){
            result.back().addShape(*(this->getShapeByID(element)));
        }
        std::vector<Contrainte> c = getContraintesConcerningShapes(result.back().shapes);
        result.back().contraintes.insert(result.back().contraintes.end(), c.begin(), c.end());
    }

    return result;
}
/**
 * TODO récupère les contraintes du type nomContrainte
 */
std::vector<Contrainte> ShapesList::getTypeContrainte(TypeContrainte nomContrainte)const {
    std::vector<Contrainte> result;

    for(const auto &contrainte : contraintes){
        if(contrainte.getTypeContrainte() == nomContrainte){
            result.push_back(contrainte);
        }
    }

    return result;
}
/**
 * Récupère une shape définie par son id
 * Fait par BEIER
 */
Shape* ShapesList::getShapeByID(int param_id) {
    Shape* result = NULL;

    for (Shape &shape : shapes) {
        if (shape.id == param_id) {
            result = &shape;
        }
    }
    return result;
}

void ShapesList::addShape(const Shape &shape) {
    shapes.push_back(shape);
}

int ShapesList::getNumberTypeContrainte(const TypeContrainte &nomContraintes)const {
    return getTypeContrainte(nomContraintes).size();
}

/**
 * Fait pas BEIER
 */
bool ShapesList::isContain(const std::vector<Shape> &shapes,const std::vector<Shape> &shapesConcerned){
    bool isContain=false;

    for (std::vector<Shape>::const_iterator iter = shapesConcerned.cbegin();iter != shapesConcerned.cend();iter++) {
        //Pour chaque élément de shapesConcerned,il cherche son type dans la list shapes
        for (std::vector<Shape>::const_iterator iterInner = this->shapes.cbegin();iterInner != this->shapes.cend();iterInner++) {
            //pour chaque element, si'l a trouvé, rendre isContrain true
            if (iter->getNature() == iterInner->getNature()) {
                isContain=true;
            }
        }
        if (!isContain) {
            return false;
        }
        //rendre isContrain false et puis recommence le prochain loop
        isContain = false;
    }

    return true;
}

std::vector<Contrainte> ShapesList::getContraintesConcerningShapes(const std::vector<Shape> &shapesConcerned) {
    std::vector<Contrainte> result;

    for (std::vector<Contrainte>::const_iterator iter = this->contraintes.begin();iter != this->contraintes.end();++iter) {
        if(isContain(iter->getShapes(), shapesConcerned)) {
            result.push_back(*iter);
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream&, const ShapesList& s){
    std::cout << std::endl << "*******Shapes*******" << std::endl;
    for(const Shape& shape : s.getShapes()){
        std::cout << "--> ";
        std::cout << shape;
    }
    std::cout << std::endl << "*******Contraintes*******"<< std::endl;
    for(const Contrainte& contrainte : s.getContraintes()){
        std::cout << contrainte;
    }
}