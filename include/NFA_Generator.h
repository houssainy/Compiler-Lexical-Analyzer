#ifndef NFA_GENERATOR_H
#define NFA_GENERATOR_H

class Node;
<<<<<<< HEAD
class Graph;
=======
class Graph;
>>>>>>> df53cba76b84642eeed534a0345a2b7627db408b
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
