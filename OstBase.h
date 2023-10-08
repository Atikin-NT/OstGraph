//
// Created by atikin on 24.09.23.
//

#ifndef OSTGRAPH_OSTBASE_H
#define OSTGRAPH_OSTBASE_H
#include "Graph.h"

/**
 * Абстрактный класс графа, в котором определены основные методы для каждого алгоритма
 */
class OstBase {
public:
    virtual void prepare(const Graph &graph) = 0; // функция подготовки данных
    virtual Graph execute() = 0;  // функция выолнения
};


#endif //OSTGRAPH_OSTBASE_H
