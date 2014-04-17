#ifndef SIMPSONGRAPHBUILDER_H
#define SIMPSONGRAPHBUILDER_H


class SimpsonGraphBuilder
{
    public:
        SimpsonGraphBuilder();
        virtual ~SimpsonGraphBuilder();
    protected:
    private:
        Graph* build_graph_for_node(string value);
        Graph* positive_clousure_operation(Graph* graph);
        Graph* clousure_operation(Graph* graph);
        Graph* or_operation(Graph* g1 , Graph* g2);
        Graph* and_operation(Graph* g1 , Graph* g2);
};

#endif // SIMPSONGRAPHBUILDER_H
