#include <stack>
#include <fstream>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include "TransitionTable.h"
#include "Lexical_Analyzer.h"
#include "graph_package/Node.h"
#include "graph_package/Graph.h"
#include "test_package/DFATest.h"
#include "lexical_analyzer_package/DFA_State.h"
#include "test_package/TestSimpsonGraphBuilder.h"
#include "lexical_analyzer_package/TokenManager.h"
#include "lexical_analyzer_package/DFA_Genrator.h"
#include "lexical_analyzer_package/NFA_Generator.h"
#include "lexical_analyzer_package/DFA_Minimization.h"
#include "lexical_analyzer_package/ExpressionEvaluator.h"


using namespace std;

int main(int arg , char* args[])
{
    /**************************** Main Code*******************************/
    Lexical_Analyzer lx("grammarInput.txt");

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

        /******************* END OF AHMED TEST  ******************/

        /****************** LEXIACL ANALYSIS OUTPUT  *************
                            BUSHRA */

    /* **************************************************/
    cout<< endl<< endl<<"--------------*-----------* Bushra Test *-----------*----------*" <<endl ;
    vector< vector<char> > symbol_table;
    ifstream inputFile ;
    ofstream outputFile;
    ofstream errorFile ;

    /* ***** For Test ******/
    vector<string> Type;
    vector < vector <int> > MDFA ;
    vector <bool> finals ;
    unordered_map <char,int> in ;
    in.insert(make_pair('d',0));
    in.insert(make_pair('o',1));
    in.insert(make_pair('u',2));
    in.insert(make_pair('b',3));
    in.insert(make_pair('l',4));
    in.insert(make_pair('e',5));
    /* ***********/
    TokenManager *token;
   //  TransitionTable *t ;
//    TransitionTable *t =new TransitionTable(MDFA, in , finals,Type);
    token = new TokenManager();
    token->printTransitionTable();

    char inputChar = ' ' ;
    int returnState;
    string token_type;
    /* **************************************************/
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
            if(token->tempState != -1)
               {
                    inputFile >> noskipws >> inputChar;
                    cout << endl<< "Input Read: " ;
                    cout << inputChar<<endl << endl;;
               }
//                    if(token->tempState == -1)
//                    returnState = token->GetNextState(inputChar);
            if(inputFile.eof())
            {
                token->transTableIndex = 0;
                returnState = token->GetNextState('\0');
            }
            else
            {
                if (inputChar == 'a')
                    token->transTableIndex = 0;
                else if (inputChar == 'b') token->transTableIndex = 1;
                else token->transTableIndex = -1;
                returnState = token->GetNextState(inputChar);
            }

            if(token->is_Token)
            {
                //token_type = t->type(token->states[token->states.size()]);

                token_type = "Identifier";

                if(token_type == "Identifier")
                {
                    outputFile << /*token_type*/ "id" << endl;
                    symbol_table.push_back(token->seq);

                }
                if(token_type == "operator")
                {
                    for (int i = 0 ; i < token->seq.size(); i++)
                    {
                          outputFile << token->seq[i] ;
                    }
                }
                if(token_type == "punc")
                    outputFile << "\t" << token->seq[0] << endl;
                if(token_type == "digit")
                {
                    for (int i = 0 ; i < token->seq.size(); i++)
                    {
                          outputFile << token->seq[i] ;
                    }
                }
                if(token_type == "keyword")
                {
                    for (int i = 0 ; i < token->seq.size(); i++)
                    {
                        outputFile << token->seq[i] ;
                    }
                }
//                int newSize = token->Character.size() - token->seq.size() ;
//                if(newSize != 0)
//                {
//                    for (int i = newSize ; i < token->Character.size() ; i ++)
//                        token->seq.insert(token->seq.begin(),token->Character[i]);
//                    returnState = token->GetNextState(token->seq.front());
//                }

            }
            if(token->isError)
            {
                for(int i = 0 ; i < token->discardChar.size(); i++)
                    errorFile << token->discardChar[i] << endl;
                token->isError = false;
            }
        }
        inputFile.close();
        outputFile.close();
        errorFile.close();

        cout << endl << endl<<" -------* Symbols Table *-------- " << endl;
        for(int i = 0; i < symbol_table.size(); ++i)
        {
                        for(int j = 0; j < symbol_table[i].size(); ++j)
                            cout << symbol_table[i][j];

                        cout << endl;
        }
        cout << "---------------------------------" << endl;

        cout << endl << " -------* States Path *-------- "<<endl;
        for(int i = 0; i < token->states.size(); ++i)
        {
            cout << token->states[i]<<endl;
            cout << endl;
        }
        cout << " --------------------------------- " << endl;

    }
    else
    {
        cout<< "Unable to open input file";
    }
        /******************* END OF BUSHRA TEST  ***********************/

    /***************************** END OF TEST **********************************/
    return 0;

};

