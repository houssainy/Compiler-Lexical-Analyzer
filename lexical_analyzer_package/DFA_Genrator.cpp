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

    DFA_State startState = DFA_State (size,stateindex);
    // Add start node to DFA_State
    startState.set_state(0,finalState[0]);
    // Add EClouser of first State to DFA_State
    for(int i =0 ; i<eClouser[0].size() ; i++)
    {
        int state = eClouser[0].at(i);
        startState.set_state(state,finalState[state]);
    }
    stateindex++;
    // Add start Node to newStates Vector
    newStates.push_back(startState);
    // Start while loop to add all new states

    while (counter < newStates.size())
    {
        int finished_states = 0;
        vector <DFA_State> row ;
        DFA_State currentState = newStates.at(counter);
        vector <int> currentStateNumber = currentState.get_States_Number();
        for (int i =0 ; i<input.size(); i++)
        {
            DFA_State element = DFA_State (size,stateindex);
            if (currentStateNumber.size()>finished_states)
            {
                for (int j =0 ; j<currentStateNumber.size(); j++)
                {
                    int tempState =  currentStateNumber[j];
                    if (NFA[tempState].at(0)!=-1 && NFA[tempState].at(1)==i+1)
                    {
                        finished_states ++ ;
                        element.set_state(NFA[tempState].at(0),finalState[tempState]);
                        for(int k =0 ; k<eClouser[NFA[tempState].at(0)].size() ; k++)
                        {
                            int state = eClouser[NFA[tempState].at(0)].at(k);
                            element.set_state(state,finalState[state]);
                        }
                    }

                }
                if (!element.is_Empty())
                    if (!Compare(element))
                    {
                        newStates.push_back(element);
                        stateindex ++ ;
                    }
                else {
                    element.set_state_number(-1);
                }
            }
            row.push_back (element);



        }
        counter ++;
        int x = DFA.size ();
        int y= newStates.size();
        DFA.push_back(row);

    }
}


vector < vector < DFA_State > > DFA_Genrator::Get_DFA ()
{

    return DFA;
}

bool DFA_Genrator::Compare (DFA_State state )
{
    vector <bool> bitmask = state.get_state();
    for (int i =0 ; i<newStates.size(); i++)
    {
        vector <bool> tempbitmask = newStates[i].get_state();
        if (bitmask==tempbitmask)
            return true;
    }
    return false;
}

DFA_Genrator::~DFA_Genrator()
{
    //dtor
}
