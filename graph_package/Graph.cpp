#include "Graph.h"

Graph::Graph()
{
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

Graph::~Graph()
{
    //dtor
}
