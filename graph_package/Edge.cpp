#include "Edge.h"

//Constructor
Edge::Edge(Node* start_node , Node* end_node , string value )
{
    //ctor
    this->value = value;
    this->start_node = start_node;
    this->end_node = end_node;
}

/**
*   return the value of the edge
**/
string Edge::get_value(){
    return value;
}

/**
*   return start node
**/
Node* Edge::get_start_Node(){
    return start_node;
}

/**
*   return end node
**/
Node* Edge::get_end_node(){
    return end_node;
}

// Destructor
Edge::~Edge()
{
    //dtor
}
