#include "NFA_Generator.h"
#include "strings.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include<queue>

NFA_Generator::NFA_Generator(string file_path)
{
    //ctor
    this->file_path = file_path;
    exp_eval = ExpressionEvaluator(&graph_builder);
}

Graph* NFA_Generator::getNFA()
{

    ifstream grammar_file (file_path.c_str());
    string line;

    if (grammar_file.is_open())  // Check if file opened
    {


        while ( getline (grammar_file,line) )
        {
            cout << line << endl;

            if( line.empty() || line[0] == ' '|| line[0] == '\t') // Empty line or white space
                continue;
            else if( line[0] == '{') // Key words
                handle_keyword_graph(line);
            else if(line[0] == '[')
                handle_punctuation_graph(line);
            else // Regular Expression or Definition
                handle_regular_exp_or_def_graph(line);

        }

        grammar_file.close();
        return get_language_graph();
    }
    else   // Error in opening file
    {
        cout << "Unable to open file";
        return NULL;
    }

}

/**
*   Read keyword line from grammerfile and build its graph
*/
void NFA_Generator::handle_keyword_graph(string line)
{
    Graph *temp_graph = NULL;

    // move on the line and construct a graph for each key word
    for(int i = 1 ; i < line.length() ; i++)
    {
        if(line[i] == ' '|| line[i] == '\t')  // white space
        {
            if( temp_graph == NULL ) // White space in the begining of the line like "{ int....}"
                continue;

            // Set last node as acceptance state
            temp_graph->get_end_node()->set_acceptance_state(true);
            temp_graph->get_end_node()->set_token_type("key word");

            if( language_map.find("key_word") != language_map.end() )
            {

                //There is already graph for key words so update the graph only
                Graph *old_graph = language_map.find("key_word")->second;
                language_map["key_word"] = graph_builder.or_operation(old_graph,temp_graph);

            }
            else  // Add new key word key
                language_map.insert(pair<string,Graph*>("key_word", temp_graph));

            temp_graph = NULL; // To start new graph

        }
        else if( line[i] == '}')   // end of key words
        {
            if( temp_graph == NULL)
                break;

            // Set last node as acceptance state
            temp_graph->get_end_node()->set_acceptance_state(true);
            temp_graph->get_end_node()->set_token_type("key word");

            if( language_map.find("key_word") != language_map.end() )
            {

                //There is already graph for key words so update the graph only
                Graph *old_graph = language_map.find("key_word")->second;
                language_map["key_word"] = graph_builder.or_operation(old_graph,temp_graph);

            }
            else  // Add new
                language_map.insert(pair<string,Graph*>("key_word", temp_graph));
            temp_graph = NULL;
            break;
        }
        else   // character
        {
            if( input_map.find(line[i]) == input_map.end() ) // this character not added before
                input_map.insert(pair<char,int>(line[i], input_count++)); // Add new character to input map

            if( temp_graph == NULL )// Build graph for first charachter
                temp_graph = graph_builder.init_graph(string(1,line[i]));
            else // concatenate old graph and new graph of the new character
                temp_graph = graph_builder.and_operation(temp_graph , graph_builder.init_graph(string(1,line[1])));
        }

    }

    delete temp_graph;
}

/**
*   Read paunctuation line from grammerfile and build its graph
*/
void NFA_Generator::handle_punctuation_graph(string line)
{
    Graph * temp_graph = NULL;

    // move on the line and construct a graph for each punctuation
    for(int i = 1 ; i < line.length() ; i++)
    {
        if(line[i] == ' '|| line[i] == '\t') // white space
            continue;
        else if( line[i] == ']') // end of punctuations
            break;
        else  // punctiation
        {

            if( line[i] == 92 /* '\'*/ && i+1 < line.length() && (line[i+1] == ')' || line[i+1] == '(')) //case \( or \)
            {
                temp_graph = graph_builder.init_graph(string(1,line[i+1]));
                i++; //skip ) or (
            }
            else
                temp_graph = graph_builder.init_graph(string(1,line[i]));

            // Set last node as acceptance state
            temp_graph->get_end_node()->set_acceptance_state(true);
            temp_graph->get_end_node()->set_token_type("punctuation");

            // Add new character to input map
            if( input_map.find(line[i]) == input_map.end() ) // this character not added before
                input_map.insert(pair<char,int>(line[i], input_count++));

            if( language_map.find("punctuation") != language_map.end() )
            {
                //There is already graph for punctuations so update the graph only

                Graph *old_graph = language_map.find("punctuation")->second;
                language_map["punctuation"] = graph_builder.or_operation(old_graph, temp_graph);

            }
            else  // Add new
                language_map.insert(pair<string,Graph*>("punctuation", temp_graph));

            temp_graph = NULL;
        }
    }

    delete temp_graph;
}

