#include "Graph.h"

Graph::Graph(Node* start_node)
{
this.start_node=start_node;
    //ctor
}

/**
*   Return startNode
**/
Node * Graph::get_start_node(){
    return start_node;
}

/**
*   Return endNode
**/
Node * Graph::get_end_node(){
    return end_node;
}
/**
* return the Node number
**/
 int Node:: get_node_num(){
 return this->node_num;
 }

int increas_node_number(){
return this->node_num++;
}

Graph::~Graph()
{
    //dtor
}
