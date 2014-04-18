#include "Graph.h"

Graph::Graph(Node* start_node)
{
    //ctor
    this->start_node=start_node;
}

Graph::Graph(){

}

/**
*   Set start node
**/
void Graph::set_start_node(Node* start_node){
    this->start_node = start_node;
}

/**
*   Return startNode
**/
Node * Graph::get_start_node(){
    return start_node;
}

/**
*   Set end node
**/
void Graph::set_end_node(Node* end_node){
    this->end_node = end_node;
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
