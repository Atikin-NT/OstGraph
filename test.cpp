#include <iostream>
#include "Kruskal.h"
#include "Prim.h"
#include <random>
#include <time.h>

/**
 * Генерация случайного графа
 * @param n - количество вершин
 * @param m - количество ребер
 * @param q - верхния граница по весам
 * @param r - нижняя граница по весам
 * @return объект графа
 */
Graph generate_random_graph(int n, int m, int r, int q) {
    Graph graph;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    std::uniform_int_distribution<int> uni(q, r);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dis(gen) <= m / ((double)n * (n - 1) / 2)) {
                int random_weight = uni(rd);
                graph.AddWeightedEdge(Edge(i, j, random_weight));
            }
        }
    }

    return graph;
}


int main() {
    const int N_MAX = 4000 + 1;
    const int STEP = 100;
    const int Q = 1;
    const int R = 1000000;
    double result[200][2];

    Kruskal kruskal;
    Prim prima;

    for (int r = 1; r < 201; ++r) {
        int n = N_MAX;
        int m = 1000 * n;
        Graph g = generate_random_graph(n, m, r, Q);
        kruskal.prepare(g);

        clock_t tStart = clock();

        kruskal.execute();

        double end_time = (double) (clock() - tStart) / CLOCKS_PER_SEC;
        result[r-1][0] = end_time;
        printf("n = %d, m = %d\n", n, m);
        printf("Time Kruskal taken: %.2fs\n", end_time);
        printf("----------------\n");

        prima.prepare(g);
        tStart = clock();

        prima.execute();

        end_time = (double) (clock() - tStart) / CLOCKS_PER_SEC;
        result[r-1][1] = end_time;
        printf("n = %d, m = %d, r = %d\n", n, m, r);
        printf("Time Prima taken: %.2fs\n", end_time);
        printf("----------------\n");
    }

    std::ofstream file;
    file.open("../data/test_step1_m_2.txt");
    if (file.is_open())
        for (auto & i : result)
            file << i[0] << " " << i[1] << std::endl;
    file.close();
    return 0;
}