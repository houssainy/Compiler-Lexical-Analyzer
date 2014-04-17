#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"

#include <iostream>

using namespace std;

class NFA_Generator : public Automata
{
    public:
        NFA_Generator(string file_name);
        Graph* getAutomata();
        virtual ~NFA_Generator();
    protected:
    private:
        Graph* setAutomata(Graph* graph);
        Graph* build_graph_for_node(string value);
        Graph* positive_clousure_operation(Graph* graph);
        Graph* clousure_operation(Graph* graph);
        Graph* or_operation(Graph* g1 , Graph* g2);
        Graph* and_operation(Graph* g1 , Graph* g2);
        Graph* read_from_file(String file_name);
        vector<string> *get_reguler_exp();
        vector<string> *get_reguler_difi();
        vector <string> *reguler_exp;
        vector <string> *reguler_difi;
        string file_name;


};

#endif // NFA_GENERATOR_H
