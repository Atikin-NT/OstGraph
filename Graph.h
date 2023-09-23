//
// Created by atikin on 22.09.23.
//

#ifndef OSTGRAPH_GRAPH_H
#define OSTGRAPH_GRAPH_H
#include <iostream>
#include <vector>

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w): src(s), dest(d), weight(w) {}
};

typedef std::pair<int, int> Pair;

class Graph {
    std::vector<std::vector<Pair>> adjList;
    size_t size;
    int node_count;
    int batch_size = 5;
public:
    Graph();
    Graph(std::vector<Edge> const &edges);
    void AddWeightedEdge(Edge const& edge);
    void print();
    [[nodiscard]] std::vector<std::vector<Pair>> getList() const;
    int get_node_count() const;
};


#endif //OSTGRAPH_GRAPH_H
