#include "TokenManager.h"
#include <string.h>
#include <fstream>
#include "TransitionTable.h"
void TokenManager::write_to_file(ofstream file, vector<char> seq, string Type)
{
    for (int i = 0 ; i < seq.size(); i++)
        outputFile << seq[i];
    outputFile << Type << "\t"<< endl;
}

void TokenManager::init()
{


}
void TokenManager::GenToken(string str)
{
}

TokenManager::TokenManager()
{
    //ctor
}

TokenManager::~TokenManager()
{
    //dtor
}
