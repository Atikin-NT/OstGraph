#include <iostream>
#include "Graph.h"

int main() {
    std::vector<Edge> edges =
    {
            {1, 2, 1},
            {2, 3, 1},
            {3, 4, 2},
            {3, 5, 1},
            {4, 5, 1},
            {4, 1, 2},
            {5, 1, 2}
    };
    Graph graph(edges);
    graph.print();
    graph.AddWeightedEdge(Edge(7, 1, 10));
    graph.print();
    return 0;
}
