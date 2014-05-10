#include "GetToken.h"

GetToken::GetToken(TransitionTable *transTable)
{
    //ctor
    this->transTable = transTable;
    transition_table = transTable->Get_MDFA();
    current_node = 0;
}

string GetToken::getToken(){
    char c;
     while( (c = read_next_char()) != inputFile.eof() ){

        int input_index = transition_table->Get_Input(c);

        if( input_index == -1){// invalid input
            errorFile << c <<endl;
            continue;
        }

        if( transition_table[current_node][input_index] != -1){ // there is a next state
            current_node = transition_table[current_node][input_index];

            State new_state;
            new_state.input = c;
            new_state.state = current_node;

            read_input.push_back(new_state);
        }else{ // no path from the current node to the current input
            // Roll back
            while( !read_input.empty() && !transTable.is_final(read_input.back().state) ){ //Not final state
                temp_state.push(read_input.back())
                read_input.erase(read_input.back());
            }

            if( !read_input.empty() ){// there is a final state
                string token ="";
                for( int = 0 ; i < read_input.size() ; i++)
                    token+= read_input.back();

                read_input.clear();
                return token;
            }else
                errorFile << c << endl;
        }
     }

     if( !read_input.empty() ){ //
        while( !read_input.empty() && !transTable.is_final(read_input.back().state) ){ //Not final state
            temp_state.push(read_input.back())
            read_input.erase(read_input.back());
        }
        if( !read_input.empty()){
            string token ="";
            for( int = 0 ; i < read_input.size() ; i++)
                token+= read_input.back();

            read_input.clear();
            return token;
        }else  { //no matching discard first input in the stack
            // All input now in the stack
            errorFile << temp_state.top() << endl;
            temp_state.pop();
            return getToken();
        }

     }else // No input remaining!
        return "";
}

GetToken::read_next_char()
{
    if(!temp_state.empty()){ // there is an input in the stack
        State s = temp_state.top();
        temp_state.pop();
        return s;
    }

    char c = ' ';
    inputFile >> noskipws >> c;
    if( c == -1)
        return inputFile.eof();
    return c;
}

GetToken::~GetToken()
{
    //dtor
}
