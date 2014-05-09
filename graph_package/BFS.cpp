#include "BFS.h"

BFS::BFS()
{
    //ctor
}

vector<string>* BFS::getBFS(Graph* g)
{
    cout<< g->get_graph_size() << endl;
    bool v[g->get_graph_size()];
    for(int i = 0 ; i < g->get_graph_size() ; i++)
        v[i] = false;

    Node* first=g->get_start_node();
    vector<Edge> *children ;
    children= first->get_children();
    v[first->get_node_name()] = true;

    for(int i=0; i< children->size(); i++)
    {
        q.push((*children)[i]);
    }

    cout<<"size Of Queue"<<q.size()<<endl;
    int j=0;
    while(q.size()!=0)
    {
        Edge element = q.front();
        q.pop();
        bfsItration.push_back(element.get_value());
        cout<<"size Of Queue-"<<q.size()<<endl;
        cout<<"element ("<<j++<<")in BFS ";
        cout<<element.get_value()<<endl;
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
    return &bfsItration;

}

BFS::~BFS()
{
    //dtor
}

