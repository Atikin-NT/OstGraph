//
// Created by atikin on 22.09.23.
//

#ifndef OSTGRAPH_KRUSKAL_H
#define OSTGRAPH_KRUSKAL_H
#include "OstBase.h"

class Kruskal: OstBase {
    std::vector<Edge> G;  // вектор и ребер графа
    int node_count;  // количество вершин в графе
    int* parent;  // вспомогательный массив для множеств
    int* rank;  // вспомогательный массив для множеств
    int find_set(int i);
    void union_set(int u, int v);
public:
    Kruskal();
    ~Kruskal();
    void prepare(const Graph &graph) override;
    Graph execute() override;
};


#endif //OSTGRAPH_KRUSKAL_H
