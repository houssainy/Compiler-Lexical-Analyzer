#include "NFA_Generator.h"

NFA_Generator::NFA_Generator(string file_path)
{
    //ctor
    this->file_path = file_path;
}

Graph* NFA_Generator::getAutomata(){
    string line;
    ifstream grammar_file (file_path.c_str());

    if (grammar_file.is_open()){ // Check if file opened
        while ( getline (grammar_file,line) ){
            cout << line << endl;

            if( line.empty()) // Empty line
                continue;
            else if( line[0] == '{'){ // Key words
                Graph *graph = NULL;
                unordered_map<string,Graph*>::const_iterator temp_iterator;

                // move on the line and construct a graph for each key word
                for(int i = 1 ; i < line.length() ; i++){
                    if(line[i] == ' ') {// white space
                        if( graph == NULL ) // White space in the begining of the line like "{ int....}"
                            continue;

                        if( reg_ex_map.find("key_word") != reg_ex_map.end() ){

                            //There is already graph for key words so update the graph only
                            Graph *old_graph = reg_ex_map.find("key_word")->second;
                            reg_ex_map["key_word"] = graph_builder.or_operation(old_graph,graph);

                        }else // Add new key word key
                            reg_ex_map.insert(pair<string,Graph*>("key_word", graph));

                        graph = NULL; // To start new graph

                    }else if( line[i] == '}'){ // end of key words
                        if( graph == NULL)
                            break;
                        if( reg_ex_map.find("key_word") != reg_ex_map.end() ){

                            //There is already graph for key words so update the graph only
                            Graph *old_graph = reg_ex_map.find("key_word")->second;
                            reg_ex_map["key_word"] = graph_builder.or_operation(old_graph,graph);

                        }else // Add new
                            reg_ex_map.insert(pair<string,Graph*>("key_word", graph));

                        delete graph; // unused object in this state
                        break;
                    }else{ // character
                        if( graph != NULL )// Build graph for first charachter
                                graph = graph_builder.init_graph(string(1,line[1]));
                        else // concatenate old graph and new graph of the new character
                            graph = graph_builder.and_operation(graph , graph_builder.init_graph(string(1,line[1])));
                    }

                }
            }else if(line[0] == '['){

            }else{ // Regular Expression or Definition

            }
        }
        grammar_file.close();

        return NULL;
    }else{ // Error in opening file
        cout << "Unable to open file";
        return NULL;
    }

}

NFA_Generator::~NFA_Generator()
{
    //dtor
}
