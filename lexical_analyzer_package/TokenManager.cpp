#include "TokenManager.h"
#include <string.h>
#include "TransitionTable.h"
#include <fstream>
#include "../test_package/TestTokenManager.h"

TokenManager::TokenManager(TransitionTable *transTable)
{
    this->transTable = transTable;
    transition_table = transTable->Get_MDFA();
    startNode = 0;
    is_Token = false;
    isError = false;
    tempState = startNode;

    inputFile.open("inputFile.txt");
    if(inputFile)
    {
        outputFile.open("outputFile.txt");
        if(!outputFile)
            openFile = false;
        errorFile.open("errorFile.txt");
        if(!errorFile)
            openFile = false;
    }
    else
        openFile = false;
}



int TokenManager::GetNextState(char inputChar)
{

    /********************** white Spaces ********************************/
    if (inputChar == ' ' || inputChar == '\t' || inputChar == '\n' )
    {
        cout<< tempState << "tempStatee";
        if(tempState != -1) is_Token = isToken(tempState); /* *tempState: the previous return*/
        if(is_Token)
        {
            tempState = -1;
            return tempState;
        }
        return tempState;

    }

    /********************************************************************/
    if(inputChar != '\0'){
        transTableIndex = transTable-> Get_Input(inputChar);
        cout<< transTableIndex << "test";
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

    /*********** Input not Exist in our language alphabets**************/
    if (transTableIndex == -1)
    {
        isError = true;
        is_Token = false;
        discardChar.push_back(inputChar);
        return tempState;
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
            transTableIndex = transTable-> Get_Input(seq.back()); ///////
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
        }
        while(seq.size() != 0);
        return tempState;
    }
    /********************************************************************/
    if (tempState != -1 )
    {
        tempState = transition_table[tempState][transTableIndex];
        seq.push_back(inputChar);
        states.push_back(tempState);
    }
    else
    {
        Character = states;
        store = seq;
        store.pop_back();
        states.pop_back();
        cout << states.size() ;
        while (seq.size() != 0 )
        {
            while(store.size() != 0 )
            {
                cout << states.size()  ;
                tempState = states.back();

                if (isToken(tempState)) /////////////////////
                {
                    is_Token = true;
                    tempState = -2;
                    return tempState;
                }
                else
                {
                    store.pop_back();
                    states.pop_back();
                }
            }
            if (store.size() == 0)
            {
                isError = true;
                discardChar.push_back(seq.front());
                if(seq.size() != 0 ) seq.erase(seq.begin());
                Character.erase(Character.begin());
            }

            store = seq;
            states = Character;
        }
        if(seq.size() == 0 && store.size() !=0 )
        {
            isError = true;
           // discardChar.push_back(inputChar);
        }
    }

    /********************************************************************/

    return tempState;
}

vector<char> TokenManager::is_Error()
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

string TokenManager::getToken()
{

    if (!openFile)
        return "Error";

    int returnState;
    string token_type;
    /* **************************************************/

    while (! inputFile.eof())
    {
        if(tempState != -1 || inputChar == ' ') /* * to re-read the same char when Next state = -1 **/
        {
            inputFile >> noskipws >> inputChar;
            cout << endl<< "Input Read: " ;
            cout << inputChar<<endl << endl;
        }
        if(inputFile.eof())
        {


            transTableIndex = 0;
            returnState = GetNextState('\0');
        }
        else
            returnState = GetNextState(inputChar);
        if(tempState == -2)
        {
            if (seq.size() > store.size())
            {
                seq.clear(); states.clear();
                cout<< "Before"<<endl;
                for ( int i = 0 ; i < seq.size() ; i++)
                    cout << seq[i] << endl;

                states.insert(states.begin() , Character.begin(),  Character.begin() + Character.size());
                seq.insert(seq.begin() , store.begin() ,  store.begin() + store.size() );
//
      cout<< "After"<<endl;
                for ( int i = 0 ; i < seq.size() ; i++)
                    cout << seq[i] << endl;

            }
            else
            {
                seq.clear(); states.clear();
                states.insert(states.begin() , states.begin() + Character.size() ,  Character.end());
                seq.insert(seq.begin() , seq.begin() + store.size() , store.end());
                returnState = GetNextState(seq.back());
            }


        }

        if(is_Token)
        {
            token_type = transTable->type(states[states.size()]);
           // if(states.back() == -1)
             //   seq.pop_back();

            Token token ;
            token.type = token_type;
            token.token = seq ;
            symbol_table.push_back(token);
            string final_token = "";
            for (int i = 0 ; i < seq.size() ; i++)
                final_token += seq[i];

            tempState = -1;
            outputFile << final_token << endl;
            return final_token;
        }
         if(isError)
        {
            for(int i = 0 ; i < discardChar.size(); i++)
                errorFile << discardChar[i] << endl;
            discardChar.clear();
            isError = false;
        }
    }
    return "";

}

TokenManager::~TokenManager()
{
    inputFile.close();
    outputFile.close();
    errorFile.close();
}
