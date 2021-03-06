#include "TestSimpsonGraphBuilder.h"
#include "BFS.h"

TestSimpsonGraphBuilder::TestSimpsonGraphBuilder()
{
    //ctor
}

void TestSimpsonGraphBuilder::start(){
//    cout << "*******************************" << endl;
//    cout << "Start of the test:" << endl;
//    cout << "1) Init Graph:" << endl;
//    cout << (test_init_graph() ? "Passed" : "Failed")<< endl;
//    cout << "-------------------------------" << endl;
//
//    cout << "2) OR Operation:" << endl;
//    cout << (test_or_op()? "Passed" : "Failed")<< endl;
//    cout << "-------------------------------" << endl;
//
//    cout << "3) AND Operation:" << endl;
//    cout << (test_and_op()? "Passed" : "Failed")<< endl;
//    cout << "-------------------------------" << endl;
//
//    cout << "4) Clousure Operation:" << endl;
//    cout << (test_clousure_op()? "Passed" : "Failed")<< endl;
//    cout << "-------------------------------" << endl;
//
//    cout << "5) Positive Clousure Operation:" << endl;
//    cout << (test_positive_clousure_op()? "Passed" : "Failed")<< endl;
//    cout << "-------------------------------" << endl;

    /** Test Read File **/
    NFA_Generator gen("grammarInput.txt");
    Graph *g = gen.getNFA();
    cout<<g->get_graph_size() << endl;
    if( g->get_graph_size() == 33)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;

    cout << "-------------------------------" << endl;
    cout<< "Test on Input map:" <<endl;
    unordered_map<char,int> input_map = gen.get_input_map();
    unordered_map<char, int>::const_iterator it = input_map.begin();

     for(;it != input_map.end(); ++it)
        cout<< "Input "<< it->first << " - index " << it->second << endl;

    cout << "-------------------------------" << endl;
    cout<< "BFS Test:" <<endl;
    BFS b ;
  //  b.getBFS(g);
}
TestSimpsonGraphBuilder::~TestSimpsonGraphBuilder()
{
    //dtor
}
