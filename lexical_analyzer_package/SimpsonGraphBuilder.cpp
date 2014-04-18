#include "SimpsonGraphBuilder.h"

SimpsonGraphBuilder::SimpsonGraphBuilder()
{
    //ctor
}

/**
*   Build sempson's initial graph for only one input
**/
Graph* SimpsonGraphBuilder::init_graph(string value){
    Graph* graph = new Graph();
    Node * start_node = new Node();
    Node * end_node = new Node();

    start_node->add_child(end_node, "\L");

    graph->set_start_node(start_node);
    graph->set_end_node(end_node);

    return graph;
}
/**
*   And operation
*   e.g: AB
**/
Graph* SimpsonGraphBuilder::and_operation(Graph* g1 , Graph* g2){
        //Connect the two graphs
        g1->set_end_node(g2->get_start_node());

        return g1;
}

/**
*   OR operation
*   e.g : A|B
**/
Graph* SimpsonGraphBuilder::or_operation(Graph* g1 , Graph* g2){
    Graph* graph = new Graph();
    Node * start_node = new Node();
    Node * end_node = new Node();

    // Connect the new End node to the two graphs
    g1->get_end_node()->add_child(end_node,"\L");
    g2->get_end_node()->add_child(end_node,"\L");

    //Connect the new Start node to the two graphs
    start_node->add_child(g1->get_start_node(),"\L");
    start_node->add_child(g2->get_start_node(),"\L");

    // Add the start and end nodes to the graph
    graph->set_start_node(start_node);
    graph->set_end_node(end_node);

    return graph;
}

/**
*   Clousure operation
*   e.g: A*
**/
Graph* SimpsonGraphBuilder::clousure_operation(Graph* g1){
    Graph* graph = new Graph();
    Node* start_node = new Node();
    Node* end_node = new Node();

    // 1..*
    start_node->add_child(g1->get_start_node() , "\L");
    g1->get_end_node()->add_child(end_node,"\L");
    g1->get_end_node()->add_child(g1->get_start_node(),"\L");

    //0..*
    start_node->add_child(end_node , "\L");

    // Add the start and end nodes to the graph
    graph->set_start_node(start_node);
    graph->set_end_node(end_node);
    return graph;
}
/**
*   Clousure operation
*   e.g: A+
**/
Graph* SimpsonGraphBuilder::positive_clousure_operation(Graph* g1){
    Graph * graph = new Graph();
    Node * end_node = new Node();

    // 1..+
    g1->get_end_node()->add_child(g1->get_start_node(),"\L");

    // finish
    g1->get_end_node()->add_child(end_node,"\L");

    // Add the start and end nodes to the graph
    graph->set_start_node(g1->get_start_node());
    graph->set_end_node(end_node);

    return graph;
}

SimpsonGraphBuilder::~SimpsonGraphBuilder()
{
    //dtor
}
