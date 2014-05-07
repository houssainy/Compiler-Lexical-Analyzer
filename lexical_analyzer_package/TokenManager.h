#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "TransitionTable.h"

class TokenManager
{
    public:
        TokenManager(TransitionTable *transTable);
        vector<char> seq ;
        bool isError ;
        char discardChar ;
        bool is_Token;
        char is_Error();
        int GetNextState(char str);
        bool isToken(int state);
        virtual ~TokenManager();
    protected:
    private:
        vector< vector<int> > transition_table;
        TransitionTable *transTable;
        vector<char> store ;
        vector<int> states;
        int startNode;
        int tempState;
        int NextTempState ;
        int transTableIndex;

        string type;
};

#endif // TOKENMANAGER_H
