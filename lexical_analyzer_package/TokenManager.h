#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "TransitionTable.h"
#include "../test_package/TestTokenManager.h"

class TokenManager
{
    public:

        vector<bool> is_Final;
        TokenManager(){};
        TokenManager(/*TransitionTable *transTable*/);
        TestTokenManager test;
        void printTransitionTable();
        int transTableIndex;
        int tempState;
        vector<char> seq ;
        vector<char> Character;
        vector<int> states;
        bool isError ;
        vector<char> discardChar ;
        bool is_Token;
        int startNode;
        vector<char> is_Error();
        int GetNextState(char str);
        vector< vector<int> > transition_table;
        bool isToken(int state);
        virtual ~TokenManager();
    private:

        TransitionTable *transTable;
        vector<char> store ;
        string type;
};

#endif // TOKENMANAGER_H
