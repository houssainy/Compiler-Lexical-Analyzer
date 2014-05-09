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

        DFA_Genrator(Graph * NFA , unordered_map<char,int> input_map);
        vector < vector < DFA_State > > Get_DFA ();
        vector < DFA_State> Get_New_States ();
        vector<string> get_token_type();
        virtual ~DFA_Genrator();

    protected:

    private:
        int Compare (DFA_State state );
        void init(Graph * NFA , unordered_map<char,int> input_map);
        void Generate (vector < vector < int > > nfa , vector < vector <int > > eClouser,int numberOfInputs,vector<bool> finalState , vector<string> token_type);
        vector < vector < DFA_State > > DFA ;
        vector <DFA_State> newStates ;
        vector <string> new_token_type ;
};

#endif // DFA_GENRATOR_H
