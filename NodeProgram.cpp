#include "NodeProgram.h"

    NodeProgram::NodeProgram(NodeFunction *functions, NodeSymbol *symbolTable) : Node((NodeType) NProgram){
        this->symbolTable = symbolTable;
        this->functions = functions;
    }

    NodeProgram::~NodeProgram(){
        delete this;
    }

    NodeFunction *NodeProgram::getFunctions(){
        return this->functions;
    }

    NodeSymbol *NodeProgram::getSymbolTable(){
        return this->symbolTable;
    }
