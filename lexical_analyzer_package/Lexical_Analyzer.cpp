#include "Lexical_Analyzer.h"

#include "NFA_Generator.h"
#include "DFA_Genrator.h"
#include "DFA_Minimization.h"
#include "TransitionTable.h"
#include <vector>
#include "DFA_State.h"
Lexical_Analyzer::Lexical_Analyzer(string file_path)
{
    //ctor
    init_transition_table(file_path);
}

#include "BFS.h"
void Lexical_Analyzer::init_transition_table(string file_path){
    NFA_Generator nfa(file_path);
    Graph *nfa_graph = nfa.getNFA();

    DFA_Genrator dfa(nfa_graph , nfa.get_input_map() );

    vector< vector<DFA_State> > my_dfa = dfa.Get_DFA();
    cout<< "**********************************"<<endl;
    cout<< "'MY DFA "<<endl;
    for( int i = 0 ; i < my_dfa.size() ; i++){
        vector<DFA_State> v = my_dfa[i];
        cout<< v.size() << endl;
        cout<< "Row " << i << endl;
        for(int j = 0 ; j < v.size() ;j++ )
            cout<< " "<<v[j].get_state_number() ;
        cout<< endl;
    }


    DFA_Minimization min_dfa;
    vector< vector<int> > m_dfa = min_dfa.minimize(dfa.Get_DFA() , dfa.Get_New_States() );
    cout<< "**********************************"<<endl;
    cout<< "'Min DFA "<<endl;
    for( int i = 0 ; i < m_dfa.size() ; i++){
        vector<int> v = m_dfa[i];
        cout<< "Row " << i <<endl;
        for(int j = 0; j < v.size() ;j++ )
            cout<< " "<<v[j];
        cout<< endl;
    }
    vector< bool > final_states = min_dfa.Is_final();

    TransitionTable trans_table(m_dfa , nfa.get_input_map() ,final_states , dfa.get_token_type());

  //  token_man = TokenManager(&trans_table);

    delete nfa_graph;
}

string Lexical_Analyzer::next_token(){
    return "";
}

Lexical_Analyzer::~Lexical_Analyzer()
{
    //dtor
}
