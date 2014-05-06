#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "Automata.h"
#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"
#include <fstream>
#include <list>
#include <string>
#define TOKENMANAGER_H
#include "TransitionTable.h"

using namespace std;

class TokenManager
{
    public:
/**<<<<<<< HEAD
        bool isToken ;
        ofstream outputFile;
        ofstream errorFile ;
        vector<char> seq;
        void init();
        void write_to_file(ofstream file , vector<char> seq, string type);
        void GenToken(string str);
        TokenManager();
        vector< string > seq ;
=======*/
        TokenManager(TransitionTable *transTable);
        vector<char> seq ;
//>>>>>>> 781d444f1ddcd7e6f46b902bb19e9b5482282cc3
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
