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
    std::vector<std::vector<Pair>> G;  // список смежности
    int node_count;  // количество вершин
    bool* selected;  // массив с флажками: были в вершине или нет
public:
    Prim();
    ~Prim();
    void prepare(const Graph &graph) override;
    Graph execute() override;
};


#endif //OSTGRAPH_PRIM_H
