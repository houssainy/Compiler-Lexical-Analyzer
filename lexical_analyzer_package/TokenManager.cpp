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
}

//int TokenManager::GetNextState(char inputChar)
//{
//    if (inputChar == ' ' || inputChar == '/t' || inputChar == '/n')
//    {
//    is_Token = isToken(tempState);
//        if(is_Token)/**tempState: the previous return*/
//            {tempState = -1;}
//        /*if not final state just skip and return the last tempState*/
//        return tempState;
//    }
//        /************************** New Token ****************************/
//    if (is_Token && tempState == -1)
//    {
//        tempState = startNode;
//        is_Token = false;
//        seq.clear();
//    }
//
//    transTableIndex = transTable-> Get_Input(string(1,inputChar));
//
//        /*********** Input not Exist in our language alphabets*************/
//    if (transTableIndex == -1)
//    {
//        isError = true;
//        return -1;
//    }
//        /********************************************************************/
//    if (tempState != -1 )
//    {
//        tempState = transition_table[tempState][transTableIndex];
//        seq.push_back(inputChar);
//    }
//    else
//    {
//        int n  = seq.size();
//        for (int i = 0 ; i < n ; i ++)
//            store.push_front(seq[i]);
//        seq.push_back(inputChar);
//        while(store.size() != 0 )
//        {
//            for (int i = n ; i < 0; i--)
//            {
//                   tempState = GetNextState(store[i]);
//                if (isToken(tempState)){is_Token = true; return tempState;}
//                else store.pop_back()
//            }
//
//            if ( store.size() == 0) {isError = true; seq.pop_front();}
//            if(seq.size() == 0 ) {isError = true; }
//        }
//    }
//
//        /********************************************************************/
//    return tempState;*/
//}
//
//bool TokenManager:: isToken(int state)
//{
//    if (transTable.is_final(state))
//        return true;
//
//    else
//        return false;
//}


TokenManager::~TokenManager()
{
    //dtor
}
