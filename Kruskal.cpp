//
// Created by atikin on 22.09.23.
//

#include "Kruskal.h"

struct less_than_key
{
    inline bool operator() (const Edge& e1, const Edge& e2)
    {
        return (e1.weight < e2.weight);
    }
};

int Kruskal::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Kruskal::union_set(int u, int v) {
    parent[u] = parent[v];
}

Kruskal::Kruskal(const Graph &graph) {
    G.clear();
    std::vector<std::vector<Pair>> adjList = graph.getList();
    for(int i = 0; i < graph.get_node_count(); i++)
        for(auto &edge: adjList[i])
            G.emplace_back(i, edge.first, edge.second);

    node_count = graph.get_node_count();
    parent = new int[node_count];
    for (int i = 0; i < node_count; i++)
        parent[i] = i;

    print_parent();
}

void Kruskal::execute() {
    int i, uRep, vRep;
    print_parent();
    std::sort(G.begin(), G.end(), less_than_key());
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].src);
        vRep = find_set(G[i].dest);
        if (uRep != vRep) {
            T.AddWeightedEdge(G[i]);  // add to tree
            union_set(uRep, vRep);
        }
        print_parent();
    }
}

void Kruskal::print() {
    T.print();
}

void Kruskal::print_parent() {
    for (int i = 0; i < node_count; i++) {
        std::cout << "parent[" << i << "] = " << parent[i];
        std::cout << std::endl;
    }
    std::cout << "-------------" << std::endl;
}