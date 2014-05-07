#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <vector>

using namespace std;

class DFA_State
{
public:

    DFA_State(int size ,int Number );

    void set_state (int stateNumber,bool isFinal);
    vector <bool> get_state ();
    bool is_final ();
    int get_state_number ();
    void set_state_number (int number );
    vector <int> get_States_Number ();
    bool is_Empty ();

    virtual ~DFA_State();

protected:

private:

    bool isEmpty;
    bool isFinal;
    vector <bool> states;
    int Number;
    vector <int> statesNumber;
};

#endif // DFA_STATE_H
