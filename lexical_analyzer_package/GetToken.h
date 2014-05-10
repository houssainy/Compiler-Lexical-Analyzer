#ifndef GETTOKEN_H
#define GETTOKEN_H
#include <stack>
#include "TransitionTable.h"
#include <vector>
#include <fstream>
#include <string.h>


struct State { int state; char input; };

#include <iostream>

using namespace std;
class GetToken
{
    public:
        GetToken(TransitionTable *transTable);
        GetToken(){};
        string getToken();

        virtual ~GetToken();

    private:
        vector<State> read_input;
        ifstream inputFile ;
        ofstream outputFile;
        ofstream errorFile ;
        ofstream symbolFile ;
        stack<State> temp_state;

        char read_next_char();
        vector< vector<int> > transition_table;
        TransitionTable *transTable;

        int current_node;



};

#endif // GETTOKEN_H
