#include "NodeReturn.h"

NodeReturn::NodeReturn(NodeExpression *returnValue) : NodeCommand((CommandType) CReturn){
    this->returnValue = returnValue;
}

NodeReturn::~NodeReturn(){
    delete this;
}

NodeExpression *NodeReturn::getReturnValue(){
    return this->returnValue;
}