//
// Created by atikin on 24.09.23.
//

#include "Prim.h"

void Prim::prepare(const Graph &graph) {
    G.clear();
    std::vector<std::vector<Pair>> adjList = graph.getList();
    G = adjList;
    for(int i = 0; i < graph.get_node_count(); i++)
        for(auto &edge: adjList[i])
            G[edge.first].emplace_back(std::make_pair(i, edge.second));

    node_count = graph.get_node_count();
    selected = new bool[node_count];
    std::memset(selected, false, node_count);
    selected[0] = true;
}

Prim::Prim() {
    G.clear();
    node_count = 0;
}

Prim::~Prim() {
    delete[] selected;
}

Graph Prim::execute(const Graph &graph) {
    prepare(graph);

    for (int i = 0; i < node_count; i++) {
        std::cout << i << " <——> ";
        for (Pair v: G[i]) {
            std::cout << "(" << v.first << ", w = " << v.second << ") ";
        }
        std::cout << std::endl;
    }

    std::vector<int> dist(node_count, INF); // Массив расстояний до каждой вершины
    std::vector<bool> used(node_count, false); // Массив посещенных вершин
    std::vector<int> parent(node_count, -1); // Массив предков для восстановления пути

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q; // Очередь с приоритетами
    dist[0] = 0; // Расстояние до первой вершины равно 0
    q.emplace(0, 0); // Добавляем первую вершину в очередь
    Graph T;

    while (!q.empty()) {
        int v = q.top().second; // Извлекаем вершину с наименьшим расстоянием
        q.pop();

        if (used[v]) continue; // Если вершина уже была посещена, пропускаем ее
        used[v] = true; // Помечаем вершину как посещенную

        for (auto edge : G[v]) { // Проходим по всем смежным вершинам
            int to = edge.first;
            int weight = edge.second;

            if (dist[to] > weight && !used[to]) { // Если новое расстояние до вершины меньше текущего и вершина еще не была посещена
                dist[to] = weight; // Обновляем расстояние до вершины
                parent[to] = v; // Запоминаем предка
                q.emplace(dist[to], to); // Добавляем вершину в очередь с новым расстоянием
            }
        }
    }

    int sum_weight = 0; // Сумма весов ребер минимального остовного дерева
    for (int i = 0; i < node_count; i++) {
        if (parent[i] != -1) { // Если у вершины есть предок
            sum_weight += dist[i]; // Добавляем вес ребра к сумме
            std::cout << parent[i] << " " << i << std::endl; // Выводим ребро на экран
            T.AddWeightedEdge(Edge(parent[i], i, dist[i]));
        }
    }

    std::cout << "Weight of MST: " << sum_weight << std::endl; // Выводим сумму весов ребер на экран

    return T;
}