#include <iostream>
#include "Kruskal.h"

int main() {
    std::vector<Edge> edges =
    {
            {0, 1, 1},
            {0, 2, 3},
            {1, 2, 4},
            {1, 3, 6},
            {1, 4, 7},
            {3, 4, 2},
            {3, 2, 5}
    };
    Graph graph(edges);
    graph.print();

    Kruskal kr(graph);
    kr.execute();
    kr.print();
    return 0;
}
