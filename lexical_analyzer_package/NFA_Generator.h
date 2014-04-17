#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

#include "Automata.h"
#include "SimpsonGraphBuilder.h"

#include <iostream>

using namespace std;

class NFA_Generator : public Automata
{
    public:
        NFA_Generator();
        Graph* getAutomata();
        virtual ~NFA_Generator();
    protected:
    private:
        SimpsonGraphBuilder graph_builder;


};

#endif // NFA_GENERATOR_H
