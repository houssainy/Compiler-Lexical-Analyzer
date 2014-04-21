#include "DFA_State.h"


//Constructor
DFA_State::DFA_State(int size , int Number)
{
    //ctor
    this->isFinal=isFinal;
    for (int i =0; i<size; i++)
        this->states.push_back(false);
    this->Number=Number;
    this->isEmpty = true;
}

void DFA_State::set_state (int stateNumber,bool isFinal)
{
    isEmpty = false;
    if (!this->isFinal)
        this->isFinal = isFinal;
    states.at(stateNumber) = true;
}

vector<bool> DFA_State::get_state ()
{
    return states;
}

bool DFA_State::is_final ()
{
    return isFinal;
}

int DFA_State::get_state_number ()
{
    return Number;
}

DFA_State::~DFA_State()
{
    //dtor
}
