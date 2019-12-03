#include "NodeBinaryOperator.h"

NodeBinaryOperator::NodeBinaryOperator(BinaryOpType binaryOpType, ReturnType returnType) : NodeOperator(binaryOp, returnType){
    this->leftSon = nullptr;
    this->rightSon = nullptr;
    this->binaryOpType = binaryOpType;
}

NodeBinaryOperator::~NodeBinaryOperator(){
    delete this;
}

NodeExpression *NodeBinaryOperator::getLeftSon(){
    return this->leftSon;
}

NodeExpression *NodeBinaryOperator::getRightSon(){
    return this->rightSon;
}

void NodeBinaryOperator::setLeftSon(NodeExpression *leftSon){
    this->leftSon = leftSon;
}

void NodeBinaryOperator::setRightSon(NodeExpression *rightSon){
    this->rightSon = rightSon;
}

BinaryOpType NodeBinaryOperator::getBinaryOpType(){
    return this->binaryOpType;
}