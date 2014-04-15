#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "../graph_package/Graph.h"
class Automata
{
    public:
        Automata();
        virtual Graph* getAutomata() = 0;
        virtual ~Automata();
    protected:
    private:
        Graph graph;

};

#endif // AUTOMATA_H
