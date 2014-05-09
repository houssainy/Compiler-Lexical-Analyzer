#ifndef DFA_GENRATOR_H
#define DFA_GENRATOR_H

#include <vector>
#include <iostream>
#include <DFA_State.h>


using namespace std;

class DFA_Genrator
{
    public:

        DFA_Genrator(vector < vector < int > > nfa , vector < vector <int > > eClouser,int numberOfInputs,vector<bool> finalState);
        vector < vector < DFA_State > > Get_DFA ();
        vector < DFA_State> Get_New_States ();
        virtual ~DFA_Genrator();

    protected:

    private:
        int Compare (DFA_State state );
        vector < vector < DFA_State > > DFA ;
        vector <DFA_State> newStates ;
};

#endif // DFA_GENRATOR_H
