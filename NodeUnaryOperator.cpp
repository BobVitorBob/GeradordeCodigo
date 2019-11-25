#include "NodeUnaryOperator.h"

    NodeUnaryOperator::NodeUnaryOperator(UnaryOpType unaryOpType, ReturnType returnType) : NodeOperator((OpId) unaryOp, returnType){
        this->son = nullptr;
        this->unaryOpType = unaryOpType;
    }

    NodeUnaryOperator::~NodeUnaryOperator(){
        delete this;
    }

    NodeOperator *NodeUnaryOperator::getSon(){
        return this->son;
    }

    UnaryOpType NodeUnaryOperator::getUnaryOpType(){
        return this->unaryOpType;
    }
