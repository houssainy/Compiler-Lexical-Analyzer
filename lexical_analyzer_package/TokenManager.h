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
#include <vector>

using namespace std;

class TokenManager
{
    public:
        bool isToken ;
        ofstream outputFile;
        ofstream errorFile ;
        vector<char> seq;
        void init();
        void write_to_file(ofstream file , vector<char> seq, string type);
        void GenToken(string str);
        TokenManager();
        bool isError ;
        int GetNextState(string str);
        void isToken(int state);
        virtual ~TokenManager();

    protected:
    private:
        vector< vector<int> > transition_table;
        TransitionTable transTable;
        vector<string> store ;
        int startNode;
        int tempState;
        int transTableIndex;
        bool is_Token;
        string type;
};

#endif // TOKENMANAGER_H
