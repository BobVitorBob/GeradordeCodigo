#include "NodeBinaryOperator.h"

NodeBinaryOperator::NodeBinaryOperator(BinaryOpType binaryOpType, ReturnType returnType) : NodeOperator(binaryOp, returnType){
    this->leftSon = nullptr;
    this->rightSon = nullptr;
    this->binaryOpType = binaryOpType;
}

NodeBinaryOperator::~NodeBinaryOperator(){
    delete this;
}

NodeOperator *NodeBinaryOperator::getLeftSon(){
    return this->leftSon;
}

NodeOperator *NodeBinaryOperator::getRightSon(){
    return this->rightSon;
}

void NodeBinaryOperator::setLeftSon(NodeOperator *leftSon){
    this->leftSon = leftSon;
}

void NodeBinaryOperator::setRightSon(NodeOperator *rightSon){
    this->rightSon = rightSon;
}

BinaryOpType NodeBinaryOperator::getBinaryOpType(){
    return this->binaryOpType;
}