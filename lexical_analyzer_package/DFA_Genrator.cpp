#include "DFA_Genrator.h"


DFA_Genrator::DFA_Genrator(vector < vector < int > > nfa , vector < vector <int > > eClouser,vector <string> input,vector<bool> finalState)
{
    //ctor

}
vector < vector < DFA_State > > DFA_Genrator::Get_DFA (){
    return DFA;
}

DFA_Genrator::~DFA_Genrator()
{
    //dtor
}
