
#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"
#include "SimpsonGraphBuilder.h"

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
        void setAutomata(Graph* graph);

        Graph* read_from_file(string file_name);

        SimpsonGraphBuilder graph_builder;

        vector<string> *get_reguler_exp();
        vector<string> *get_reguler_difi();
        vector <string> *reguler_exp;
        vector <string> *reguler_difi;
         stack <string> operand;
         stack <string> operation;

        string file_name;
        ///////////////////////try bas

};

#endif // NFA_GENERATOR_H

