
#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"
#include "SimpsonGraphBuilder.h"
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

        /*Hash map regExpmap*/
        unordered_map<string,Graph*> reg_ex_map;
};

#endif // NFA_GENERATOR_H

