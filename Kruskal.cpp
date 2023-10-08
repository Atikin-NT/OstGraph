//
// Created by atikin on 22.09.23.
//

#include "Kruskal.h"

/**
 * Определение в каком множестве находится вершина
 * @param i индекс вершины
 * @return индекс множества
 */
int Kruskal::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

/**
 * Объединение вершин в одно множество
 * @param u первая вершина
 * @param v вторая вершина
 */
void Kruskal::union_set(int u, int v) {
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[u] = v;
        rank[v]++;
    }
}

/**
 * Подготовка данных: перевод в определенную структуру данных и заполнение вспомогательных элементов.
 * @param graph Объект графа
 */
void Kruskal::prepare(const Graph &graph) {
    G.clear();
    std::vector<std::vector<Pair>> adjList = graph.getList();
    node_count = graph.get_node_count();
    for(int i = 0; i < node_count - 1; i++)
        for(auto &edge: adjList[i])
            G.emplace_back(i, edge.first, edge.second);

    parent = new int[node_count];
    rank = new int[node_count];
    for (int i = 0; i < node_count; i++){
        parent[i] = i;
        rank[i] = 1;
    }
}

Kruskal::Kruskal() {
    G.clear();
    node_count = 0;
    parent = nullptr;
}

Kruskal::~Kruskal() {
    delete[] parent;
    delete[] rank;
}

/**
 * Поиск остовного дерева. Предпологается, что данные уже отсортированы
 * @return Объект графа
 */
Graph Kruskal::execute() {
    Graph T;

    int i, uRep, vRep;
    std::sort(G.begin(), G.end());  // сортируем ребра по их весу
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].src);  // узнаем к каким множества принадлежат вершины
        vRep = find_set(G[i].dest);
        if (uRep != vRep) {  // если к разным
            T.AddWeightedEdge(G[i]);  // добавляем в наш граф
            union_set(uRep, vRep);  // и объединяем эти множества
        }
    }
    return T;
}
