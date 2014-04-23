#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include "Automata.h"
#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"
#include <fstream>
#include <list>

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
        virtual ~TokenManager();
    protected:
    private:
};

#endif // TOKENMANAGER_H
