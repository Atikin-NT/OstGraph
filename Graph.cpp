//
// Created by atikin on 22.09.23.
//

#include "Graph.h"


Graph::Graph(): size(0) {
    adjList.clear();
}

Graph::Graph(const std::vector<Edge> &edges): size(edges.size() - 1) {
    adjList.resize(size);
    for(auto &edge: edges){
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        adjList[src].emplace_back(dest, weight);
        adjList[dest].emplace_back(src, weight);
    }
}

void Graph::print() {
    for (int i = 0; i < size; i++) {
        std::cout << i << " ——> ";
        for (Pair v: adjList[i]) {
            std::cout << "(" << v.first << ", " << v.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::AddWeightedEdge(const Edge &edge) {
    int max_src = std::max(edge.src, edge.dest);
    if (max_src > size){
        adjList.resize(size + batch_size);
        size += batch_size;
    }
    adjList[edge.src].emplace_back(edge.dest, edge.weight);
    adjList[edge.dest].emplace_back(edge.src, edge.weight);
}