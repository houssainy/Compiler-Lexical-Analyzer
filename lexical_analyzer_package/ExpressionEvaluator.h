#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H


#include "SimpsonGraphBuilder.h"
#include "../graph_package/Graph.h"

#include <iostream>

using namespace std;
class ExpressionEvaluator
{
    public:
        ExpressionEvaluator(SimpsonGraphBuilder* builder);
        Graph *evaluate(string expr /*, hash map*/);
        virtual ~ExpressionEvaluator();
    protected:
    private:
        SimpsonGraphBuilder *builder;

};

#endif // EXPRESSIONEVALUATOR_H
