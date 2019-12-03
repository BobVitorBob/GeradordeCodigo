#include "NodeWhile.h"

NodeWhile::NodeWhile(NodeCommand *commands=nullptr, NodeExpression *stopCondition=nullptr) : NodeCommand((CommandType) CWhile){
    this->commands = commands;
    this->stopCondition = stopCondition;
}

NodeWhile::~NodeWhile(){
    delete this;
}

NodeCommand *NodeWhile::getCommands(){
    return this->commands;
}

NodeCommand *NodeWhile::getStopCondition(){
    return this->stopCondition;
}
