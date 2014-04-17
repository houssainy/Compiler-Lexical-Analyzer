#ifndef GRAPH_H
#define GRAPH_H


class Graph
{
    public:
        Graph(Node* start);
        Node* get_start_node();
        virtual ~Graph();
    protected:
    private:
     int get_node_num();
    void increas_node_number();
   Node* start_node;
    int node_num ;
};

#endif // GRAPH_H
