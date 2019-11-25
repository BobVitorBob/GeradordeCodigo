#include "NodeExit.h"

NodeExit::NodeExit(NodeExpression *exitValue) : NodeCommand((CommandType) CExit){
    this->exitValue = exitValue;
}

NodeExit::~NodeExit(){
    delete this;
}

NodeExpression *NodeExit::getExitValue(){
    return this->exitValue;
}