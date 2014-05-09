#include "Lexical_Analyzer.h"

#include "NFA_Generator.h"
#include "DFA_Genrator.h"

Lexical_Analyzer::Lexical_Analyzer(string file_path)
{
    //ctor
    init_transition_table(file_path);
}

void Lexical_Analyzer::init_transition_table(string file_path){
    NFA_Generator nfa(file_path);
    Graph *nfa_graph = nfa.getAutomata();
    // DFA_Genrator dfa;
    //dfa.

    delete nfa_graph;
}

string Lexical_Analyzer::next_token(){
    return "";
}

Lexical_Analyzer::~Lexical_Analyzer()
{
    //dtor
}
