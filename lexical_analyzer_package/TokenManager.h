#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "TransitionTable.h"
#include "TestTokenManager.h"

class TokenManager
{
    public:

        void printTransitionTable();
        int transTableIndex;
        int tempState;
        TokenManager(TransitionTable *transTable);
        TestTokenManager test;
        vector<char> seq ;
        vector<int> states;
        bool isError ;
        char discardChar ;
        bool is_Token;
        int startNode;
        char is_Error();
        int GetNextState(char str);
          vector< vector<int> > transition_table;
        bool isToken(int state);
        virtual ~TokenManager();
    protected:
    private:

        TransitionTable *transTable;
        vector<char> store ;


        ;
        int NextTempState ;


        string type;
};

#endif // TOKENMANAGER_H
