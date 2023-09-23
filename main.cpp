#include <iostream>
#include "Graph.h"

int main() {
    std::vector<Edge> edges =
    {
            {0, 1, 1},
            {1, 2, 1},
            {2, 3, 2},
            {2, 4, 1},
            {3, 4, 1},
            {3, 0, 2},
            {4, 0, 2}
    };
    Graph graph(edges);
    graph.print();
    return 0;
}
