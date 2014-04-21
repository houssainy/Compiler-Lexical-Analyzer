#include "TransitionTable.h"


TransitionTable::TransitionTable( vector < vector <int> > MDFA ,
                                  unordered_map <string,int> input,
                                  vector <bool> finalState ,
                                  vector <string> tokenType )
{
    //ctor
    this->MDFA = MDFA;
    this->input_map = input;
    this->finalState = finalState;
    this->tokenType = tokenType;
}
vector < vector <int> > TransitionTable::Get_MDFA ()
{
    return MDFA;
}

int TransitionTable::Get_Input (string input)
{
    unordered_map<string,int>::const_iterator it =input_map.find(input);

    if (it!=input_map.end())
    {
        return it->second;
    }
    return -1;
}

bool TransitionTable::is_final (int state )
{
    if (state < finalState.size())
        return finalState[state];
    return -1;
}

string TransitionTable::type (int state )
{
    if (state < tokenType.size())
        return tokenType[state];
    return NULL;
}

TransitionTable::~TransitionTable()
{
    //dtor
}
