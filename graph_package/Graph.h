#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"


class Graph
{
    public:
        Node* startNode;
        Node* getStartNode();
        Graph();
        virtual ~Graph();
    protected:
    private:
};

#endif // GRAPH_H
