#ifndef DFA_GENRATOR_H
#define DFA_GENRATOR_H

#include <vector>
#include <iostream>
#include <DFA_State.h>


using namespace std;

class DFA_Genrator
{
    public:

        DFA_Genrator(vector < vector < int > > nfa , vector < vector <int > > eClouser,vector <string> input,vector<bool> finalState);
        vector < vector < DFA_State > > Get_DFA ();

        virtual ~DFA_Genrator();

    protected:

    private:
        vector < vector < DFA_State > > DFA ;
};

#endif // DFA_GENRATOR_H
