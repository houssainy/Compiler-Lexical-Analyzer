#include "NFA_Generator.h"

NFA_Generator::NFA_Generator(string file_name)
{
this->file_name=file_name;
    //ctor
}
vector <string>* NFA_Generator::read_File(string file_name);
        vector <string> NFA_Generator::*get_reguler_exp(){
        return this->expression;
        }
        vector <string> NFA_Generator::*get_reguler_difi(){
        return this->difinition;
        }
        Graph* NFA_Generator:: get_evaluation(string exp){

        }


NFA_Generator::~NFA_Generator()
{
    //dtor
}
