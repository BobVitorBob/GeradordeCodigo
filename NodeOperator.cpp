#include "NodeOperator.h"

    NodeOperator::NodeOperator(OpId opId, ReturnType returnType) : Node(NOperator){
        this->opId = opId;
        this->returnType = returnType;
    }

    NodeOperator::~NodeOperator(){
        delete this;
    }

    OpId NodeOperator::getOpId(){
        return this->opId;
    }

    ReturnType NodeOperator::getReturnType(){
        return this->returnType;
    }
