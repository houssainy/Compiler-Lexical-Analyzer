#include "DFA_Minimization.h"


DFA_Minimization::DFA_Minimization()
{
    //ctor
}

vector< vector <int> > DFA_Minimization:: minimize (vector < vector < DFA_State > > DFA,vector < DFA_State > newStates)
{
    vector < vector <DFA_State> > sets ;
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

    int acc_size = acceptance.size();
    int non_size = nonacceptance.size();
    sets.push_back(acceptance);
    sets.push_back(nonacceptance);

    bool f = true;

    while(f)
    {
        f = false;
        int setCount = sets.size();
        for(int i = 0 ; i < setCount ; i++)
        {
            for(int j = 0 ; j < sets[0].size() ; j++)
            {
                vector <DFA_State> cur;
                cur.push_back(sets[0][j]);
                int first_state =sets[0][j].get_state_number();
                //stateSet[first_state] = counter;

                for(int k = j+1 ; k < sets[0].size() ; k++)
                {
                    int second_state = sets[0][k].get_state_number();
                    bool check = true;
                    for(int l = 0 ; l < DFA[0].size() ; l++)
                    {

                        int testvalue = stateSet[DFA[second_state][l].get_state_number()];
                        testvalue = stateSet[DFA[first_state][l].get_state_number()];
                        if(stateSet[DFA[first_state][l].get_state_number()] != stateSet[DFA[second_state][l].get_state_number()])
                            check =false;
                    }
                    if (check)
                    {
                        cur.push_back(sets[0][k]);
                        sets[0].erase(sets[0].begin() + k);
                       // stateSet[second_state] = counter;
                        k--;
                    }
                    else
                        f=true;
                }
                for (int k =0 ; k<cur.size();k++)
                {
                    stateSet[cur[k].get_state_number()]=counter;
                }
                sets.push_back(cur);
                sets[0].erase(sets[0].begin() + j);
                j--;
                counter++;
            }
            sets.erase(sets.begin());
        }
    }

    map <int, int> rootState;
   vector < vector <int> > MDFA ;

    for(int i = 0 ; i < sets.size() ; i++)
        for(int j = 0 ; j < sets[i].size() ; j++)
            rootState.insert(pair<int, int> (sets[i][j].get_state_number(), sets[i][0].get_state_number()));


    for(int i = 0 ; i < DFA.size() ; i++)
    {
        vector <int > row ;
        for(int j = 0 ; j < DFA[i].size() ; j++)
        {
            int state = DFA[i][j].get_state_number();
            if (state==-1)
                row.push_back(-1);
            else
                row.push_back(rootState[state]);

        }
        bool test = newStates[i].is_final();
        isFinal.push_back(newStates[i].is_final());
        MDFA.push_back(row);

    }
   return MDFA;
}
vector < bool > DFA_Minimization::Is_final ()
{

    return isFinal;

}

DFA_Minimization::~DFA_Minimization()
{
    //dtor
}
