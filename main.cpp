#include <string.h>

#include "Lexical_Analyzer.h"

using namespace std;

int main(int arg , char* args[])
{

    /**************************** Main Code******************************/
    Lexical_Analyzer lx("grammarInput.txt");
    string token;
    while( (token = lx.next_token()) != "" )
        cout << token <<endl;



    /**************************** END OF MAIN ***************************/

    return 0;

};

