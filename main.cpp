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

using namespace std;

int main()
{/*
=======
{

    unordered_map<string , int> mymap;
    mymap.insert(pair<string,int>("a", 0));
    mymap.insert(pair<string,int>("b", 1));

    unordered_map<string,int>::const_iterator it = mymap.find("a");

    if( it == mymap.end()){
        cout<<"Not found" <<endl;
    }else{
        cout<<it->first<<endl;
        cout<< it->second <<endl;
    }

>>>>>>> 3f6e0359d629e663f883a44726396dfbcf73b552
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    /** Test Graph Builder **/
    TestSimpsonGraphBuilder test_builder;
    cout << "*******************************" << endl;
    cout << "Start of the test:" << endl;
    cout << "1) Init Graph:" << endl;
    cout << (test_builder.test_init_graph() ? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "2) OR Operation:" << endl;
    cout << (test_builder.test_or_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

string str("Hello, can you find Ben?");
string::size_type position = str.find("Ben");
cout << "First occurrence of Ben was found at: " << position << endl;
    // test
    cout << "Hello world!" << endl;

    cout << "3) AND Operation:" << endl;
    cout << (test_builder.test_and_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "4) Clousure Operation:" << endl;
    cout << (test_builder.test_clousure_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    cout << "5) Positive Clousure Operation:" << endl;
    cout << (test_builder.test_positive_clousure_op()? "Passed" : "Failed")<< endl;
    cout << "-------------------------------" << endl;

    /** Test Read File **/
    NFA_Generator gen("grammarInput.txt");
    Graph *g = gen.getAutomata();
    cout<<g->get_graph_size() << endl;
    if( g->get_graph_size() == 22)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
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
    *   ***************** TEST PostFiXConversion **********************
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
