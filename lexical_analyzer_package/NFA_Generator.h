#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"
#include "SimpsonGraphBuilder.h"

#include "../graph_package/Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "unordered_map"
#include "ExpressionEvaluator.h"

using namespace std;

class NFA_Generator : public Automata
{
    public:
        NFA_Generator(string file_path);
        Graph* getAutomata();
        unordered_map<char,int> *get_input_map(){
            return &input_map;
        }
        virtual ~NFA_Generator();
    protected:
    private:
        string file_path;
        SimpsonGraphBuilder graph_builder;
        ExpressionEvaluator exp_eval = ExpressionEvaluator(&graph_builder);

        // Hash map to hold all the builded graphs to be able to check
        // if the graph is built before or not in keywords case or regular expression case
        unordered_map<string,Graph*> language_map;

        //Map to hold all inputs and its mapping to column number in transition table
        unordered_map<char,int> input_map;
        int input_count = 0;

        void handle_keyword_graph(string line);
        void handle_punctuation_graph(string line);
        void handle_regular_exp_or_def_graph(string line);

        Graph* copy_graph(Graph *g);
        Graph* build_new_input_graph(string temp_string );
        Graph *get_language_graph();

};

#endif // NFA_GENERATOR_H

