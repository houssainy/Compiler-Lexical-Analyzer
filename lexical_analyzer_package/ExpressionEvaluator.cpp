#include "ExpressionEvaluator.h"
#include "string.h"
#include <unordered_map>
#include <iostream>
using namespace std;

ExpressionEvaluator::ExpressionEvaluator(SimpsonGraphBuilder *builder)
{
    //ctor
    this->builder = builder;
}
ExpressionEvaluator::ExpressionEvaluator( )
{
    //ctor

}

string ExpressionEvaluator::post_fix_conversion(string exp)
{
    char expr[exp.length()];
    string element="";
    int i=0;
    strcpy(expr, exp.c_str());
    while(i<exp.length())
    {
        if((string(1 , exp[i])!="*")&&
                (string(1 , exp[i])!="+")&&
                (string(1 , exp[i])!=".")&&
                (string(1 , exp[i])!="|")&&
                (string(1 , exp[i])!="(")&&
                (string(1 , exp[i])!=")"))
        {
//input is operand
            operand.push(string(1 , exp[i]));
            i++;
        }
        else
//input is operation
            if((string(1 , exp[i])=="*")||
                    (string(1 , exp[i])=="+")||
                    (string(1 , exp[i])=="("))
            {
                if(string(1 , exp[i])=="(")
                {
                    operation.push(string(1 , exp[i]));
                    i++;
                }
                else
                {
                    operation.push(string(1 , exp[i]));
                    i++;
                }
            }
            else if(string(1 , exp[i])==".")
            {
                if(operation.empty())
                {
                    operation.push(string(1 , exp[i]));
                    i++;
                }
                else
                {
                    if((operation.top()=="*")||(operation.top()=="+"))
                    {
                        element=element +""+operand.top();
                        element=element +""+operation.top();
                        operand.pop();
                        operation.pop();
                        operand.push (element);
                        operation.push (string(1 , exp[i]));
                        element="";
                        i++;
                    }
                    else
                    {
                        operation.push (string(1 , exp[i]));
                        i++;
                    }
                }

            }
            else if(expr[i]=='|')
            {
                if(operation.empty())
                {
                    operation.push(string(1 , exp[i]));
                    i++;
                }
                else
                {
                    if((operation.top()=="*")||(operation.top()=="+"))
                    {

                        element=element +""+operand.top();
                        element=element +""+operation.top();
                        operand.pop();
                        operation.pop();
                        operand.push(element);
                        operation.push(string(1 , exp[i]));
                        element="";
                        i++;
                    }
                    else if ((operation.top()=="."))
                    {
                        element=element +""+operand.top();

                        operand.pop();
                        element=element +""+operand.top();
                        operand.pop();
                        element=element +""+operation.top();
                        operation.pop();
                        operand.push(element);
                        operation.push(string(1 , exp[i]));
                        element="";
                        i++;
                    }
                    else
                    {
                        operation.push(string(1 , exp[i]));
                        i++;
                    }
                }
            }
            else if(string(1 , exp[i])==")")
            {
                if(operation.empty())
                {
                    cout<<"ERROR IN EXP";
                }
                while((operation.top()!="(")&&(!operation.empty())&& (!operand.empty()))
                {
                    if ((operation.top()=="*")||(operation.top()=="+"))
                    {
                        element ="";
                        element=element+""+operand.top()+""+operation.top();
                        operation.pop();
                        operand.pop();
                        operand.push(element);
                        element="";
                    }
                    else if((operation.top()=="|")||(operation.top()=="."))
                    {
                        element=element+""+operand.top();
                        operand.pop();
                        element=element+""+operand.top();
                        element=element+""+operation.top();
                        operand.pop();
                        operation.pop();
                        operand.push(element);
                        element="";
                    }

                }

                operation.pop();
                i++;
            }
    }
    if(operand.empty())
    {
        return NULL;
    }
    if(operation.empty())
    {
        element=operand.top();
        operand.pop();
    }
    else
    {

        while(!operand.empty()&&(!operation.empty()))
        {
            if ((operation.top()=="*")||(operation.top()=="+"))
            {
                element ="";
                element=element+""+operand.top()+""+operation.top();
                operation.pop();
                operand.pop();
                operand.push(element);
                element="";
            }
            else if((operation.top()=="|")||(operation.top()=="."))
            {
                element=element+""+operand.top();
                operand.pop();
                element=element+""+operand.top();
                element=element+""+operation.top();
                operand.pop();
                operation.pop();
                operand.push(element);
                element="";
            }
        }
        element=operand.top();
        while(!operation.empty())
        {
            element=element+""+operation.top();
            operation.pop();


        }

    }
    return element;
}



Graph *ExpressionEvaluator::evaluate(string expr,unordered_map <string,Graph*> *graphs)
{
    string post_fix=post_fix_conversion(expr);
    unordered_map<string,Graph*>::const_iterator itr;
    Graph* g1,*g2;
    char expr_array[post_fix.length()];
    string element="";
    int i=0;
    strcpy(expr_array, post_fix.c_str());
    stack <string> operationS;
    stack<Graph *> operandG;
    for(i=0; i<post_fix.length(); i++)
    {
        if((string(1 , expr_array[i])!="*")&&
                (string(1 , expr_array[i])!="+")&&
                (string(1 , expr_array[i])!=".")&&
                (string(1 , expr_array[i])!="|"))
        {
            itr=graphs->find(string(1,expr_array[i]));
            operandG.push(itr->second);
        }
        else
        {
            if((!operationS.empty())&&(string(1 , expr_array[i])=="*"))
            {
                g1=operandG.top();
                operandG.pop();
                operandG.push(builder->clousure_operation(g1));
            }
            else if((!operationS.empty())&&(string(1 , expr_array[i])=="+"))
            {
                g1=operandG.top();
                operandG.pop();
                operandG.push(builder->positive_clousure_operation(g1));
            }
            else if((!operationS.empty())&&(string(1 , expr_array[i])=="."))
            {
                g1=operandG.top();
                operandG.pop();
                g2=operandG.top();
                operandG.pop();
                operandG.push(builder->and_operation(g1,g2));

            }
            else if((!operationS.empty())&&(string(1 , expr_array[i])=="|"))
            {

                g1=operandG.top();
                operandG.pop();
                g2=operandG.top();
                operandG.pop();
                operandG.push(builder->or_operation(g1,g2));
            }

        }


    }

    return operandG.top();

}



ExpressionEvaluator::~ExpressionEvaluator()
{
    //dtor
}

