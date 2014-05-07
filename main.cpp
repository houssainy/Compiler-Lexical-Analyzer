#include <iostream>

#include "test_package/TestSimpsonGraphBuilder.h"
#include <stack>
#include <fstream>
#include <string.h>
#include "lexical_analyzer_package/TokenManager.h"
#include "lexical_analyzer_package/ExpressionEvaluator.h"
#include "graph_package/Graph.h"
#include "graph_package/Node.h"
#include "lexical_analyzer_package/NFA_Generator.h"
#include "TransitionTable.h"

using namespace std;

int main()
{
    cout<<"hell"<<endl;
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    /** Test Graph Builder **/


    ExpressionEvaluator expressionEvaluator;

    string exp;



    exp=expressionEvaluator.post_fix_conversion("A.B|C*");
    cout <<"PostFixNotation of this Expression (A.B|C*) is "<< exp << endl;
    cout << "--------------------------------------------------------" << endl;

    exp=expressionEvaluator.post_fix_conversion("A.(B|C*|A*).B*");
    cout <<"PostFixNotation of this Expression (A.(B|C*|A*).B*) is "<< exp << endl;
    cout << "--------------------------------------------------------" << endl;

    exp=expressionEvaluator.post_fix_conversion("A.(B|C)");
    cout <<"PostFixNotation of this Expression (A.(B|C) is "<< exp <<  endl;
    cout << "--------------------------------------------------------" << endl;

    exp=expressionEvaluator.post_fix_conversion("A.(B|C)|A|C*.(A*.S*)");
    cout <<"PostFixNotation of this Expression (A.(B|C)|A|C*.(A*.S*)) is "<< exp << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;

};
