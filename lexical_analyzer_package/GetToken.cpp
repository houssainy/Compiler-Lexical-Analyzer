#include "GetToken.h"

GetToken::GetToken(TransitionTable *transTable)
{
    //ctor
    this->transTable = transTable;
    transition_table = transTable->Get_MDFA();

    inputFile.open("inputFile.txt");
//    if(inputFile)
//    {
    outputFile.open("outputFile.txt");
//        if(!outputFile)
//            openFile = false;
    errorFile.open("errorFile.txt");
    symbolFile.open("symbolFile.txt");
//        if(!errorFile)
//            openFile = false;
//    }
//    else
//        openFile = false;

    current_node = 0;
}

string GetToken::getToken()
{
    char c;
    while( (c = read_next_char()) != '\0' /*End of file*/)
    {
        if( c == ' ' || c == '\t')  //white space
        {
            if(transTable->is_final(read_input.back().state))
            {
                current_node = 0;
//                string type;
//                if( (type = transTable->type(read_input.back().state)) == "key_word"  || type == "punctuation" || type == "")
//                {
                    string token ="";
                    int vector_size = read_input.size() ;
                    for( int i= 0 ; i < vector_size ; i++)
                    {
                        token= read_input.back().input + token;
                        read_input.erase(read_input.begin() + read_input.size() - 1);
                    }

                    symbolFile <<"Token = " << token <<" ,Type = "<<transTable->type(read_input.back().state) <<  endl;
                    outputFile << token << endl;
                    return token;
//                }
//                else
//                {
//                    read_input.clear();
//                    outputFile << type << endl;
//                    return type;
//                }

            }
            continue;
        }

        int input_index = transTable->Get_Input(c);

        if( input_index == -1) // invalid input
        {
            errorFile << c <<endl;
            continue;
        }

        if( transition_table[current_node][input_index] != -1)  // there is a next state
        {
            current_node = transition_table[current_node][input_index];

            State new_state;
            new_state.input = c;
            new_state.state = current_node;

            read_input.push_back(new_state);
        }
        else   // no path from the current node to the current input
        {
            // Roll back
            State new_state;
            new_state.input = c;
            new_state.state = current_node;

            temp_state.push(new_state);

            current_node = 0;
            while( !read_input.empty() && !transTable->is_final(read_input.back().state) )  //Not final state
            {
                temp_state.push(read_input.back());
                read_input.erase(read_input.begin() + read_input.size() - 1);
            }

            if( !read_input.empty() ) // there is a final state
            {
//                string type;
//                if( (type = transTable->type(read_input.back().state)) == "key_word"  || type == "punctuation")
//                {
                    string token ="";
                    int vector_size = read_input.size() ;
                    for( int i= 0 ; i < vector_size ; i++)
                    {
                        token= read_input.back().input + token;
                        read_input.erase(read_input.begin() + read_input.size() - 1);
                    }
                    symbolFile <<"Token = " << token <<" ,Type = "<<transTable->type(read_input.back().state) <<  endl;
                    outputFile << token << endl;
                    return token;
//                }
//                else
//                {
//                    read_input.clear();
//                    outputFile << type << endl;
//                    return type;
//                }
            }
            else
            {
                errorFile << temp_state.top().input << endl;
                temp_state.pop();
            }
        }
    }

    if( !read_input.empty() )  //
    {
        while( !read_input.empty() && !transTable->is_final(read_input.back().state) )  //Not final state
        {
            temp_state.push(read_input.back());
            read_input.erase(read_input.begin() + read_input.size() - 1);
        }
        current_node = 0;
        if( !read_input.empty())
        {
//            string type;
//            if( (type = transTable->type(read_input.back().state)) == "key_word"  || type == "punctuation")
//            {
                string token ="";
                int vector_size = read_input.size() ;
                for( int i= 0 ; i < vector_size ; i++)
                {
                    token= read_input.back().input + token;
                    read_input.erase(read_input.begin() + read_input.size() - 1);
                }

                symbolFile <<"Token = " << token <<" ,Type = "<<transTable->type(read_input.back().state) <<  endl;
                outputFile << token << endl;
                return token;
//            }
//            else
//            {
//                read_input.clear();
//                outputFile << type << endl;
//                return type;
//            }
        }
        else     //no matching discard first input in the stack
        {
            // All input now in the stack
            errorFile << temp_state.top().input << endl;
            temp_state.pop();
            return getToken();
        }

    }
    else  // No input remaining!
        return "";
}

char GetToken::read_next_char()
{
    if(!temp_state.empty())  // there is an input in the stack
    {
        State s = temp_state.top();
        temp_state.pop();
        return s.input;
    }

    char c ;
    inputFile >> noskipws >> c;
    if( c == -1)
        return inputFile.eof();
    return c;
}

GetToken::~GetToken()
{
    //dtor
    inputFile.close();
    outputFile.close();
    errorFile.close();
}
