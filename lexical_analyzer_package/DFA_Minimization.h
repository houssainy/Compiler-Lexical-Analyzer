#ifndef DFA_MINIMIZATION_H
#define DFA_MINIMIZATION_H

#include <vector>
#include <DFA_State.h>

using namespace std ;

class DFA_Minimization
{
typedef struct statesSet
    {
        vector < int > states ;
        vector < bool > mask ;
    };
public:
    DFA_Minimization(vector < vector < DFA_State > > DFA ,vector < DFA_State > newStates );

    statesSet creat_set (){
        statesSet state ;
        for (int i =0 ; i< initialStates ;i++){
            state.mask.push_back(false);
        }
        return state;

    }

    virtual ~DFA_Minimization();
protected:
private:

    vector < statesSet > MSets ;
    vector < vector < int > > MDFA ;
    bool isChanged ;
    int initialStates;

};

#endif // DFA_MINIMIZATION_H
