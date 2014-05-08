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
#include "TestTokenManager.h"

using namespace std;

int main()
{
    /**
    *  ***************** Simposn't Test  **********************
    *                       Houssainy
    */
    /** Test Graph Builder **/
   // TestSimpsonGraphBuilder test_builder;
   // test_builder.start();
    /**
    *  ***************** END OF TEST  **********************
    */

    /**
    *   ***************** BUSHRA **********************
    **/

    vector< vector<char> > symbol_table;
    ifstream inputFile ;
    ofstream outputFile;
    ofstream errorFile ;

    TestTokenManager test_builder;
    test_builder.start();

    TokenManager *token;
    TransitionTable *t;
    token = new TokenManager(t);
    token->printTransitionTable();

    char inputChar = ' ' ;
    int returnState;
    string token_type;

    inputFile.open("inputFile.txt");
    if(inputFile)
    {
        outputFile.open("outputFile.txt");
        if(!outputFile)
            cout<< "Unable to open output file";
        errorFile.open("errorFile.txt");
        if(!errorFile)
            cout<< "Unable to open error file";
         while (! inputFile.eof())
        {
            inputFile >> noskipws >> inputChar;
            if(inputFile.eof())
            {
                token->transTableIndex = 0;
                returnState = token->GetNextState('\0');
            }
            else
            {
                cout << inputChar<<endl;
//                if (inputChar == 'a') token->transTableIndex = 1;
//                else if (inputChar == 'b') token->transTableIndex = 2;
//                else token->transTableIndex = -1;
                returnState = token->GetNextState(inputChar);
            }

            if(token->is_Token)
            {
                token_type = t->type(token->states[token->states.size()]);
                token_type = "Identifier";
                cout << "********Symbol Table********" << endl;
                if(token_type == "Identifier")
                {
                    outputFile << /*token_type*/ "id" << endl;
                    symbol_table.push_back(token->seq);
                    for(int i = 0; i < symbol_table.size(); ++i)
                    {
                        for(int j = 0; j < symbol_table[i].size(); ++j)
                            cout << symbol_table[i][j];

                        cout << endl;
                    }
                }

                if(token_type == "operator")
                    outputFile << "\t" << token->seq[0] << endl;

                if(token_type == "punc")
                    outputFile << "\t" << token->seq[0] << endl;

                if(token_type == "digit")
                       outputFile << "\t" << token->seq[0] << endl;

                if(token_type == "keyword")
                {
                    for (int i = 0 ; i < token->seq.size(); i++)
                    {
                        outputFile << token->seq[i] ;
                    }
                }
            }
            if(token->isError)
            {
                errorFile << token->is_Error() << endl;
                token->isError = false;
            }
        }
        inputFile.close();
        outputFile.close();
        errorFile.close();

        cout << endl << "************************************" << endl;
        cout << "States path"<<endl;
        for(int i = 0; i < token->states.size(); ++i)
        {
            cout << token->states[i]<<endl;
            cout << endl;
        }

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
//
//    ExpressionEvaluator expressionEvaluator;
//
//    string exp;
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

    return 0;

};
