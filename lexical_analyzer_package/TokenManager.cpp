#include "TokenManager.h"
#include <string.h>
#include "TransitionTable.h"
#include <fstream>
#include "../test_package/TestTokenManager.h"

TokenManager::TokenManager(/*TransitionTable *transTable*/)
{

   // this->transTable = transTable;
  //  transition_table = transTable->Get_MDFA();
    transition_table=test.insertTable();
    test.isFinal();
    is_Final = test.tokenType;
    startNode = 0;
    is_Token = false;
    isError = false;
    tempState = startNode;
    cout<< "Start State:"<<tempState << endl;
}

int TokenManager::GetNextState(char inputChar)
{
    /********************************************************************/
    if(inputChar != '\0')
       // transTableIndex = transTable-> Get_Input(inputChar);

    /********************** white Spaces ********************************/
    if (inputChar == ' ' || inputChar == '/t' || inputChar == '/n' )
    {
        is_Token = isToken(tempState);/* *tempState: the previous return*/
        cout << "isToken :" << is_Token << endl;

        if(is_Token)
            {tempState = -1;}
        return tempState;
    }

    /*********** Input not Exist in our language alphabets**************/
    if (transTableIndex == -1)
    {
        isError = true;
        is_Token = false;
        discardChar.push_back(inputChar);
        return tempState;
    }

    /************************** New Token ****************************/
    if (is_Token && tempState == -1)
    {
        tempState = startNode;
        is_Token = false;
        seq.clear();
        states.clear();
        Character.clear();
    }

   /************************** End of file ***************************/
    if ((inputChar == '\0') && (seq.size()!= 0))
    {
        int n = seq.size();
        is_Token = isToken(tempState); /* *tempState: the previous return*/

        if(is_Token)
            return tempState;
        else
        {
            /* seq[n] != 0 */
           // transTableIndex = transTable-> Get_Input(seq[n]);
           // transTableIndex =2;
            tempState = -1;
        }
    }
    /********************************************************************/
    if (tempState != -1 )
    {
        /**There is accepted path -->
        1. add inputChar to sequence vector
        2. get Next State **/

        cout << "Current State:" << tempState << "\t \t";
        tempState = transition_table[tempState][transTableIndex];

        seq.push_back(inputChar);
        /* Test ******/
        cout<<"Input Index:" << transTableIndex << "\t \t";
        cout << "Next State:" << tempState << endl << endl;
        //is_Token = isToken(tempState);
    }
    else
    {
        /**There is no accepted path -->
        1. if the last chars accepted **/

        Character = seq;
        store = seq;
        store.pop_back(); states.pop_back();
        if (isToken(states.back())){
            is_Token = true;  seq = store; return tempState;}
        while (seq.size() != 0 )
        {
            while(store.size() != 0 )
            {
                tempState = states.back();

                if (isToken(tempState)){
                    is_Token = true; return tempState;}
                else {
                        store.pop_back(); }
            }

            if (store.size() == 0) {
                    isError = true; discardChar.push_back(seq.front());
                    if(seq.size() != 0 ) seq.erase(seq.begin()); states.erase(states.begin()); }
            store = seq;
        }
        if(seq.size() == 0 ) {isError = true; discardChar.push_back(inputChar); }
    }

        /********************************************************************/
    states.push_back(tempState);
    return tempState;
}

vector<char> TokenManager::is_Error()
{
    //seq.pop_back();
    return discardChar;
}

bool TokenManager::isToken(int state)
{

    bool temp = is_Final.at(state);
    if (temp/*transTable->is_final(state)*/)
        return true;
    else
        return false;
}

void TokenManager::printTransitionTable()
{
    cout << endl <<" -------* Transition Table *-------- " << endl;
    for(int i = 0; i < transition_table.size(); ++i)
    {
        for(int j = 0; j < transition_table[i].size(); ++j)
            cout << transition_table[i][j] << "\t";

        cout << endl << endl;
    }
     cout << " -----------------------------------";
}

TokenManager::~TokenManager()
{
    //dtor
}
