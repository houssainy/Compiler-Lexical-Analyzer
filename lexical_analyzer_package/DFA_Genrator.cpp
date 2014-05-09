#include "DFA_Genrator.h"
#include <DFA_State.h>

#include <queue>

DFA_Genrator::DFA_Genrator(Graph * NFA , int input_size)
{
    // Traverse
    init(NFA, input_size);
}

void DFA_Genrator::init(Graph * NFA , int input_size){
    vector < vector < int > > trans_nfa;
    vector < vector <int > > eClouser;
    vector<bool> finalState;

    vector<int> state_clouser;
    vector<int> state_trans;

    int node_name = 0;

    //BFS
    queue <Edge> q;
    Edge e;

    bool v[NFA->get_graph_size()];
    for(int i = 0 ; i < NFA->get_graph_size() ; i++)
        v[i] = false;

    Node* first = NFA->get_start_node();
    vector<Edge> *children = first->get_children();

    v[first->get_node_name()] = true;

    for(int i=0; i< children->size(); i++)
    {
        e = (*children)[i];
        q.push(e);

        if( e.get_value() == "\\L"){
          //  state_clouser.push_back();
        }
    }

    while(q.size()!=0)
    {
        Edge element = q.front();
        q.pop();
        bfsItration.push_back(element.get_value());
        if( v[element.get_end_node()->get_node_name()] )
            continue;

        v[element.get_end_node()->get_node_name()] = true;
        children = element.get_end_node()->get_children();
        for(int i=0; i<children->size(); i++)
        {
            Edge child = (*children)[i];
            q.push((*children)[i]);
        }


    }

    Generate(trans_nfa , eClouser , input_size , finalState);
}

void DFA_Genrator::Generate (vector < vector < int > > NFA , vector < vector <int > > eClouser,int numberOfInputs,vector<bool> finalState)
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
        int state = eClouser[0][i];
        bool testcase = finalState [state];
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
        DFA_State currentState = newStates[counter];
        vector <int> currentStateNumber = currentState.get_States_Number();
        for (int i =0 ; i<numberOfInputs; i++)
        {
            DFA_State element = DFA_State (size,stateindex);
            if (currentStateNumber.size()>finished_states)
            {
                for (int j =0 ; j<currentStateNumber.size(); j++)
                {
                    int tempState =  currentStateNumber[j];
                    if (NFA[tempState][0]!=-1 && NFA[tempState][1]==i+1)
                    {
                        finished_states ++ ;
                        //remove it
                        bool test= finalState[NFA[tempState][0]];
                        element.set_state(NFA[tempState][0],finalState[NFA[tempState][0]]);
                        for(int k =0 ; k<eClouser[NFA[tempState][0]].size() ; k++)
                        {
                            int state = eClouser[NFA[tempState][0]].at(k);
                            element.set_state(state,finalState[state]);
                        }
                    }

                }
                if (!element.is_Empty())
                {
                    int found =Compare(element);
                    if (found ==-1)
                    {
                        newStates.push_back(element);
                        stateindex ++ ;
                    }
                    else
                        element = newStates[found];
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
vector < DFA_State> DFA_Genrator::Get_New_States ()
{

    return newStates;
}

int DFA_Genrator::Compare (DFA_State state )
{
    vector <bool> bitmask = state.get_state();
    for (int i =0 ; i<newStates.size(); i++)
    {
        vector <bool> tempbitmask = newStates[i].get_state();
        if (bitmask==tempbitmask)
            return i;
    }
    return -1;
}

DFA_Genrator::~DFA_Genrator()
{
    //dtor
}
