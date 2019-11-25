#include "NodeFunction.h"

    NodeFunction::NodeFunction(string functionName, NodeVariable *param, NodeSymbol *symbolTable, NodeCommand *commands, ReturnType returnType) : Node((NodeType) NFunction){
        this->functionName = functionName;
        this->returnType = returnType;
        this->symbolTable = symbolTable;
        this->param = param;
        this->commands = commands;
    }

    NodeFunction::~NodeFunction(){
        delete this;
    }

    string NodeFunction::getFunctionName(){
        return this->functionName;
    }

    NodeSymbol *NodeFunction::getSymbolTable(){
        return this->symbolTable;
    }

    NodeVariable *NodeFunction::getParam(){
        return this->param;
    }

    ReturnType NodeFunction::getReturnType(){
        return this->returnType;
    }

    NodeCommand *NodeFunction::getCommands(){
        return this->commands;
    }
