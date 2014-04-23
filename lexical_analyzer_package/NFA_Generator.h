
#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"
#include "SimpsonGraphBuilder.h"
#include "../graph_package/Graph.h"

#include <fstream>
#include <iostream>

#include "unordered_map"
#include "ExpressionEvaluator.h"

using namespace std;

class NFA_Generator : public Automata
{
    public:
        NFA_Generator(string file_path);
        Graph* getAutomata();

        virtual ~NFA_Generator();
    protected:

    private:
        string file_path;
        SimpsonGraphBuilder graph_builder;
        ExpressionEvaluator exp_eval = ExpressionEvaluator(&graph_builder);

        // Hash map to hold all the builded graphs to be able to check
        // if the graph is built before or not in keywords case or regular expression case
        unordered_map<string,Graph*> language_map;

        Graph *get_language_graph();

};

#endif // NFA_GENERATOR_H

