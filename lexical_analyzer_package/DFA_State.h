#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <vector>

using namespace std;

class DFA_State
{
public:

    DFA_State(int size ,bool isFinal,int Number );

    void set_state (int stateNumber);
    vector <bool> get_state ();
    bool is_final ();
    int get_state_number ();

    virtual ~DFA_State();

protected:

private:

    bool isEmpty;
    bool isFinal;
    vector <bool> states;
    int Number;
};

#endif // DFA_STATE_H
