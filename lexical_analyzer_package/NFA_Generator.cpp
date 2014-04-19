#include "NFA_Generator.h"
#include "strings.h"
#include <stdio.h>
#include <vector>
#include <iostream>

NFA_Generator::NFA_Generator(string file_name)
{

    this->file_name=file_name;

    //ctor
}

void NFA_Generator::setAutomata(Graph* graph){
    Node start_node= Node();
    //start_node->add_child(graph.get_start_node())
}

Graph* NFA_Generator::getAutomata(){
    return NULL;
}

NFA_Generator::~NFA_Generator()
{
    //dtor
}
