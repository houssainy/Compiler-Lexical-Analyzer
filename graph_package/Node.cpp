#include "Node.h"

Node::Node()
{
    //ctor
}

/**
*   Get All the ourward edges from this node
*/
vector<Edge>* Node::get_children(){
    return children;
}

/**
*   Add new ourward edge to the given node and value
**/
void Node::add_child(Node* end_node, string value){
    Edge *e = new Edge(this, end_node , value);
    children->push_back(*e);
}

/**
*   Set Acceptance State of the Node
**/
void Node::set_acceptance_state(bool is_acceptance){
    this->is_acceptance = is_acceptance;
}

/**
* return is this node acceptance state?
**/
bool Node::is_acceptance_node(){
    return is_acceptance;
}

Node::~Node()
{
    //dtor
}
