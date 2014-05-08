#ifndef DFA_MINIMIZATION_H
#define DFA_MINIMIZATION_H

#include <vector>
#include <DFA_State.h>
#include <map>

using namespace std;

class DFA_Minimization
{

public:
    DFA_Minimization();
    vector < vector <int> > minimize (vector < vector < DFA_State > > DFA,vector < DFA_State > newStates );
    vector < bool > Is_final ();
    virtual ~DFA_Minimization();
protected:
private:
    vector <bool> isFinal ;
};

#endif // DFA_MINIMIZATION_H
