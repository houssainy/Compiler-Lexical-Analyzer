#include "DFA_Minimization.h"


DFA_Minimization::DFA_Minimization(vector < vector < DFA_State > > DFA )
{
    //ctor
    this ->DFA_Copy = DFA;

}

vector< vector <int> > DFA_Minimization:: minimize (vector < DFA_State > newStates)
{   vector < vector <DFA_State> > sets ;
    // add final and not final to sets vector
    vector <DFA_State> acceptance ;
    vector <DFA_State> nonacceptance;
    map <int, int> stateSet;
    int counter = 2;

    for (int i =0 ; i< newStates.size();i++)
    {
        if (newStates[i].is_final())
        {
            acceptance.push_back(newStates[i]);
            stateSet.insert(pair<char,int>(newStates[i].get_state_number(), 0));
        }else
        {
            nonacceptance.push_back(newStates[i]);
            stateSet.insert(pair<char,int>(newStates[i].get_state_number(), 1));
        }
    }

    sets.push_back(acceptance);
    sets.push_back(nonacceptance);

    bool f = true;

    while(f)
    {
        f = false;
        int setCount = sets.size();
        for(int i = 0 ; i < setCount ; i++)
        {
            for(int j = 0 ; j < sets[i].size() ; j++)
            {
                vector <DFA_State> cur;
                cur.push_back(sets[0][j]);
                stateSet[j] = counter;

                for(int k = j+1 ; k < sets[0].size() ; k++)
                {
                    for(int l = 0 ; l < DFA_Copy[0].size() ; l++)
                    {
                        if(stateSet[DFA_Copy[j][l].get_state_number()] == stateSet[DFA_Copy[k][l].get_state_number()])
                        {
                            cur.push_back(sets[0][k]);
                            sets[0].erase(sets[0].begin() + k);
                            k--;
                            stateSet[k] = counter;
                        }else
                        {
                            f = true;
                        }
                    }
                }
                sets.push_back(cur);
                sets[0].erase(sets[0].begin() + j);
                j--;
                counter++;
            }
            sets.erase(sets.begin());
        }
    }

    map <int, DFA_State> rootState;


    return DFA_Copy;
}
DFA_Minimization::~DFA_Minimization()
{
    //dtor
}
