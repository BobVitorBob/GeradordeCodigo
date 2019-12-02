#include "NodeDoWhile.h"

NodeDoWhile::NodeDoWhile() : NodeCommand((CommandType) CDo_while){
    this->commands = nullptr;
    this->stopCondition = nullptr;
}

NodeDoWhile::~NodeDoWhile(){
    delete this;
}

NodeCommand *NodeDoWhile::getCommands(){
    return this->commands;
}

NodeExpression *NodeDoWhile::getStopCondition(){
    return this->stopCondition;
}

void NodeDoWhile::addCommand(NodeCommand *newCommand){
    NodeCommand *next = this->commands;
    if (next != nullptr) while (next->getNext() != nullptr)
    {
        next = (NodeCommand*) next->getNext();
    }else{
        this->commands = newCommand;
        return;
    }
    next->setNext(newCommand);
}

void NodeDoWhile::setStopCondition(NodeExpression *stopCondition){
    this->stopCondition = stopCondition;
}