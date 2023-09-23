//
// Created by atikin on 22.09.23.
//

#ifndef OSTGRAPH_KRUSKAL_H
#define OSTGRAPH_KRUSKAL_H
#include "Graph.h"

class Kruskal {
    Graph T;
    std::vector<Edge> G;
    int node_count;
    int* parent;
    int find_set(int i);
    void union_set(int u, int v);
public:
    Kruskal(Graph const &graph);
    void execute();
    void print();
    void print_parent();
};


#endif //OSTGRAPH_KRUSKAL_H
