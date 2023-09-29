#include <iostream>
#include "Kruskal.h"
#include "Prim.h"

int main() {
    Graph graph;
    graph.read_from_file("../data/input.txt");

    Graph new_kruskal = Kruskal().execute(graph);
    new_kruskal.save_to_file("../data/kruskal.txt");

    Graph new_prim = Prim().execute(graph);
    new_prim.save_to_file("../data/prim.txt");
    return 0;
}
