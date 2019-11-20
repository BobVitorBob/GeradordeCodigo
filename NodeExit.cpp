#include "NodeExit.h"

NodeExit::NodeExit(CommandType commandType, NodeExpression *exitValue){
    this->commandType = commandType;
    this->exitValue = exitValue;
}

NodeExit::~NodeExit(){
    delete this;
}

NodeExpression *NodeExit::getExitValue(){
    return this->exitValue;
}