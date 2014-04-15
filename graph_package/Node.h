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

        virtual ~Node();
    protected:
    private:
        int name;
        bool is_acceptance;
        vector<Edge> *children;
};

#endif // NODE_H
