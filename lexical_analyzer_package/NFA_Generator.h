
#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H
#include "Automata.h"
#include "SimpsonGraphBuilder.h"
#include <stack>
#include "../graph_package/Graph.h"
#include <fstream>
#include <iostream>

#include "unordered_map"

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

<<<<<<< HEAD
        vector<string> *get_reguler_exp();
        vector<string> *get_reguler_difi();
        vector <string> *reguler_exp;
        vector <string> *reguler_difi;


        string file_name;


        /*Hash map regExpmap*/
=======
        // Hash map to hold all the builded graphs to be able to check
        // if the graph is built before or not in keywords case or regular expression case
        unordered_map<string,Graph*> language_map;

        Graph *get_language_graph();
>>>>>>> 3f6e0359d629e663f883a44726396dfbcf73b552

};

#endif // NFA_GENERATOR_H

