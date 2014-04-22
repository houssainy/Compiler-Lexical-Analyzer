#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H
#include <stack>
#include "SimpsonGraphBuilder.h"
#include "../graph_package/Graph.h"
#include <unordered_map>
#include <iostream>

using namespace std;
class ExpressionEvaluator
{
    public:
        ExpressionEvaluator(SimpsonGraphBuilder* builder);
         ExpressionEvaluator();
         string post_fix_conversion(string exp);
        Graph *evaluate(string expr ,unordered_map <string,Graph*> graphs);
        bool is_operand(string type);
        virtual ~ExpressionEvaluator();
    protected:
    private:
        SimpsonGraphBuilder *builder;

        stack <string> operand;
        stack <string> operation;

};

#endif // EXPRESSIONEVALUATOR_H
