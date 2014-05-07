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
#include "lexical_analyzer_package/DFA_Genrator.h"
#include "lexical_analyzer_package/DFA_State.h"

using namespace std;

int main()
{
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    /** Test Graph Builder **/
    TestSimpsonGraphBuilder test_builder;
    test_builder.start();
    /**
    *  ***************** END OF TEST  **********************
    */
//    /**
//    *   ***************** BUSHRA **********************
//    **/
//
// char inputChar ;
//    int returnState;
//    string token_type;
//    vector<char> tokenSeq;
//
////    TransitionTable t;
// //   TokenManager token;
////    char inputChar ;
////    int returnState;
////    string token_type;
////    vector<char> tokenSeq;
//    TransitionTable *t;
//    TokenManager *token;
//    ifstream inputFile ;
//    ofstream outputFile;
//    ofstream errorFile ;
//    vector< vector<char> > symbol_table;
//    inputFile.open("p.txt");
//    if(inputFile)
//    {
//        token = new TokenManager(t);
//        outputFile.open("output.txt");
//        if(!outputFile)
//            cout<< "Unable to open output file";
//        errorFile.open("errorFile.txt");
//        if(!errorFile)
//            cout<< "Unable to open error file";
//        do
//        {
//            inputFile >> noskipws >> inputChar;
//            returnState = token->GetNextState(inputChar);
//            if(token->is_Token)
//            {
//                token_type = t->type(token->seq[token->seq.size()]);
//                for (int i = 0 ; i < token->seq.size(); i++)
//                {
//                   outputFile << token->seq[i] ;
//                }
//                outputFile << "/t" << token_type << endl;
//
//                if(token_type == "Identifier")
//                    symbol_table.push_back(token->seq); /*test*/
//            }
//            if(token->isError)
//                errorFile << token->is_Error() << "/t" << returnState << endl;
//        } while(! inputFile.eof());
//        inputFile.close();
//        outputFile.close();
//        errorFile.close();
//    }
//    else
//    {
//        cout<< "Unable to open input file";
//    }
//    /**
//    *   ***************** END BUSHRA **********************
//    **/



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



    /**
     * DFA test
     */
    /**
     *-------------------------------------------
     *Test 1
     *-------------------------------------------
     */
    vector <vector <int> > nfa;
    vector <vector <int> > eclosure;
    vector <bool> finalStates ;
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
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    cout << nfa.size()<<endl;
//input to e-closure
    row.push_back(1);
    row.push_back(5);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(3);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(11);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(7);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(9);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(11);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    cout<< eclosure.size()<<endl;
//create final states vector
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(true);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(true);
    finalStates.push_back(false);
    cout<< finalStates.size() <<endl;
//this vector for test only
    vector < string > input;
    input.push_back("i");
    input.push_back("f");
    input.push_back("n");
    input.push_back("t");

    DFA_Genrator gene = DFA_Genrator (nfa , eclosure , input ,finalStates);
    vector < vector <DFA_State> > DFA = gene.Get_DFA();
    for (int i=0 ; i<DFA.size() ; i++)
    {
        for (int j=0; j<DFA[i].size() ; j++)
        {
            cout << DFA[i][j].get_state_number ()<<"\t" <<DFA[i][j].is_final () << endl;

        }

    }
    cout << "\n\n\n" <<"test 2" <<endl;
    /**
     *-------------------------------------------
     *Test 2
     *-------------------------------------------
     */
    nfa.clear();
    finalStates.clear();
    eclosure.clear();
// inout to NFA table
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
    row.push_back(2);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    row.push_back(10);
    row.push_back(3);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    row.push_back(12);
    row.push_back(4);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    row.push_back(14);
    row.push_back(5);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    row.push_back(16);
    row.push_back(6);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();
    row.push_back(-1);
    row.push_back(-1);
    nfa.push_back(row);
    row.clear();

    cout << nfa.size()<<endl;
//input to e-closure
    row.push_back(1);
    row.push_back(5);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(3);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(17);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(7);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(9);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(11);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(13);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(15);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    row.push_back(17);
    eclosure.push_back(row);
    row.clear();
    eclosure.push_back(row);
    row.clear();
    cout<< eclosure.size()<<endl;

//create final states vector
    finalStates.clear();
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(true);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(false);
    finalStates.push_back(true);
    finalStates.push_back(false);
    cout<< finalStates.size() <<endl;
//this vector for test only
    input.clear();
    input.push_back("d");
    input.push_back("o");
    input.push_back("u");
    input.push_back("b");
    input.push_back("l");
    input.push_back("e");


    gene = DFA_Genrator (nfa , eclosure , input ,finalStates);
    DFA = gene.Get_DFA();
    for (int i=0 ; i<DFA.size() ; i++)
    {
        for (int j=0; j<DFA[i].size() ; j++)
        {
            cout << DFA[i][j].get_state_number ()<<"\t" <<DFA[i][j].is_final () << endl;

        }

    }

    return 0;

};
