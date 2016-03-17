//
// Created by seti on 01/03/16.
//

#ifndef CLOSEDWALKS_GRAPH_H
#define CLOSEDWALKS_GRAPH_H

#include <list>


enum VertexState {
    White, Gray, Black
};


class Graph {
protected:
    int vertexCount = 0;
    std::list<int> *adj;
    std::list<std::list<int>> closedShapes;
    std::list<int> path;
    bool isEdge(int a, int b);
public:
    void addEdge(int a, int b);
    std::vector<std::vector<int>> DFS();
    void runDFS(int u, VertexState state[]);

    Graph(int V);

    void cutToCycle(int i);
};


#endif //CLOSEDWALKS_GRAPH_H
