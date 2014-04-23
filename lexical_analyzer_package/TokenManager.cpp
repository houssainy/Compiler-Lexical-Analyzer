#include "TokenManager.h"
#include <string.h>
#include <fstream>

TokenManager::TokenManager()
{
    //ctor
    transition_table = transTable.Get_MDFA();
    startNode = transition_table[0];
    is_Token = false;
    isError = false;
}

int TokenManager::GetNextState(char inputChar)
{
    if (inputChar == ' ' || inputChar == '/t' || inputChar == '/n')
    {
        if(isToken(tempState))/**tempState: the previous return*/
            {tempState = -1;}
        /*if not final state just skip and return the last tempState*/
        return tempState;
    }
        /************************** New Token ****************************/
    if (isToken() && tempState == -1)
    {
        tempState = startNode;
        is_Token = false;
        seq.clear();
    }

    transTableIndex = transTable.Get_Input(inputChar);

        /*********** Input not Exist in our language alphabets*************/
    if (transTableIndex == -1)
    {
        isError = true;
        return -1;
    }
        /********************************************************************/
    if (tempState != -1 )
    {
        tempState = transition_table[tempState][transTableIndex];
        seq.push_back(inputChar);
    }
    else
    {
        int n  = seq.size();
        for (int i = 0 ; i < n ; i ++)
            store.push_front(seq[i]);
        seq.push_back(inputChar);
        while(store.size() != 0 )
        {
            for (int i = n ; i < 0; i--)
            {
                   tempState = GetNextState(store[i]);
                if (isToken(tempState)){is_Token = true; return tempState;}
                else store.pop_back()
            }

            if ( store.size() == 0) {isError = true; seq.pop_front();}
            if(seq.size() == 0 ) {isError = true; }
        }
    }

        /********************************************************************/
    return tempState;
}

bool TokenManager:: isToken(int state)
{
    if (transTable.is_final(state))
        return true;

    else
        return false;
}


TokenManager::~TokenManager()
{
    //dtor
}
