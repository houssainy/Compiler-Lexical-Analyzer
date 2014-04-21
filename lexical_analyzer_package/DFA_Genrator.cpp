#include "DFA_Genrator.h"

#include <DFA_State.h>


DFA_Genrator::DFA_Genrator(vector < vector < int > > NFA , vector < vector <int > > eClouser,vector <string> input,vector<bool> finalState)
{
    //ctor
    int size = NFA.size ();

    if (size == -1)
        return;

    int counter =0 ;
    int stateindex=0;

    vector <DFA_State> newStates ;
    DFA_State startState = DFA_State (size,stateindex);
    startState.set_state(0,finalState[0]);
    for(int i =0 ; i<eClouser[0].size();i++){
        int state = eClouser[0].at(i);
        startState.set_state(state,finalState[state]);
    }

}
vector < vector < DFA_State > > DFA_Genrator::Get_DFA ()
{
    return DFA;
}

DFA_Genrator::~DFA_Genrator()
{
    //dtor
}
