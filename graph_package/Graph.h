#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

class Graph
{
    public:
        Graph(Node* start);
         Node * get_start_node();
        Node * get_end_node();
        virtual ~Graph();
    protected:
    private:
     int get_node_num();
    int increas_node_number();
        Node * start_node;
        Node * end_node;
    int node_num ;

};

#endif // GRAPH_H
