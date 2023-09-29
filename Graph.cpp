//
// Created by atikin on 22.09.23.
//

#include "Graph.h"


Graph::Graph(): size(0) {
    adjList.clear();
    node_count = 0;
}

Graph::Graph(const std::vector<Edge> &edges): size(0), node_count(0) {
    adjList.clear();
    node_count = 0;
    for(auto &edge: edges)
        AddWeightedEdge(edge);
}

void Graph::print() {
    for (int i = 0; i <= node_count; i++) {
        std::cout << i << " <——> ";
        for (Pair v: adjList[i]) {
            std::cout << "(" << v.first << ", w = " << v.second << ") ";
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
}

std::vector<std::vector<Pair>> Graph::getList() const {
    return adjList;
}

int Graph::get_node_count() const{
    return node_count + 1;
}

void Graph::read_from_file(const std::string& file_path) {
    std::ifstream file;
    file.open(file_path);
    std::string line;
    if ( file.is_open() ) {
        while ( std::getline (file, line) ) {
//            std::getline (file, line);
            std::cout << line << std::endl;

            std::vector<int> v;
            std::string elem;
            std::stringstream line_stream(line);
            while (getline(line_stream, elem, ' ')) {
                v.push_back(std::stoi(elem));
            }
            AddWeightedEdge(Edge(v[0], v[1], v[2]));
        }
    }
}

void Graph::save_to_file(const std::string &file_path) {
    std::ofstream file;
    file.open(file_path);
    if (file.is_open()){
        for (int i = 0; i <= node_count; i++) {
            file << i << " <——> ";
            for (Pair v: adjList[i]) {
                file << "(" << v.first << ", w = " << v.second << ") ";
            }
            file << std::endl;
        }
    }
}