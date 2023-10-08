//
// Created by atikin on 22.09.23.
//

#ifndef OSTGRAPH_GRAPH_H
#define OSTGRAPH_GRAPH_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

/**
 * Структура для сохранения ребра
 */
struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w): src(s), dest(d), weight(w) {}

    // оператор перегрузки для сравнения во время сортировки
    bool operator<(const Edge& e) const {
        return (weight < e.weight);
    }
};

typedef std::pair<int, int> Pair;

class Graph {
    std::vector<std::vector<Pair>> adjList;
    size_t size;
    int node_count;
    int batch_size = 0;
public:
    Graph();
    Graph(std::vector<Edge> const &edges);
    void AddWeightedEdge(Edge const& edge);
    void print();
    void read_from_file(const std::string& file_path);
    void save_to_file(const std::string& file_path);
    [[nodiscard]] std::vector<std::vector<Pair>> getList() const;
    [[nodiscard]] int get_node_count() const;
};


#endif //OSTGRAPH_GRAPH_H
