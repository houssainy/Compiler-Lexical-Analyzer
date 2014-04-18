#include "TokenManager.h"
#include <string.h>
#include <fstream>

void TokenManager::writeToOutput(vector<char> seq, cToken c)
{
    outputFile.open("output.txt");
    for (int i = 0 ; i < seq.size(); i++)
        outputFile << seq[i];
    outputFile << c << "\t"<< endl;
}
void TokenManager::GenToken(char str)
{
   if (isalpha(str))
    {
        if (currentToken != Unkown && currentToken != Ident && currentToken != Keyword)
        {
            writeToOutput(seq,currentToken);
            seq.clear();
            Ptr = graph.getStartNode();
            currentToken = Unkown;
        }

        vector<Edge>* temp = ((Node)*Ptr).get_children();
        for(int i = 0; i < ((vector<Edge>)*temp).size() ; i++)
        {
            if (((vector<Edge>)*temp)[i].get_value()== str)
            {
                Ptr = ((vector<Edge>)*temp)[i].get_end_node();
                seq.push_back(str);
                if (  !((Node)*Ptr).is_acceptance_node())
                    {currentToken = Ident;}
                else {currentToken = Keyword;}

            }
            break;
        }
    }
    if(isdigit(str))
    {
        if(currentToken  != Unkown || currentToken != Number)
        {
            writeToOutput(seq,currentToken);
            seq.clear();
            Ptr = graph.getStartNode();
            currentToken = Unkown;
        }
        vector<Edge>* temp = ((Node)*Ptr).get_children();
        Ptr = ((vector<Edge>)*temp)[5].get_end_node();
        seq.push_back(str);
        currentToken = Number;
    }
    if(isspace(str))
    {
        if(currentToken != Unkown)
        {
            writeToOutput(seq,currentToken);
            seq.clear();
            Ptr = graph.getStartNode();
            currentToken = Unkown;
        }
    }
    if (str == '+' || str == '-' || str == '=' || str == '*' || str == '<' || str == '>' ||   str == '/' || str == '!')
    {
        if(currentToken != Unkown && currentToken != Operat)
        {
            writeToOutput(seq,currentToken);
            seq.clear();
            Ptr = graph.getStartNode();
            currentToken = Unkown;
        }
         vector<Edge>* temp = ((Node)*Ptr).get_children();
        for(int i = 0; i < ((vector<Edge>)*temp).size() ; i++)
        {
             if (((vector<Edge>)*temp)[i].get_value()== str)
                {
                    Ptr =((vector<Edge>)*temp)[i].get_end_node();
                    seq.push_back(str);
                    if ( !((Node)*Ptr).is_acceptance_node())
                        {currentToken = Unkown;} // error?
                    else {currentToken = Operat;}
                }
                break;
         }
        if (str == '(' || str == ')' || str == '{' || str == '}' ||   str == ',' || str == ';')
        {
            if( currentToken != Unkown )
            {
               writeToOutput(seq,currentToken);
                seq.clear();
                Ptr = graph.getStartNode();
                currentToken = Unkown;
            }
            vector<Edge>* temp = ((Node)*Ptr).get_children();
            Ptr = ((vector<Edge>)*temp)[7].get_end_node();
            seq.push_back(str);
            currentToken = Punctuation;
        }
    }
}

TokenManager::TokenManager()
{
    //ctor
}

TokenManager::~TokenManager()
{
    //dtor
}
