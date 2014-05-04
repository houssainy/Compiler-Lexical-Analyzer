#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "TransitionTable.h"

class TokenManager
{
    public:
        TokenManager(TransitionTable *transTable);
        vector<char> seq ;
        bool isError ;
//        int GetNextState(char str);
//        bool isToken(int state);
        virtual ~TokenManager();

    protected:
    private:
        vector< vector<int> > transition_table;
        TransitionTable *transTable;
        vector<string> store ;
        int startNode;
        int tempState;
        int transTableIndex;
        bool is_Token;
        string type;
};

#endif // TOKENMANAGER_H
