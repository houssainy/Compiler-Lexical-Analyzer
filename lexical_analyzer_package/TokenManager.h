#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "Automata.h"
#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"
#include <fstream>
#include <list>

enum  cToken{Ident, Keyword, Number,Unkown, Punctuation, Operat} ;
class TokenManager
{
    public:
        cToken currentToken;
        ofstream outputFile;
        vector<char> seq ;
        Node* Ptr;
        Graph graph;
        void writeToOutput(vector<char> seq, cToken c);
        void GenToken(char str);
        TokenManager();
        virtual ~TokenManager();
    protected:
    private:
};

#endif // TOKENMANAGER_H
