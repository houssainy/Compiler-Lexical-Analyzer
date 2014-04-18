#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Node;

class Edge
{
    public:
        Edge(Node* start_node , Node* end_node , char value );

        char get_value();
        Node* get_start_Node();
        Node* get_end_node();

        virtual ~Edge();
    protected:
    private:
        char value;
        Node *start_node;
        Node *end_node;
};

#endif // EDGE_H
