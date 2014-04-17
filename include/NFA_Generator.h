#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

class Node;
class Graph;
class Edge;

class NFA_Generator
{
    public:
        NFA_Generator(string file_name);
        vector <string> *read_File(string file_name);
        vector <string> *get_reguler_exp();
        vector <string> *get_reguler_difi();
        Graph* get_evaluation(string exp);


        virtual ~NFA_Generator();
    protected:
    private:
    vector <string> expression;
    vector <string> difinition;
    int node_number=0;
    string file_name;
    stack <Graph> operation;
    stack <Graph> operand;
};

#endif
