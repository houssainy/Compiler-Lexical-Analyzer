#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

class NFA_Generator
{
        NFA_Generator(string file_name);
        Graph* getAutomata();

        virtual ~NFA_Generator();
    protected:
    private:
        Graph* setAutomata(Graph* graph);
        Graph* read_from_file(string file_name);

        SimpsonGraphBuilder graph_builder;

        vector<string> *get_reguler_exp();
        vector<string> *get_reguler_difi();
        vector <string> *reguler_exp;
        vector <string> *reguler_difi;
        string file_name;

};

#endif // NFA_GENERATOR_H
