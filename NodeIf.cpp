#include "NodeIf.h"
    NodeIf::NodeIf() : NodeCommand((CommandType) CIf){
        this->conditional = nullptr;
        this->then = nullptr;
        this->else_ = nullptr;
    }
    
    NodeIf::~NodeIf(){
        delete this;
    }
    
    NodeExpression *NodeIf::getConditional(){
        return this-> conditional;
    }

    NodeCommand *NodeIf::getThen(){
        return this-> then;
    }

    NodeCommand *NodeIf::getElse(){
        return this-> else_;
    }