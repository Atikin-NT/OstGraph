//
// Created by atikin on 24.09.23.
//

#include "Prim.h"

/**
 * Подготовка данных и перевод из объекта Graph в список смежности, а так же заполнение вспомогательных элементов
 * @param graph
 */
void Prim::prepare(const Graph &graph) {
    G.clear();
    std::vector<std::vector<Pair>> adjList = graph.getList();
    G = adjList;
    node_count = graph.get_node_count();
    for(int i = 0; i < node_count - 1; i++)
        for(auto &edge: adjList[i])
            G[edge.first].emplace_back(std::make_pair(i, edge.second));

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

/**
 * Выполнение алгоритма Прима по поиску остовного дерева в графе
 * @return Объект графа
 */
Graph Prim::execute() {
    if (node_count == 1)
        return Graph();

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
            T.AddWeightedEdge(Edge(parent[i], i, dist[i]));
        }
    }

    return T;
}