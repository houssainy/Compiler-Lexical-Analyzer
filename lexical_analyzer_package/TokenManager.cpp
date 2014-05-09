#include "TokenManager.h"
#include <string.h>
#include "TransitionTable.h"
#include <fstream>
#include "../test_package/TestTokenManager.h"

TokenManager::TokenManager(TransitionTable *transTable)
{
    this->transTable = transTable;
    transition_table = transTable->Get_MDFA();
   // transition_table=test.insertTable();
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
        transTableIndex = transTable-> Get_Input(inputChar);

    /********************** white Spaces ********************************/
    if (inputChar == ' ' || inputChar == '/t' || inputChar == '/n' )
    {
        is_Token = isToken(tempState);/**tempState: the previous return*/
        cout << "isToken :" << is_Token << endl;

        if(is_Token)
            {tempState = -1;}
        return tempState;
    }

    /*********** Input not Exist in our language alphabets**************/
    if (transTableIndex == -1)
    {
        isError = true;
        discardChar = inputChar;
        return -1;
    }

    /************************** New Token ****************************/
    if (is_Token && tempState == -1)
    {
        tempState = startNode;
        is_Token = false;
        seq.clear();
        states.clear();
    }

    /*********** Input not Exist in our language alphabets *************/
    if (transTableIndex == -1)
    {
        isError = true;
        is_Token = false;
        discardChar = inputChar;
        return tempState ;
    }
   /************************** End of file *****************************/
    if ((inputChar == '\0') && (seq.size()!= 0))
    {
        int n = seq.size();
        is_Token = isToken(tempState); /* *tempState: the previous return*/

        if(is_Token)
            return tempState;
        else
        {
            /* seq[n] != 0 */
            transTableIndex = transTable-> Get_Input(seq[n]);
            transTableIndex =2;
            tempState = -1;
        }
    }
    /********************************************************************/
    if (tempState != -1 )
    {
        /**There is accepted path -->
        1. add inputChar to sequence vector
        2. get Next State **/

        seq.push_back(inputChar);

        cout << "State:" << tempState;
        tempState = transition_table[tempState][transTableIndex];


        /* Test ******/
        cout<<"Index:" << transTableIndex <<endl;
        cout << "NextState:" << tempState << endl;
        if(isToken(tempState)) return tempState;
    }
    else
    {
        /**There is no accepted path -->
        1. if the last chars accepted **/
        int n  = seq.size();
        for (int i = 0 ; i < n ; i ++)
        {
            store.push_back(seq[i]);
        }
        while(store.size() != 0 )
        {
            store.pop_back(); states.pop_back();
            for (int i = n ; i > 0; i--)
            {
                tempState = states[states.size()];
                cout << "tempState: "<<tempState <<endl;
                for (int i = 0 ; i < store.size() ; i++)
                    cout<< states[i]<<endl;

                if (isToken(tempState)){
                        is_Token = true; return tempState;}
                else {store.pop_back(); states.pop_back();}

                tempState = transition_table[tempState][transTableIndex];
                cout<< tempState;

                if (isToken(tempState)){is_Token = true; return tempState;}
                else {store.pop_back(); states.pop_back();}
            }
        }
        if ( store.size() == 0) { isError = true; discardChar = seq.front(); seq.erase(seq.begin());}
        if(seq.size() == 0 ) {isError = true; discardChar = inputChar; }
    }

        /********************************************************************/
    states.push_back(tempState);
    return tempState;
}

char TokenManager::is_Error()
{
    //seq.pop_back();
    return discardChar;
}

bool TokenManager::isToken(int state)
{
    if (transTable->is_final(state))
        return true;
    else
        return false;
}

void TokenManager::printTransitionTable()
{
    for(int i = 0; i < transition_table.size(); ++i)
    {
        for(int j = 0; j < transition_table[i].size(); ++j)
            cout << transition_table[i][j];

        cout << endl;
    }
}

TokenManager::~TokenManager()
{
    //dtor
}
