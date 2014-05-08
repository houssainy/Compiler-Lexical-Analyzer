#ifndef TESTTOKENMANAGER_H
#define TESTTOKENMANAGER_H
#include <vector>
#include <iostream>

using namespace std;
class TestTokenManager
{
    public:
        void start();
        void print_output();
        vector<vector <int> > transTable;
        TestTokenManager();
        vector< vector<int> > insertTable();
        virtual ~TestTokenManager();
    protected:
    private:


};

#endif // TESTTOKENMANAGER_H
