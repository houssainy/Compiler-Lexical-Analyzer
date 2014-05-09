#include "Lexical_Analyzer.h"

#include "NFA_Generator.h"
#include "DFA_Genrator.h"
#include "DFA_Minimization.h"
#include "TransitionTable.h"
#include <vector>

Lexical_Analyzer::Lexical_Analyzer(string file_path)
{
    //ctor
    init_transition_table(file_path);
}

void Lexical_Analyzer::init_transition_table(string file_path){
    NFA_Generator nfa(file_path);
    Graph *nfa_graph = nfa.getNFA();

    DFA_Genrator dfa(nfa_graph ,nfa.get_input_map().size() );

    DFA_Minimization min_dfa;
    vector< vector<int> > m_dfa = min_dfa.minimize(dfa.Get_DFA() , dfa.Get_New_States() );
    vector< bool > final_states = min_dfa.Is_final();

    unordered_map <int,string> tokenType;
    TransitionTable trans_table(m_dfa , nfa.get_input_map() ,final_states , tokenType);

    token_man = TokenManager(&trans_table);

    delete nfa_graph;
}

string Lexical_Analyzer::next_token(){
    return "";
}

Lexical_Analyzer::~Lexical_Analyzer()
{
    //dtor
}
