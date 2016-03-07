#include <bits/stl_map.h>
#include "ShapesList.h"
#include "../core/graph/Graph.h"

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
std::vector<> ShapesList::buildGroups() {
    std::vector<Contrainte> contraintes = getTypeContrainte(JOINTURE);
    Graph g(contraintes.size());

    for(auto const& c : contraintes){
        g.addEdge(c.getShapes()[0].id, c.getShapes()[1].id);
    }
    std::vector<std::vector<int>> result = g.DFS();

    // TODO transormer cette liste en liste de shape et envoyer toutes les contraintes qui vont avec chaque

    return result;
}
/**
 * TODO
 */
std::vector<Contrainte> ShapesList::getTypeContrainte(TypesContrainte nomContraintes) {
    std::vector<Contrainte> contraintes;

    return contraintes;
}
