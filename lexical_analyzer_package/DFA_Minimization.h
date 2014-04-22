#ifndef DFA_MINIMIZATION_H
#define DFA_MINIMIZATION_H

#include <vector>
#include <DFA_State.h>

using namespace std ;

class DFA_Minimization
{
public:
    DFA_Minimization(vector < vector < DFA_State > > DFA ,vector < bool > finalState);

    virtual ~DFA_Minimization();
protected:
private:
    struct set
    {

        vector < int > states ;
    };
    vector < set > MDFA ;
};

#endif // DFA_MINIMIZATION_H
