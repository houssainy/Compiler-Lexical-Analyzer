#include <iostream>
#include <fstream>
#include <string.h>
#include "lexical_analyzer_package/TokenManager.h"
#include "graph_package/Graph.h"
#include "graph_package/Node.h"

using namespace std;

int main()
{
    char inputChar ;
    TokenManager token;
    ifstream inputFile ("p.txt");
    ofstream errorsFile;

    if(inputFile)
    {
        do
        {
            inputFile >> noskipws >> inputChar ;
            cout << inputChar;
            token.GenToken(inputChar);
        }while(! inputFile.eof());
        inputFile.close();
    }
    else
    {
        cout<< "Unable to open file";
    }
    return 0;

};
