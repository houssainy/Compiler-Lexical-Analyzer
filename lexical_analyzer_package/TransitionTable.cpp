#include "TransitionTable.h"

#include <iostream>
TransitionTable::TransitionTable( vector < vector <int> > MDFA ,
                                  unordered_map <char,int> input,
                                  vector <bool> finalState ,
                                  vector<string> tokenType )
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

int TransitionTable::Get_Input (char input)
{
    if( input_map.find(input) == input_map.end())
        return -1;
    return input_map[input];
}

bool TransitionTable::is_final (int state )
{
    if (state < finalState.size())
        return finalState[state];
    return false;
}

string TransitionTable::type (int state )
{
    if (state < tokenType.size())
        return tokenType[state];
    return "";
}

TransitionTable::~TransitionTable()
{
    //dtor
}
