#ifndef TESTSIMPSONGRAPHBUILDER_H
#define TESTSIMPSONGRAPHBUILDER_H

#include "../lexical_analyzer_package/SimpsonGraphBuilder.h"
#include "../lexical_analyzer_package/NFA_Generator.h"
#include <vector>
#include "../graph_package/Edge.h"

#include <stack>
#include <fstream>
#include <string.h>

#include <iostream>

using namespace std;
class TestSimpsonGraphBuilder
{
    public:
        TestSimpsonGraphBuilder();

        void start();

        virtual ~TestSimpsonGraphBuilder();
    protected:
    private:
        SimpsonGraphBuilder builder;

                bool test_init_graph(){

            Graph* g = builder.init_graph("A");
            vector<Edge> *children = g->get_start_node()->get_children();

            vector<Edge>::iterator it = children->begin();
            string val = it->get_value();

            if( val != "A")
                return false;

            Node * end_node = it->get_end_node();
            if( end_node == NULL)
                return false;

            cout<< (end_node == g->get_end_node() )<< endl;
            cout<< (end_node != g->get_end_node() )<< endl;
            if( end_node != g->get_end_node() )
                return false;

            if( g->get_graph_size() != 2)
                return false;
            return true;
        }

        bool test_or_op(){
            Graph* g1 = builder.init_graph("A");
            Graph* g2 = builder.init_graph("B");
            Graph* g = builder.or_operation(g1,g2);


            Node * start_node = g->get_start_node();
            Node * end_node = g->get_end_node();

            vector<Edge> *children = start_node->get_children();
            vector<Edge>::iterator it = children->begin();

            //First graph
            if( !(it->get_value() == "\L" ) )
                return false;

            // check graph one
            Node * node = it->get_end_node();

            if( node != g1->get_start_node())
                return false;

            vector<Edge> *children1 = node->get_children();
            vector<Edge>::iterator it1 = children1->begin();

            if( !(it1->get_value()=="A") )
                return false;

            Node * node2 = it1->get_end_node() ;
            if( node2 == NULL )
                return false;

            // End node
            vector<Edge>::iterator temp_it = (node2->get_children())->begin();
            if( !(temp_it->get_value()=="\L") )
                return false;

            if( temp_it->get_end_node() != end_node )
                return false;

            //-------------------------------------
            it++;
            //Second graph
            node = it->get_end_node();

            if( node != g2->get_start_node())
                return false;

            children1 = node->get_children();
            it1 = children1->begin();

            if( !(it1->get_value()=="B") )
                return false;

            node2 = it1->get_end_node() ;
            if( node2 == NULL )
                return false;

            // End node
            temp_it = node2->get_children()->begin();
            if( !(temp_it->get_value()=="\L") )
                return false;

            if( temp_it->get_end_node() != end_node )
                return false;

            if( g->get_graph_size() != 6 )
                return false;
            return true;
        }

        bool test_and_op(){
            Graph* g1 = builder.init_graph("A");
            Graph* g2 = builder.init_graph("B");
            Graph* g = builder.and_operation(g1,g2);

            Node * start_node = g->get_start_node();
            Node * end_node = g->get_end_node();

            if( start_node != g1->get_start_node())
                return false;

            if(end_node != g2->get_end_node())
                return false;

            vector<Edge> *children = start_node->get_children();
            vector<Edge>::iterator it = children->begin();

            //First graph
            if( !(it->get_value() == "A" ) )
                return false;

            Node * temp_node = it->get_end_node();
            vector<Edge> *children1 = temp_node->get_children();
            vector<Edge>::iterator it1 = children1->begin();

            if( it1->get_value() != "\L" )
                return false;

            //Second graph
            temp_node = it1->get_end_node();
            children = temp_node->get_children();
            it = children->begin();

            if( it->get_end_node() != end_node )
                return false;

            if(g->get_graph_size() != 4)
                return false;
            return true;
        }


        bool test_clousure_op(){
            Graph* g1 = builder.init_graph("A");
            Graph* g = builder.clousure_operation(g1);

            Node * start_node = g->get_start_node();
            Node * end_node = g->get_end_node();

            if( end_node != g1->get_end_node())
                return false;

            vector<Edge> *children = start_node->get_children();
            vector<Edge>::iterator it = children->begin();

            if( it->get_value() != "\L" )
                return false;

            if( it->get_end_node() != g1->get_start_node() )
                return false;

            it++;
            if( it->get_value() != "\L" )
                return false;

            if( it->get_end_node() != g1->get_end_node() )
                return false;

            vector<Edge> *children2 = start_node->get_children();
            vector<Edge>::iterator it2 = children2->begin();

            Node * temp_node = it2->get_end_node();
            vector<Edge> *temp_children = temp_node->get_children();
            vector<Edge>::iterator temp_it = temp_children->begin();

            if( temp_it->get_value() != "A")
                return false;
            if(temp_it->get_end_node() != g1->get_end_node())
                return false;

            if( g->get_graph_size() != 3)
                return false;
            return true;
        }

        bool test_positive_clousure_op(){
            Graph* g1 = builder.init_graph("A");
            Graph* g = builder.positive_clousure_operation(g1);

            Node * start_node = g->get_start_node();
            Node * end_node = g->get_end_node();

            if( start_node != g1->get_start_node())
                return false;

            vector<Edge> *children = start_node->get_children();
            vector<Edge>::iterator it = children->begin();

            if( it->get_value() != "A" )
                return false;

            if( it->get_end_node() != g1->get_end_node() )
                return false;

            Node *temp_node = it->get_end_node();
            vector<Edge> *temp_children = temp_node->get_children();
            vector<Edge>::iterator temp_it = temp_children->begin();

            if( temp_it->get_value() != "\L")
                return false;
            if(temp_it->get_end_node() != g1->get_start_node())
                return false;

            temp_it++;
            if( temp_it->get_value() != "\L")
                return false;
            if(temp_it->get_end_node() != end_node)
                return false;

            if( g->get_graph_size() != 3)
                return false;
            return true;
        }
};

#endif // TESTSIMPSONGRAPHBUILDER_H
