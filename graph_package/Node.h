#ifndef NODE_H
#define NODE_H

#include <vector>
#include "Edge.h"

#include <iostream>

using namespace std;

class Node
{
    public:
        Node();

        vector<Edge> *get_children();
        void add_child(Node* end_node, string value);
        void set_acceptance_state(bool is_acceptance);
        bool is_acceptance_node();

        void set_token_type(string token_type){
            this->token_type = token_type;
        }

        string get_token_type(){
            return token_type;
        }

        void set_node_name(){
            this->node_name = node_count++;
        }

        int get_node_name(){
            return node_name;
        }

        static int node_count;
        virtual ~Node();
    protected:
    private:
        int node_name = -1;
        string token_type;
        bool is_acceptance = false;
        vector<Edge> children;


};
#endif // NODE_H
