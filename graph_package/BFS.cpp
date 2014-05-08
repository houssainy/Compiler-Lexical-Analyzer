#include "BFS.h"

BFS::BFS()
{
    //ctor
}

vector<string>* BFS::getBFS(Graph* g)
{
    Node* first=g->get_start_node();
    vector<Edge> *children ;
    children= first->get_children();
    first->set_visited(true);

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
        if( element.get_end_node()->is_visited())
            continue;

        element.get_end_node()->set_visited(true);
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

