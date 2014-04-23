#include "NFA_Generator.h"
#include "strings.h"
#include <stdio.h>
#include <vector>
#include <iostream>

NFA_Generator::NFA_Generator(string file_path)
{
    //ctor
}

void NFA_Generator::setAutomata(Graph* graph){
    Node start_node= Node();
    //start_node->add_child(graph.get_start_node())
    this->file_path = file_path;
    exp_eval = ExpressionEvaluator(&graph_builder);
}

Graph* NFA_Generator::getAutomata(){

    ifstream grammar_file (file_path.c_str());
    string line;

    if (grammar_file.is_open()){ // Check if file opened


        while ( getline (grammar_file,line) ){
            cout << line << endl;

            if( line.empty()) // Empty line
                continue;
            else if(line[0] == ' '|| line[0] == '\t')
                continue;
            else if( line[0] == '{'){ // Key words
                Graph *graph = NULL;

                // move on the line and construct a graph for each key word
                for(int i = 1 ; i < line.length() ; i++){
                    if(line[i] == ' '|| line[i] == '\t') {// white space
                        if( graph == NULL ) // White space in the begining of the line like "{ int....}"
                            continue;

                        if( language_map.find("key_word") != language_map.end() ){

                            //There is already graph for key words so update the graph only
                            Graph *old_graph = language_map.find("key_word")->second;
                            language_map["key_word"] = graph_builder.or_operation(old_graph,graph);

                        }else // Add new key word key
                            language_map.insert(pair<string,Graph*>("key_word", graph));

                        graph = NULL; // To start new graph

                    }else if( line[i] == '}'){ // end of key words
                        if( graph == NULL)
                            break;
                        if( language_map.find("key_word") != language_map.end() ){

                            //There is already graph for key words so update the graph only
                            Graph *old_graph = language_map.find("key_word")->second;
                            language_map["key_word"] = graph_builder.or_operation(old_graph,graph);

                        }else // Add new
                            language_map.insert(pair<string,Graph*>("key_word", graph));

                        break;
                    }else{ // character
                        if( graph == NULL )// Build graph for first charachter
                            graph = graph_builder.init_graph(string(1,line[i]));
                        else // concatenate old graph and new graph of the new character
                            graph = graph_builder.and_operation(graph , graph_builder.init_graph(string(1,line[1])));
                    }

                }

                delete graph;
            }else if(line[0] == '['){
                Graph * temp_graph = NULL;

                // move on the line and construct a graph for each punctuation
                for(int i = 1 ; i < line.length() ; i++){
                    if(line[i] == ' '|| line[i] == '\t') // white space
                        continue;
                    else if( line[i] == ']') // end of punctuations
                        break;
                    else{ // punctiation

                        if( line[i] == '\\'){//case \( or \)
                            temp_graph = graph_builder.init_graph(string(line , i , i+1));
                            i++;
                        }else
                            temp_graph = graph_builder.init_graph(string(1,line[i]));

                        if( language_map.find("punctuation") != language_map.end() ){
                            //There is already graph for punctuations so update the graph only

                            Graph *old_graph = language_map.find("punctuation")->second;
                            language_map["punctuation"] = graph_builder.or_operation(old_graph, temp_graph);

                        }else // Add new
                            language_map.insert(pair<string,Graph*>("punctuation", temp_graph));

                        temp_graph = NULL;
                    }
                }

                delete temp_graph;
            }else{ // Regular Expression or Definition
                string exp_name;
                int i = 0;

                // skip white spaces in the beggining of the file
                while(i < line.length() && (line[i] == ' ' || line[i] == '\t') )
                    i++;

                //build exp_name
                while(i < line.length() && (line[i] == ' ' || line[i] == '\t' || line[i] =='=' || line[i] == ':') )
                    exp_name = string(exp_name + line[i++]);

                // skip white spaces after exp name
                while(i < line.length() && (line[i] == ' ' || line[i] == '\t' || line[i] =='=' || line[i] == ':' ) )
                    i++;

                if( line[i] < line.length() && (line[i] == '='|| line[i] == ':' )){
                    unordered_map<string, Graph*> exp_graphs;
                    string exp_string;
                    string temp_string;
                    char index_char = 'a';

                    for(; i < line.length() ; i++ ){
                        if( line[i] == ' ' || line[i] == '\t'){
                            if( temp_string.empty() ) // Spaces
                                continue;

                            // create new graph
                            exp_graphs.insert(pair<string,Graph*>( string(1,index_char), graph_builder.init_graph(exp_string)));
                            // Add the chosen char to the expression to be user in evaluation
                            exp_string = string(exp_string + index_char);
                            index_char++;

                            temp_string = string("");

                        }else{
                            if( line[i] == '+' || line[i] == '*' || line[i] == '|' || line[i] == '.'){ // Operation
                                exp_string = string(exp_string + line[i]);
                            }else// append character
                                temp_string = string(temp_string + line[i]);
                        }
                    }
                    exp_eval.evaluate(exp_string);
                }else{
                    cout<< "Grammar Error!" << endl;
                    continue;
                }

            }
        }
        grammar_file.close();

        return get_language_graph();
    }else{ // Error in opening file
        cout << "Unable to open file";
        return NULL;
    }

}

Graph *NFA_Generator::get_language_graph(){
    Graph * language_graph;

    unordered_map<string,Graph*>::const_iterator it = language_map.begin();
    language_graph = it->second;

    it++;
    for ( ; it != language_map.end(); ++it ){
        language_graph = graph_builder.or_operation(language_graph , it->second);

        delete it->second;
    }

    return language_graph;
}
NFA_Generator::~NFA_Generator()
{
    //dtor
}
