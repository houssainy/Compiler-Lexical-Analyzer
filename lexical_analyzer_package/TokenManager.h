#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include <fstream>
#include "TransitionTable.h"
#include "../test_package/TestTokenManager.h"

struct Token{string type; vector<char> token; };
class TokenManager
{
    public:
        TokenManager(TransitionTable *transTable);
        TokenManager(){};

        string getToken();
        virtual ~TokenManager();

    private:
        vector< Token > symbol_table;
        ifstream inputFile ;
        ofstream outputFile;
        ofstream errorFile ;
        char inputChar =' ';
        bool openFile = true;

        int transTableIndex;
        int tempState;
        int startNode;

        bool is_Token;
        bool isToken(int state);
        vector<bool> is_Final;
        bool isError ;
        vector<char> is_Error();
        vector<char> discardChar ;

        string type;
        vector<char> store ;
        vector<char> seq ;
        vector<int> states;
        vector<int> Character;
        int GetNextState(char str);
        vector< vector<int> > transition_table;
        TransitionTable *transTable;
};

#endif // TOKENMANAGER_H
