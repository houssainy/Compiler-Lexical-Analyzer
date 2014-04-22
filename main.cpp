#include <iostream>

#include "test_package/TestSimpsonGraphBuilder.h"
#include <stack>
#include <fstream>
#include <string.h>
#include "lexical_analyzer_package/TokenManager.h"
#include "lexical_analyzer_package/ExpressionEvaluator.h"
#include "graph_package/Graph.h"
#include "graph_package/Node.h"


using namespace std;

int main()
{/*
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    TestSimpsonGraphBuilder test_builder;
    cout << "*******************************" << endl;
    cout << "Start of the test:" << endl;
    cout << "1) Init Graph:" << endl;
    cout << (test_builder.test_init_graph() ? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "2) OR Operation:" << endl;
    cout << (test_builder.test_or_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

//<<<<<<< HEAD
    //djkdk
string str("Hello, can you find Ben?");
string::size_type position = str.find("Ben");
cout << "First occurrence of Ben was found at: " << position << endl;
    // test
    cout << "Hello world!" << endl;
    //kkkkk
//=======
    cout << "3) AND Operation:" << endl;
    cout << (test_builder.test_and_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "4) Clousure Operation:" << endl;
    cout << (test_builder.test_clousure_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "5) Positive Clousure Operation:" << endl;
    cout << (test_builder.test_positive_clousure_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;
    /**
    *  ***************** END OF TEST  **********************
    */

    /**
    *   ***************** BUSHRA **********************
    **/
    char inputChar ;
    TokenManager token;
    ifstream inputFile ("p.txt");
    ofstream errorsFile;

    if(inputFile)
    {
        do
        {
            inputFile >> noskipws >> inputChar ;
            cout << inputChar;
            token.GenToken(inputChar);
        }while(! inputFile.eof());
        inputFile.close();
    }
    else
    {
        cout<< "Unable to open file";
    }
    /**
    *   ***************** END BUSHRA **********************
    **/


  /**
    *   ***************** YASMINA **********************
    **/

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
