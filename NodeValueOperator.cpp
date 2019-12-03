#include "NodeValueOperator.h"

    NodeValueOperator::NodeValueOperator(void *value, ReturnType returnType) : NodeOperator((OpId) trueValue, returnType){
        this->value = value;
    }

    NodeValueOperator::~NodeValueOperator(){
        delete this;
    }

    void *NodeValueOperator::getValue(){
        return this->value;   
    }
