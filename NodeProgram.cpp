#include "NodeProgram.h"

    NodeProgram::NodeProgram(NodeSymbolFunction *functions, NodeSymbol *symbolTable) : Node((NodeType) NProgram){
        this->symbolTable = symbolTable;
        this->functions = functions;
    }

    NodeProgram::~NodeProgram(){
        delete this;
    }

    NodeSymbolFunction *NodeProgram::getFunctions(){
        return this->functions;
    }

    NodeSymbol *NodeProgram::getSymbolTable(){
        return this->symbolTable;
    }

    void NodeProgram::setNewFunction(NodeSymbolFunction *function){
        NodeSymbolFunction *next = this->functions;
        if (next != nullptr) while (next->getNext() != nullptr)
        {
            next = (NodeSymbolFunction*) next->getNext();
        }else{
            this->functions = function;
            return;
        }
        next->setNext(function);
    }

    void NodeProgram::setNewSymbol(NodeSymbol *symbol){
        NodeSymbol *next = this->symbolTable;
        if (next != nullptr) while (next->getNext() != nullptr)
        {
            next = (NodeSymbol*) next->getNext();
        }else{
            this->symbolTable = symbol;
            return;
        }
        next->setNext(symbol);
    }