/**
*   Read Regular expression or deffinition line from grammerfile and build its graph
*/
void NFA_Generator::handle_regular_exp_or_def_graph(string line)
{
    string exp_name;
    int i = 0;

    // skip white spaces in the beggining of the file
    while(i < line.length() && (line[i] == ' ' || line[i] == '\t') )
        i++;

    //build exp_name
    while(i < line.length() && line[i] != ' ' && line[i] != '\t' && line[i] !='=' && line[i] != ':' )
        exp_name = string(exp_name + line[i++]);

    // skip white spaces after exp name
    while(i < line.length() && (line[i] == ' ' || line[i] == '\t') )
        i++;

    if( i < line.length() && (line[i] == '='|| line[i] == ':' ))
    {
        unordered_map<string, Graph*> exp_graphs;
        stringstream exp_string;
        stringstream temp_string;
        char index_char = 'a';

        for(i=i+1 ; i < line.length() ; i++ )
        {
            if( line[i] == ' ' || line[i] == '\t' )
            {
                if( temp_string.str().empty() ) // Spaces
                    continue;

                Graph* temp_graph = build_new_input_graph(temp_string.str());
                if( temp_graph == NULL )//Error
                    return ;

                // create new graph
                exp_graphs.insert(pair<string,Graph*>( string(1,index_char), temp_graph ));
                // Add the chosen char to the expression to be user in evaluation
                exp_string << index_char;
                index_char++;

                temp_string.clear();
                temp_string.str("");

                temp_graph = NULL;
                delete temp_graph;
            }
            else if( temp_string.str() != "\\"&& ( line[i] == '+' || line[i] == '*' || line[i] == '|' || line[i] == '.' || line[i] == '(' || line[i] == ')' ) )  // Operation
            {
                if( !temp_string.str().empty() )
                {

                    Graph* temp_graph = build_new_input_graph(temp_string.str());
                    if( temp_graph == NULL )//Error
                        return ;

                    // create new graph
                    exp_graphs.insert(pair<string,Graph*>( string(1,index_char), temp_graph ));
                    // Add the chosen char to the expression to be user in evaluation
                    exp_string << index_char <<  line[i];
                    index_char++;

                    temp_string.clear();
                    temp_string.str("");


                    temp_graph = NULL;
                    delete temp_graph;
                }
                else
                    exp_string <<  line[i] ;


            }
            else // append character to temp_string to be used as name of key of the map
                temp_string<< line[i];
        }

        if( !temp_string.str().empty() )
        {

            Graph* temp_graph = build_new_input_graph(temp_string.str());
            if( temp_graph == NULL )//Error
                return ;

            exp_graphs.insert(pair<string,Graph*>( string(1,index_char), temp_graph ));
            // Add the chosen char to the expression to be user in evaluation
            exp_string << index_char;
            index_char++;

            temp_string.clear();
            temp_string.str("");


            temp_graph = NULL;
            delete temp_graph;
        }

        //Evaluate the expression
        Graph* result_graph = exp_eval.evaluate(exp_string.str() , &exp_graphs);
        result_graph->get_end_node()->set_acceptance_state(true);
        result_graph->get_end_node()->set_token_type(exp_name);

        // insert new reg expression or deffinition
        language_map.insert(pair<string,Graph*>(exp_name, result_graph));

        result_graph = NULL;
        delete result_graph;
    }
    else
        cout<< "Grammar Error!" << endl;
}

