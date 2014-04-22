#include "DFA_Minimization.h"

DFA_Minimization::DFA_Minimization(vector < vector < DFA_State > > DFA ,vector < DFA_State > newStates)
{
    //ctor
    /**
      *  Add finite state and nonfinite state in MDFA Vector
      */
    set finite ;
    set nonfinite ;

    for (int i =0 ; i<newStates.size () ; i++)
    {
        if (newStates[i].is_final())
            finite.states.push_back(newStates[i].get_state_number());
        else
            nonfinite.states.push_back(newStates[i].get_state_number());
    }
    MSets.push_back (finite);
    MSets.push_back (nonfinite);
    //set isChanged with true to make loop start
    isChanged = true;
    /**
      *loop at MSets and split sets unitl no change can happen
      */

    while (isChanged){
        //convert isChanged to false to detect if there new change in MSets or not
        isChanged= false ;
        vector < set > tempVector ;




    }


}

DFA_Minimization::~DFA_Minimization()
{
    //dtor
}
