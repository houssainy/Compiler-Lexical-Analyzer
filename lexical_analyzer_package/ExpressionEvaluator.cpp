#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(SimpsonGraphBuilder *builder)
{
    //ctor
    this->builder = builder;
}

ExpressionEvaluator::ExpressionEvaluator(){}

Graph *ExpressionEvaluator::evaluate(string expr /*, hash map*/){
    return NULL;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
    //dtor
}
