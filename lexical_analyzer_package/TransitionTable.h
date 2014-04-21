#ifndef TRANSITIONTABLE_H
#define TRANSITIONTABLE_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TransitionTable
{
public:
    TransitionTable( vector < vector <int> > MDFA ,
                     unordered_map <string,int> input,
                     vector <bool> finalState ,
                     vector <string> tokenType );
    vector < vector <int> > Get_MDFA ();
    int Get_Input (string input);
    bool is_final (int state );
    string type (int state );

    virtual ~TransitionTable();
protected:

private:
    vector < vector <int> > MDFA ;
    unordered_map <string,int> input_map;
    vector <bool> finalState ;
    vector <string> tokenType ;
};

#endif // TRANSITIONTABLE_H
