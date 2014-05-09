#ifndef DFA_GENRATOR_H
#define DFA_GENRATOR_H

#include <vector>
#include <iostream>
#include <DFA_State.h>
#include <unordered_map>
#include "../graph_package/Graph.h"
#include "../graph_package/Node.h"
#include "../graph_package/Edge.h"


using namespace std;

class DFA_Genrator
{
    public:

        DFA_Genrator(Graph * NFA , int input_size);
        vector < vector < DFA_State > > Get_DFA ();
        vector < DFA_State> Get_New_States ();
        virtual ~DFA_Genrator();

    protected:

    private:
        int Compare (DFA_State state );
        void init(Graph * NFA , int input_size);
        void Generate (vector < vector < int > > nfa , vector < vector <int > > eClouser,int numberOfInputs,vector<bool> finalState);
        vector < vector < DFA_State > > DFA ;
        vector <DFA_State> newStates ;
};

#endif // DFA_GENRATOR_H