Graph * NFA_Generator::build_new_input_graph(string temp_string)
{
    Graph *temp_graph;
    if( language_map.find(temp_string) != language_map.end())  // diffinition of predefined expression
    {
        temp_graph = copy_graph(language_map.find(temp_string)->second);
    }
    else   // New input
    {
        cout<< temp_string.length() << endl;
        if( temp_string.length() > 1)
        {
            /**
            *   1- Range e.g a-z or 1-9
            *   2- Add or Multiply operation e.g \+ or \*
            *   3- Relational operation e.g \=\= or !\= or > or >\= or < or <\=
            **/
            int i = 0;
            if( temp_string[i] == '\\' || temp_string[i] == '!' ||
                    temp_string[i] == '>' || temp_string[i] == '<')  //case 2 or 3
            {

                if( temp_string[i] == '\\')
                    i++;

                if( input_map.find(temp_string[i]) == input_map.end() ) // this character not added before
                    input_map.insert(pair<char,int>(temp_string[i], input_count++));
                temp_graph = graph_builder.init_graph(string(1,temp_string[i++]));

                for( ; i < temp_string.length() ; i++ )
                {
                    if( temp_string[i] != '\\')
                    {
                        if( input_map.find(temp_string[i]) == input_map.end() ) // this character not added before
                            input_map.insert(pair<char,int>(temp_string[i], input_count++));
                        temp_graph = graph_builder.and_operation(temp_graph , graph_builder.init_graph(string(1,temp_string[i])));
                    }
                }
            }
            else  //Case 1 or error
            {
                temp_graph = graph_builder.init_graph(string(1,temp_string[i++]));

                // skip white spaces after exp name
                while(i < temp_string.length() && (temp_string[i] == ' ' || temp_string[i] == '\t') )
                    i++;

                if( temp_string[i++] != '-')
                {
                    cout<< "Error in Grammar!" <<endl;
                    return NULL;
                }

                // skip white spaces after exp name
                while(i < temp_string.length() && (temp_string[i] == ' ' || temp_string[i] == '\t') )
                    i++;

                for( char c = temp_string[0] + 1  ; c <= temp_string[i] ; c++ )  // Range a-z OR 1-9
                {
                    if( input_map.find(c) == input_map.end() ) // this character not added before
                        input_map.insert(pair<char,int>(c, input_count++));

                    temp_graph = graph_builder.or_operation(temp_graph , graph_builder.init_graph(string(1, c)));
                }
            }

        }
        else   // one char
        {
            if( input_map.find(temp_string[0]) == input_map.end() ) // this character not added before
                input_map.insert(pair<char,int>(temp_string[0], input_count++));
            temp_graph = graph_builder.init_graph(temp_string);
        }
    }
    return temp_graph;
}

Graph *NFA_Generator::get_language_graph()
{
    Graph * language_graph;

    unordered_map<string,Graph*>::const_iterator it = language_map.begin();

    if( it == language_map.end() ) // No graphs has been built!
        return NULL;

    language_graph = it->second;
    it++;
    for ( ; it != language_map.end(); ++it )
    {
        language_graph = graph_builder.or_operation(language_graph , it->second);
    }

    return language_graph;
}

Graph* NFA_Generator::copy_graph(Graph *g)
{
    queue <Node*> q;

    // map of key = node name and value pointer to Node in the new graph
    // if there was a value for the givven node name
    unordered_map<int,Node*> node_holder;
    Graph *new_graph = new Graph();

    // Node of old graph
    Node* temp_node;
    // Children of old graph
    vector<Edge> *children;

    // Node of new graph
    Node *new_temp_node;

    temp_node = g->get_start_node();

    // New start Node
    new_temp_node = new Node();
    new_temp_node->set_node_name();

    new_temp_node->set_acceptance_state(temp_node->is_acceptance_node());
    new_temp_node->set_token_type(temp_node->get_token_type());

    //Set start node of new graph
    new_graph->set_start_node(new_temp_node);

    //Push first node
    q.push(temp_node);
    node_holder.insert(pair<int,Node*>(temp_node->get_node_name(), new_temp_node));

    while(q.size()!=0)
    {
        temp_node = q.front(); // old node
        q.pop();

        new_temp_node = node_holder[temp_node->get_node_name()]; // new graph

        children = temp_node->get_children();
        Node * node;

        for(int i=0; i< children->size(); i++)
        {
            node = (*children)[i].get_end_node(); // children #i

            if( node_holder.find(node->get_node_name()) != node_holder.end() ){ // visited add to new graph only
                new_temp_node->add_child( node_holder[node->get_node_name()] , (*children)[i].get_value());
                continue;
            }

            Node *new_node = new Node();
            new_node->set_node_name();

            new_node->set_acceptance_state(node->is_acceptance_node());
            new_node->set_token_type(node->get_token_type());

            new_temp_node->add_child( new_node , (*children)[i].get_value());

            //Not visited
            q.push(node);
            node_holder.insert(pair<int,Node*>((*children)[i].get_end_node()->get_node_name(), new_node));
        }
    }
    // Set end node
    new_graph->set_end_node(node_holder[g->get_end_node()->get_node_name()]);
    new_graph->get_end_node()->set_acceptance_state(g->get_end_node()->is_acceptance_node());
    new_graph->get_end_node()->set_token_type(g->get_end_node()->get_token_type());

    new_graph->set_graph_size(g->get_graph_size());

    return new_graph;
}

NFA_Generator::~NFA_Generator()
{
    //dtor
}
