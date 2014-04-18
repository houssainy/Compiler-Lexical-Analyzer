#ifndef SIMPSONGRAPHBUILDER_H
#define SIMPSONGRAPHBUILDER_H

#include "../graph_package/Graph.h"
#include <iostream>

using namespace std;
class SimpsonGraphBuilder
{
    public:
        SimpsonGraphBuilder();
        virtual ~SimpsonGraphBuilder();
    private:
        Graph* init_graph(string value);
        Graph* positive_clousure_operation(Graph* g1);
        Graph* clousure_operation(Graph* g1);
        Graph* or_operation(Graph* g1 , Graph* g2);
        Graph* and_operation(Graph* g1 , Graph* g2);
};

#endif // SIMPSONGRAPHBUILDER_H
