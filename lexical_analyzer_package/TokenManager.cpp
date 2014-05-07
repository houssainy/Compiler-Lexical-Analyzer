#include "TokenManager.h"
#include <string.h>
#include "TransitionTable.h"
#include <fstream>

TokenManager::TokenManager(TransitionTable *transTable)
{
    //ctor
    this->transTable = transTable;
    transition_table = transTable->Get_MDFA();
    startNode = transition_table[0][0];
    is_Token = false;
    isError = false;
    tempState = startNode;
}

int TokenManager::GetNextState(char inputChar)
{
    if(NextTempState != -1)
    {
      tempState = NextTempState;
      states.pop_back();
    }

    transTableIndex = transTable-> Get_Input(string(1,inputChar));

    /*********** Input not Exist in our language alphabets*************/
    if (transTableIndex == -1)
    {
        isError = true;
        discardChar = inputChar;
        return -1;
    }
    /********************************************************************/
    if (inputChar == ' ' || inputChar == '/t' || inputChar == '/n')
    {
        is_Token = isToken(tempState);
        if(is_Token)/**tempState: the previous return*/
            {tempState = -1;}
        /*if not final state just skip and return the last tempState*/
        return tempState;
    }
        /************************** New Token ****************************/
    if (is_Token && tempState == -1)
    {
        tempState = startNode;
        is_Token = false;
        seq.clear();
        states.clear();
    }

        /********************************************************************/
    seq.push_back(inputChar);
    if (tempState != -1 )
    {
        NextTempState = transition_table[tempState][transTableIndex];
    }
    else
    {
        int n  = seq.size();
        for (int i = 0 ; i < n-1 ; i ++)
        {
            store.push_back(seq[i]);
        }

        while(store.size() != 0 )
        {
            for (int i = n ; i < 0; i-1)
            {
                   //tempState = GetNextState(store[i]);
               inputChar = seq[i];
               NextTempState = states.back();
               transTableIndex = transTable-> Get_Input(string(1,inputChar));
               tempState = transition_table[NextTempState][transTableIndex];
                if (isToken(tempState)){is_Token = true; return tempState;}
                else {store.pop_back(); states.pop_back();}
            }
        }
        if ( store.size() == 0) {
                isError = true;
                discardChar = seq.front();
                seq.erase(seq.begin());

        if(seq.size() == 0 ) {isError = true; discardChar = inputChar; }
        }
    }

        /********************************************************************/
    states.push_back(tempState);
    return tempState;
}
char TokenManager::is_Error()
{
    return discardChar;
}

bool TokenManager::isToken(int state)
{
    if (transTable->is_final(state))
        return true;

    else
        return false;
}


TokenManager::~TokenManager()
{
    //dtor
}
