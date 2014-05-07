#ifndef BFS_H
#define BFS_H
#include <iostream>
#include <vector>
#include<queue>
#include "Graph.h"


using namespace std;


class BFS
{
    public:
        BFS();
   vector<string> *getBFS(Graph* g);
        virtual ~BFS();
    protected:
    private:
    queue <Edge> q;
    vector <string> bfsItration;
};

#endif // BFS_H
