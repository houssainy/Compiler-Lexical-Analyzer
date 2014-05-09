#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include "TokenManager.h"
#include <iostream>

using namespace std;
class Lexical_Analyzer
{
    public:
        Lexical_Analyzer(string file_path);
        string next_token();
        virtual ~Lexical_Analyzer();
    protected:
    private:
        TokenManager token_man;
        void init_transition_table(string file_path);
};

#endif // LEXICAL_ANALYZER_H
