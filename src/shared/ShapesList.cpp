#include <bits/stl_map.h>
#include <bits/unique_ptr.h>
#include "ShapesList.h"
#include "../core/graph/Graph.h"
#include "../core/ShapesForAnalysis.h"

ShapesList::ShapesList()
{
}

ShapesList::~ShapesList()
{
}

/**
 * Prend un type de Forme shape et renvoit la liste des shape présents dans la liste des shapes (attribut) CONTRAINTES?????
 */
ShapesList ShapesList::search(const Shape &shape) {
    ShapesList result;

    Shape currentShape;




    return result;
}


void ShapesList::add(ShapesList list) {
    shapes.insert(shapes.end(), list.getShapes().begin(), list.getShapes().end());
    contraintes.insert(contraintes.end(), list.getContraintes().begin(), list.getContraintes().end());
}

std::vector<Shape> &ShapesList::getShapes() {
    return shapes;
}

std::vector<Contrainte> &ShapesList::getContraintes() {
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
std::vector<ShapesForAnalysis> ShapesList::buildGroups() {
    std::vector<Contrainte> contraintes = getTypeContrainte(JOINTURE);
    Graph g(contraintes.size());

    for(auto const& c : contraintes){
        g.addEdge(c.getShapes()[0].id, c.getShapes()[1].id);
    }

    std::vector<std::vector<int>> resultDFS = g.DFS();
    std::vector<ShapesForAnalysis> result;

    // Peut yavoir un problème ici avec la gestion des pointeurs
    for(auto const& shape : resultDFS){ // on boucle sur la liste des formes fermées renvoyées par le DFS
        std::unique_ptr<ShapesForAnalysis> p(new ShapesForAnalysis);
        result.push_back(*p);
        for(auto const& element : shape){
            p->shapes.push_back(this->getShapeByID(element));
        }
        std::vector<Contrainte> c = getContraintesConcerningShapes(p->shapes);
        p->contraintes.insert(p->contraintes.end(), c.begin(), c.end());
    }

    return result;
}
/**
 * TODO récupère les contraintes du type nomContrainte
 */
std::vector<Contrainte> ShapesList::getTypeContrainte(TypesContrainte nomContraintes) {
    std::vector<Contrainte> contraintes;

    return contraintes;
}
/**
 * TODO récupère une shape définie par son id
 */
Shape ShapesList::getShapeByID(int id) {
    return <#initializer#>;
}

/**
 * TODO Recupère toutes les contraintes qui concernent les shapes (elementaires) (il faut que les deux elements de la contrainte soient présent dans la liste des shapes)
 */
std::vector<Contrainte> ShapesList::getContraintesConcerningShapes(const std::vector<Shape> &shapesConcerned) {
    return std::vector<Contrainte>();
}
