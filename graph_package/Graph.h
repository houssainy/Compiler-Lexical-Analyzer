#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

class Graph
{
    public:
        Graph(Node* start);
        Graph();

        void set_start_node(Node* start_node);
        Node * get_start_node();

        void set_end_node(Node* end_node);
        Node * get_end_node();

         void set_graph_name(string name);
         string get_graph_name();

        virtual ~Graph();
    protected:
    private:
        Node * start_node;
        Node * end_node;
        string graph_name;


};

#endif // GRAPH_H
