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
    if (inputChar == ' ' || inputChar == '\t' || inputChar == '\n' )
    {
        cout<< tempState << "tempStatee";
        if(tempState != -1) is_Token = isToken(tempState); /* *tempState: the previous return*/
        if(is_Token)
            {tempState = -1; return tempState;}
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
    if(tempState == -2)
    {
        do
        {
            is_Token = isToken(tempState);
            if(is_Token)
                break;
            else
            {
                isError = true;
                discardChar.push_back(tempState);
                seq.erase(seq.begin());
                states.erase(states.begin());
                tempState = states.back();
            }

        }while(seq.size() != 0);
        return tempState;
    }

    /********************************************************************/

    if (tempState != -1 )
    {
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
        Character = states;
        store = seq;
        store.pop_back(); states.pop_back();
         cout << "test here"<<endl <<store.size() << "store::"<< endl;
        cout << states.size() << "states::"<< endl;
        while (seq.size() != 0 )
        {
            while(store.size() != 0 )
            {
                cout << states.size() << "state:::"<< endl;
                tempState = states.back();

                if (isToken(tempState)){/////////////////////
                    is_Token = true; tempState = -2; return tempState;}
                else {
                        store.pop_back();states.pop_back();}
            }
            if (store.size() == 0) {
                    isError = true; discardChar.push_back(seq.front());
                    if(seq.size() != 0 ) seq.erase(seq.begin()); Character.erase(Character.begin()); }

            store = seq;
            states = Character;
        }
        if(seq.size() == 0 ) {isError = true; discardChar.push_back(inputChar);
        }
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
