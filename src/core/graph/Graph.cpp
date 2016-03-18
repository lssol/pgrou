//
// Created by seti on 01/03/16.
//

#include "Graph.h"
// C++ program to print DFS traversal for a given given graph
#include<iostream>
#include <list>
#include <vector>

using namespace std;

Graph::Graph(int V)
{
    this->vertexCount = V;
    adj = new list<int>[V];
}
std::vector<std::vector<int>> Graph::DFS() {
    std::vector<std::vector<int>> result;
    VertexState *state = new VertexState[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        state[i] = White;
    }
    path.erase(path.begin(), path.end());
    runDFS(0, state);
    delete[] state;

    for (std::list<std::list<int>>::const_iterator i = closedShapes.begin(), end = closedShapes.end(); i != end; ++i) {
        result.push_back(*new std::vector<int>);
        for (std::list<int>::const_iterator j = (*i).begin(), end = (*i).end(); j != end; ++j) {
            result.back().push_back(*j);
        }
    }
}
void Graph::runDFS(int u, VertexState state[]) {
    cout << u;
    path.push_back(u);
    state[u] = Gray;
    for (int v = 0; v < vertexCount; v++) {
        if (isEdge(u, v) && state[v] == Gray) {
            cutToCycle(v);
        }
    }
    for (int v = 0; v < vertexCount; v++) {
        if (isEdge(u, v) && state[v] == White) {
            runDFS(v, state);
        }
    }
    state[u] = Black;
}

void Graph::addEdge(int a, int b) {
    this->adj[a].push_back(b);
    this->adj[b].push_back(a);
}

bool Graph::isEdge(int a, int b) {
    for (std::list<int>::const_iterator iterator = adj[a].begin(), end = adj[a].end(); iterator != end; ++iterator) {
        if(*iterator == b){
            return true;
        }
    }
    return false;
}

void Graph::cutToCycle(int v) {
    cout << "cut : " << v << endl;
    list<int> cycle;
    bool recording = false;
    for (std::list<int>::const_iterator iterator = path.begin(), end = path.end(); iterator != end; ++iterator) {
        if(*iterator == v){
            recording = true;
        }
        if(recording){
            cycle.push_back(*iterator);
        }
    }
    cycle.push_back(v);
    if(cycle.size() > 3){
        closedShapes.push_back(cycle);
    }
}
