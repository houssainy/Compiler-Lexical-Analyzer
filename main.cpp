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
<<<<<<< HEAD
    string inputChar ;
    TokenManager token;
    ifstream inputFile ("p.txt");
=======
 char inputChar ;
    int returnState;
    string token_type;
    vector<char> tokenSeq;
>>>>>>> 757bf898fda5166e834537d94aac119f532f3dd4

    TransitionTable t;
    TokenManager token;
    ifstream inputFile ;
    ofstream outputFile, errorFile;
    vector<string> symbol_table;
    inputFile.open("p.txt");
    if(inputFile)
    {
        token.TokenManager();
        outputFile.open("output.txt");
        if(!outputFile)
            cout<< "Unable to open output file";
        errorsFile.open("errorFile.txt");
        if(!errorFile)
            cout<< "Unable to open error file";
        do
        {
            inputFile >> noskipws >> inputChar;
            returnState = token.GetNextState(inputChar);
            if(token.isToken)
            {
                token_type = t.type(token.seq[seq.size()]);
                for (int i = 0 ; i < token.seq.size(); i++)
                {
                   outputFile << token.seq[i] ;
                }
                outputFile << "/t" << token_type << endl;

                if(token_type == "Identifier")
                    symbol_table.push_back(seq); /*test*/
            }
            if(token.isError)
                errorsFile << inputChar << "/t" << returnState << endl;
        } while(! inputFile.eof());
        inputFile.close();
        outputFile.close();
        errorFile.close();
    }
    else
    {
        cout<< "Unable to open input file";
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


/**
 * DFA test
*/
vector <vector <int> > nfa;
vector <vector <int> > eclosure;
// inout to NFA table
vector <int> row;
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(2);
row.push_back(1);
nfa.push_back(row);
row.clear();
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(4);
row.push_back(2);
nfa.push_back(row);
row.clear();
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(6);
row.push_back(1);
nfa.push_back(row);
row.clear();
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(8);
row.push_back(3);
nfa.push_back(row);
row.clear();
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(10);
row.push_back(4);
nfa.push_back(row);
row.clear();
row.push_back(-1);
row.push_back(-1);
nfa.push_back(row);
row.clear();
row.push_back(-1);
nfa.push_back(row);
row.push_back(-1);
//input to e-closure


};
