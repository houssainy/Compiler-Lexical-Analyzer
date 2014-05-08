#include "BFS.h"

BFS::BFS()
{
    //ctor
}
vector<string>* BFS::getBFS(Graph* g){
 Node* first=g->get_start_node();
 vector<Edge> *children ;
 children= first->get_children();
    for(int i=0; i< children->size(); i++)
    {
        q.push((*children)[i]);
    }

 for(int j=0;j<g->get_graph_size();j++)
 {
        Edge element = q.front();
        q.pop();
        bfsItration.push_back(element.get_value());
         children = element.get_end_node()->get_children();
          for(int i=0;i<children->size();i++)
            {
              q.push((*children)[i]);
             }

 }

return &bfsItration;

}

BFS::~BFS()
{
    //dtor
}

