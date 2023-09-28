//
// Created by atikin on 24.09.23.
//

#ifndef OSTGRAPH_PRIM_H
#define OSTGRAPH_PRIM_H
#include "OstBase.h"
#include <cstring>
#include <queue>

const int INF = 1e9; // Бесконечность

class Prim: OstBase {
    std::vector<std::vector<Pair>> G;
    int node_count;
    bool* selected;
    void prepare(const Graph &graph) override;
public:
    Prim();
    ~Prim();
    Graph execute(const Graph &graph) override;
};


#endif //OSTGRAPH_PRIM_H
