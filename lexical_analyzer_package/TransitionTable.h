#ifndef TRANSITIONTABLE_H
#define TRANSITIONTABLE_H

#include <string>
#include <vector>

using namespace std;

class TransitionTable
{
public:
    TransitionTable( vector < vector <int> > MDFA ,
                     vector <string> input,
                     vector <bool> finalState ,
                     vector <string> tokenType );
    vector < vector <int> > Get_MDFA ();
    vector < string > Get_Input ();
    bool is_final (int state );
    string type (int state );
    virtual ~TransitionTable();
protected:

private:
    vector < vector <int> > MDFA ;
    vector <string> input;
    vector <bool> finalState ;
    vector <string> tokenType ;
};

#endif // TRANSITIONTABLE_H
