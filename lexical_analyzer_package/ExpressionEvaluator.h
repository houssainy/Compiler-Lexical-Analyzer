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
<<<<<<< HEAD
        ExpressionEvaluator();
        Graph *evaluate(string expr /*, hash map*/);
=======
         ExpressionEvaluator();
         string post_fix_conversion(string exp);
        Graph *evaluate(string expr ,unordered_map <string,Graph*> graphs);
        bool is_operand(string type);
>>>>>>> 97fc01ae400ed38d849c4cdf8e1d620b09d7f37d
        virtual ~ExpressionEvaluator();
    protected:
    private:
        SimpsonGraphBuilder *builder;

        stack <string> operand;
        stack <string> operation;

};

#endif // EXPRESSIONEVALUATOR_H

