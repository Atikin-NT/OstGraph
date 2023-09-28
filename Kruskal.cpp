//
// Created by atikin on 22.09.23.
//

#include "Kruskal.h"

int Kruskal::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Kruskal::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Kruskal::prepare(const Graph &graph) {
    G.clear();
    std::vector<std::vector<Pair>> adjList = graph.getList();
    for(int i = 0; i < graph.get_node_count(); i++)
        for(auto &edge: adjList[i])
            G.emplace_back(i, edge.first, edge.second);

    node_count = graph.get_node_count();
    parent = new int[node_count];
    for (int i = 0; i < node_count; i++)
        parent[i] = i;
}

Kruskal::Kruskal() {
    G.clear();
    node_count = 0;
    parent = nullptr;
}

Kruskal::~Kruskal() {
    delete[] parent;
}

Graph Kruskal::execute(const Graph &graph) {
    prepare(graph);
    Graph T;

    int i, uRep, vRep;
    std::sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].src);
        vRep = find_set(G[i].dest);
        if (uRep != vRep) {
            T.AddWeightedEdge(G[i]);  // add to tree
            union_set(uRep, vRep);
        }
    }
    return T;
}
