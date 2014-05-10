#include "TestTokenManager.h"
#include "TokenManager.h"
#include "TransitionTable.h"

TestTokenManager::TestTokenManager()
{

}

std::vector< vector<int> > TestTokenManager::insertTable()
{
    vector<int> temp;

    temp.push_back(1);
    temp.push_back(0);
    transTable.push_back(temp);

    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    transTable.push_back(temp);

    temp.clear();
    temp.push_back(1);
    temp.push_back(3);
    transTable.push_back(temp);

    temp.clear();
    temp.push_back(-1);
    temp.push_back(0);
    transTable.push_back(temp);

    return transTable;

}

void TestTokenManager::isFinal()
{
    tokenType.push_back(false);
    tokenType.push_back(false);
    tokenType.push_back(false);
    tokenType.push_back(true);
}

TestTokenManager::~TestTokenManager()
{
    //dtor
}
