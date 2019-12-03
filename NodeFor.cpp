#include "NodeFor.h"

NodeFor::NodeFor() : NodeCommand((CommandType) CFor){
    this->startOfLoop = nullptr;
    this->endOfIteration = nullptr;
    this->stopCondition = nullptr;
    this->forCode = nullptr;
}

NodeFor::~NodeFor(){
    delete this;
}

NodeExpression *NodeFor::getStartOfLoop(){
    return this->startOfLoop;
}

NodeExpression *NodeFor::getStopCondition(){
    return this->stopCondition;
}

NodeExpression *NodeFor::getEndOfIteration(){
    return this->endOfIteration;
}

NodeCommand *NodeFor::getForCode(){
    return this->forCode;
}