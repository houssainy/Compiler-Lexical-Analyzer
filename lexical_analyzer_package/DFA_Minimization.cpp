#include "DFA_Minimization.h"

DFA_Minimization::DFA_Minimization(vector < vector < DFA_State > > DFA ,vector < DFA_State > newStates)
{
    //ctor
    this->initialStates = newStates.size();

    /**
      *  Add finite state and nonfinite state in MDFA Vector
      */

    statesSet finite = creat_set();
    statesSet nonfinite =creat_set();


    for (int i =0 ; i<newStates.size () ; i++)
    {
        int stateNumber = newStates[i].get_state_number();
        if (newStates[i].is_final())
        {
            finite.states.push_back(stateNumber);
        }
        else
        {
            nonfinite.states.push_back(stateNumber);
        }
    }
    MSets.push_back (finite);
    MSets.push_back (nonfinite);
    //set isChanged with true to make loop start
    isChanged = true;
    /**
      *loop at MSets and split sets unitl no change can happen
      */

    while (isChanged)
    {
        //convert isChanged to false to detect if there new change in MSets or not
        isChanged= false ;
        for (int i =0 ; i<MSets.size(); i++)
        {
            vector < statesSet > tempVector ;
            statesSet currentSet = MSets[i];

        }


    }


}

/**statesSet DFA_Minimization::creat_set(){
    statesSet states;
    for(int i=0 ; i<initialStates; i++){
        states.mask.push_back(false);
    }
    return states;
}*/
DFA_Minimization::~DFA_Minimization()
{
    //dtor
}
