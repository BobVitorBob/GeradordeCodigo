#include "NodeDoWhile.h"

NodeDoWhile::NodeDoWhile(CommandType CommandType){
    this->commandType = commandType;
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

void NodeDoWhile::setCommands(NodeCommand *commands){
    this->commands = commands;
}

void NodeDoWhile::setStopCondition(NodeExpression *stopCondition){
    this->stopCondition = stopCondition;
}