#include "Graph.h"

Graph::Graph(Node* start_node)
{
this.start_node=start_node;
    //ctor
}
Node* Graph::get_start_node(){
return this.start_node;
}




Graph::~Graph()
{
    //dtor
}
