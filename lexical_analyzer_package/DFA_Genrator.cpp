#include "DFA_Genrator.h"
#include <DFA_State.h>

#include <queue>

DFA_Genrator::DFA_Genrator(Graph * NFA , unordered_map<char,int> input_map)
{
    // Traverse
    init(NFA, input_map);
}

void DFA_Genrator::init(Graph * NFA , unordered_map<char,int> input_map){
    vector < vector < int > > trans_nfa;
    vector < vector <int > > eClouser;
    vector<bool> finalState;
    vector<string> token_type;

    vector<int> state_clouser;
    vector<int> state_trans;

    int node_name = 0;

    //BFS
    queue <Node*> q;

    // map of key = node name and value index of the node in transition table
    // if there was a value for the givven node name
    unordered_map<int,int> node_holder;

    // Node of old graph
    Node* temp_node;
    // Children of old graph
    vector<Edge> *children;

    temp_node = NFA->get_start_node();
    cout<< temp_node->get_node_name() << "Is Acceptance = " << temp_node->is_acceptance_node()<< "Token Type =" << temp_node->get_token_type() <<endl;
    // New start Node
    finalState.push_back(temp_node->is_acceptance_node());
    token_type.push_back(temp_node->get_token_type());

    //Push first node
    q.push(temp_node);
    node_holder.insert(pair<int,int>(temp_node->get_node_name(), node_name++));

    while(q.size()!=0)
    {
        temp_node = q.front(); // old node
        q.pop();

        children = temp_node->get_children();
        Node * node;

        for(int i=0; i< children->size(); i++)
        {
            node = (*children)[i].get_end_node(); // children #i
            cout<< node->get_node_name() << "Is Acceptance = " << node->is_acceptance_node()<< "Token Type =" << node->get_token_type() <<endl;
            if( node_holder.find(node->get_node_name()) != node_holder.end() ){ // visited add to new graph only
                if( (*children)[i].get_value() == "\\L"){ // if epson add it to epson clousre
                    state_clouser.push_back(node_holder[node->get_node_name()]);
                }else{ // not epson, add it trans_table
                    state_trans.push_back(node_holder[node->get_node_name()]); // state number
                    state_trans.push_back(input_map[(*children)[i].get_value()[0]]); // input for the previous state number
                }
                continue;
            }

            //Not visited

            // New start Node
            finalState.push_back(node->is_acceptance_node());
            token_type.push_back(node->get_token_type());

            //Push first node
            q.push(node);
            node_holder.insert(pair<int,int>(node->get_node_name(), node_name++));

            if( (*children)[i].get_value() == "\\L"){ // if epson add it to epson clousre
                state_clouser.push_back(node_holder[node->get_node_name()]);
            }else{ // not epson, add it trans_table
                state_trans.push_back(node_holder[node->get_node_name()]); // state number
                state_trans.push_back(input_map[(*children)[i].get_value()[0]]); // input for the previous state number
            }
        }
        if (state_trans.size()<2){
            state_trans.push_back(-1);
            state_trans.push_back(-1);
        }

        trans_nfa.push_back(state_trans);
        eClouser.push_back(state_clouser);
        state_clouser.clear();
        state_trans.clear();
    }
    cout<< "*******************************************"<<endl;
    cout<< "Transition Table :" << endl;
    for(int i = 0 ; i < trans_nfa.size() ;i++){
        vector<int> v = trans_nfa[i];
        cout<< "Row " << i << endl;
        cout<< endl;
        for(int j= 0 ; j < v.size() ; j++)
            cout<< " "<<v[j];
        cout<< " |  is final = "  << finalState[i] << " | Token Type = " << token_type[i] << "| Epson Closure ";
        vector<int> e_clo = eClouser[i];
        for(int j = 0 ; j < e_clo.size();j++)
            cout<< " " << e_clo[j];
        cout<< endl;

    }
    cout<< "End **********************************"<<endl;
    Generate(trans_nfa , eClouser , input_map.size() , finalState , token_type);
}

void DFA_Genrator::Generate (vector < vector < int > > NFA , vector < vector <int > > eClouser,int numberOfInputs,vector<bool> finalState , vector<string> token_type)
{
       //ctor
    int size = NFA.size ();

    if (size == -1)
        return;

    int counter =0 ;
    int counter2=0 ;
    int stateindex=0;
    string type="";

    DFA_State startState = DFA_State (size,stateindex);
    // Add start node to DFA_StateĿĿĿĿĿĿĿĿĿ
    startState.set_state(0,finalState[0]);
    if (finalState[0])
        type = token_type[0];
    // Add EClouser of first State to DFA_State
    while(counter2<startState.get_States_Number().size())
    {
        int state_number = startState.get_States_Number()[counter2];
        for(int i =0 ; i<eClouser[state_number].size() ; i++)
        {
            int state = eClouser[state_number][i];
            startState.set_state(state,finalState[state]);
            if (finalState[state] && type =="")
                type =token_type[state];
        }
        counter2++;
    }
    counter2=0;
    stateindex++;
    // Add start Node to newStates Vector
    newStates.push_back(startState);
    token_type.push_back(type);
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
            type = "";
            if (currentStateNumber.size()>finished_states)
            {
                for (int j =0 ; j<currentStateNumber.size(); j++)
                {
                    int tempState =  currentStateNumber[j];
                    if (NFA[tempState][0]!=-1 && NFA[tempState][1]==i)
                    {
                        finished_states ++ ;
                        element.set_state(NFA[tempState][0],finalState[NFA[tempState][0]]);
                        if (finalState[NFA[tempState][0]])
                            type = token_type[NFA[tempState][0]];

                    }

                }
                while(counter2<element.get_States_Number().size())
                {
                    int state_number = element.get_States_Number()[counter2];
                    for(int i =0 ; i<eClouser[state_number].size() ; i++)
                    {
                        int state = eClouser[state_number][i];
                        element.set_state(state,finalState[state]);
                        if (finalState[state] && type =="")
                            type =token_type[state];
                    }
                    counter2++;
                }
                counter2=0;
                if (!element.is_Empty())
                {
                    int found =Compare(element);
                    if (found ==-1)
                    {
                        newStates.push_back(element);
                        token_type.push_back(type);
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
vector<string> DFA_Genrator::get_token_type()
{

    return new_token_type;
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
