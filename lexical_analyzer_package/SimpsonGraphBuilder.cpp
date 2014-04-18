#include "SimpsonGraphBuilder.h"

#include "../utilities_package/Util.h"

SimpsonGraphBuilder::SimpsonGraphBuilder()
{
    //ctor
}

/**
*   Build sempson's initial graph for only one input
**/
Graph* SimpsonGraphBuilder::init_graph(string value){
    Graph graph;
    Node * start_node = new Node();
    Node * end_node = new Node();

    start_node->add_child(end_node, "\L");

    return &graph;
}

Graph* SimpsonGraphBuilder::positive_clousure_operation(Graph* g1){

}
Graph* SimpsonGraphBuilder::clousure_operation(Graph* g1){

}
Graph* SimpsonGraphBuilder::or_operation(Graph* g1 , Graph* g2){

}
Graph* SimpsonGraphBuilder::and_operation(Graph* g1 , Graph* g2){

}
SimpsonGraphBuilder::~SimpsonGraphBuilder()
{
    //dtor
}
