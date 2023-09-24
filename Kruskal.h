//
// Created by atikin on 22.09.23.
//

#ifndef OSTGRAPH_KRUSKAL_H
#define OSTGRAPH_KRUSKAL_H
#include "OstBase.h"

class Kruskal: OstBase {
    std::vector<Edge> G;
    int node_count;
    int* parent;
    int find_set(int i);
    void union_set(int u, int v);
    void prepare(const Graph &graph) override;
public:
    Kruskal();
    Graph execute(const Graph &graph) override;
};


#endif //OSTGRAPH_KRUSKAL_H
