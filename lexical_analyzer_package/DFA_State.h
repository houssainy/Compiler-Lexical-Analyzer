#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <vector>

using namespace std;

class DFA_State
{
public:

    DFA_State(int size ,bool isFinal );

    void set_state (int stateNumber);
    vector <bool> get_state ();
    bool is_final ();

    virtual ~DFA_State();

protected:

private:

    bool isFinal;
    vector <bool> states;
};

#endif // DFA_STATE_H
