#include "NodeBinaryOperator.h"

BinaryNodeOperator::BinaryNodeOperator(OpId opId, OpType opType, int returnType){

    this->next = nullptr;
    this->leftSon = nullptr;
    this->rightSon = nullptr;
    this->opId = opId;
    this->opType = opType;
    this->returnType = returnType;
}

BinaryNodeOperator::~BinaryNodeOperator(){
    delete this;
}

NodeOperator *BinaryNodeOperator::getLeftSon(){
    return this->leftSon;
}

NodeOperator *BinaryNodeOperator::getRightSon(){
    return this->rightSon;
}

void BinaryNodeOperator::setLeftSon(NodeOperator *leftSon){
    this->leftSon = leftSon;
}

void BinaryNodeOperator::setRightSon(NodeOperator *rightSon){
    this->rightSon = rightSon;
}

OpType BinaryNodeOperator::getOpType(){
    return this->opType;
}