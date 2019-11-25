#include "NodeVariable.h"

    NodeVariable::NodeVariable(string name, void *value, VarType varType) : Node((NodeType) NVariable){
        this->name = name;
        this->value = value;
        this->varType = varType;
    }

    NodeVariable::~NodeVariable(){
        delete this;
    }

    string NodeVariable::getName(){
        return this->name;
    }

    VarType NodeVariable::getVarType(){
        return this->varType;
    }

    void *NodeVariable::getValue(){
        return this->value;
    }
