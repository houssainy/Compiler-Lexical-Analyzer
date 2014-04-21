#include "TransitionTable.h"

TransitionTable::TransitionTable( vector < vector <int> > MDFA ,
                                  vector <string> input,
                                  vector <bool> finalState ,
                                  vector <string> tokenType )
{
        //ctor
        this->MDFA = MDFA;
        this->input = input;
        this->finalState = finalState;
        this->tokenType = tokenType;
}
vector < vector <int> > TransitionTable::Get_MDFA ()
{
    return MDFA;
}

vector < string > TransitionTable::Get_Input () {
    return input;
}

bool TransitionTable::is_final (int state ) {
    return finalState[state];
}

string TransitionTable::type (int state ) {
    return tokenType[state];
}

TransitionTable::~TransitionTable()
{
    //dtor
}
