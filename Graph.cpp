//
// Created by atikin on 22.09.23.
//

#include "Graph.h"


Graph::Graph(): size(0) {
    adjList.clear();
}

Graph::Graph(const std::vector<Edge> &edges): size(0), node_count(0) {
    adjList.clear();
    for(auto &edge: edges)
        AddWeightedEdge(edge);
}

void Graph::print() {
    for (int i = 0; i <= node_count; i++) {
        std::cout << i << " ——> ";
        for (Pair v: adjList[i]) {
            std::cout << "(" << v.first << ", " << v.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::AddWeightedEdge(const Edge &edge) {
    int max_src = std::max(edge.src, edge.dest);
    node_count = std::max(node_count, max_src);
    if (max_src > size){
        adjList.resize(size + batch_size);
        size += batch_size;
    }
    adjList[edge.src].emplace_back(edge.dest, edge.weight);
    adjList[edge.dest].emplace_back(edge.src, edge.weight);
}