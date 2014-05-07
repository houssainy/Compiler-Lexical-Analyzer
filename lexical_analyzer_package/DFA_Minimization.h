#ifndef DFA_MINIMIZATION_H
#define DFA_MINIMIZATION_H

#include <vector>
#include <DFA_State.h>
#include <map>

using namespace std;

class DFA_Minimization
{

public:
    DFA_Minimization(vector < vector < DFA_State > > DFA );
    vector < vector <DFA_State> > minimize (vector < DFA_State > newStates );
    virtual ~DFA_Minimization();
protected:
private:
  vector < vector <DFA_State> > DFA_Copy ;

};

#endif // DFA_MINIMIZATION_H
