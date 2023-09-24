//
// Created by atikin on 24.09.23.
//

#ifndef OSTGRAPH_OSTBASE_H
#define OSTGRAPH_OSTBASE_H
#include "Graph.h"

class OstBase {
public:
    virtual void prepare(const Graph &graph) = 0;
    virtual Graph execute(const Graph &graph) = 0;
};


#endif //OSTGRAPH_OSTBASE_H
