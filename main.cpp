#include "Kruskal.h"
#include "Prim.h"

int main() {
    Graph graph;
    graph.read_from_file("../data/input.txt");

    Kruskal kruskal;
    kruskal.prepare(graph);
    Graph new_kruskal = kruskal.execute();
    new_kruskal.save_to_file("../data/kruskal.txt");

    Prim prima;
    prima.prepare(graph);
    Graph new_prim = prima.execute();
    new_prim.save_to_file("../data/prim.txt");
    return 0;
}
