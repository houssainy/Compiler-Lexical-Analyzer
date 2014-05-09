#include <iostream>

#include "test_package/TestSimpsonGraphBuilder.h"
#include "test_package/DFATest.h"
#include <stack>
#include <fstream>
#include <string.h>
#include "lexical_analyzer_package/TokenManager.h"
#include "lexical_analyzer_package/ExpressionEvaluator.h"
#include "graph_package/Graph.h"
#include "graph_package/Node.h"
#include "lexical_analyzer_package/NFA_Generator.h"
#include "TransitionTable.h"
#include "Lexical_Analyzer.h"

using namespace std;

int main(int arg , char* args[])
{
    /**************************** Main Code*******************************/
//    Lexical_Analyzer lx("grammarInput.txt");

    /****************************END OF MAIN ****************************/


    /*****************************TEST **********************************/
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    /** Test Graph Builder **/
    TestSimpsonGraphBuilder test_builder;
    test_builder.start();
    /**
    *  ***************** END HOUSSAINY'S TEST  **********************
    */
    /**
    *   ***************** BUSHRA **********************
    **/
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
    /**
    *   ***************** END BUSHRA **********************
    **/



    /**
    *   ***************** TEST PostFiXConversion **********************
    **/


//    ExpressionEvaluator expressionEvaluator;
//
//    string exp;
//
//
//
//    exp=expressionEvaluator.post_fix_conversion("A.B|C*");
//    cout <<"PostFixNotation of this Expression (A.B|C*) is "<< exp << endl;
//    cout << "--------------------------------------------------------" << endl;
//
//    exp=expressionEvaluator.post_fix_conversion("A.(B|C*|A*).B*");
//    cout <<"PostFixNotation of this Expression (A.(B|C*|A*).B*) is "<< exp << endl;
//    cout << "--------------------------------------------------------" << endl;
//
//    exp=expressionEvaluator.post_fix_conversion("A.(B|C)");
//    cout <<"PostFixNotation of this Expression (A.(B|C) is "<< exp <<  endl;
//    cout << "--------------------------------------------------------" << endl;
//
//    exp=expressionEvaluator.post_fix_conversion("A.(B|C)|A|C*.(A*.S*)");
//    cout <<"PostFixNotation of this Expression (A.(B|C)|A|C*.(A*.S*)) is "<< exp << endl;
//    cout << "-------------------------------------------------------" << endl;

    /************************* END POST FIX TEST *******************************/

    /**************************** DFA TEST *************************************/
    DFATest DFAtest = DFATest ();
    /************************* END DFA TEST *******************************/

    return 0;

};
