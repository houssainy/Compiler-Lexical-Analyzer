#ifndef TESTSIMPSONGRAPHBUILDER_H
#define TESTSIMPSONGRAPHBUILDER_H

#include "../lexical_analyzer_package/SimpsonGraphBuilder.h"
#include <vector>
#include "../graph_package/Edge.h"

class TestSimpsonGraphBuilder
{
    public:
        TestSimpsonGraphBuilder();

        bool test_init_graph(){
            Graph* g = builder.init_graph("A");
          //  vector<Edge> children = g->get_start_node()->get_children();
           // vector::iterator it = children
            return false;
        }

        bool test_and_op(){

            return false;
        }

        bool test_or_op(){
            return false;
        }


        bool test_clousure_op(){
            return false;
        }

        bool test_positive_clousure_op(){
            return false;
        }

        virtual ~TestSimpsonGraphBuilder();
    protected:
    private:
        SimpsonGraphBuilder builder;
};

#endif // TESTSIMPSONGRAPHBUILDER_H
