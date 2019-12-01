#include "NodeSymbolFunction.h"

    NodeSymbolFunction::NodeSymbolFunction(string functionName, NodeSymbol *symbolTable, NodeCommand *commands, ReturnType returnType) : NodeSymbol(SFunction, functionName){
        printf("Got here!\n");
        this->functionName = functionName;
        printf("Got here!\n");
        this->returnType = returnType;
        printf("Got here!\n");
        this->symbolTable = symbolTable;
        printf("Got here!\n");
        this->commands = commands;
    }

    NodeSymbolFunction::~NodeSymbolFunction(){
        delete this;
    }

    string NodeSymbolFunction::getFunctionName(){
        return this->functionName;
    }

    NodeSymbol *NodeSymbolFunction::getSymbolTable(){
        return this->symbolTable;
    }

    ReturnType NodeSymbolFunction::getReturnType(){
        return this->returnType;
    }

    NodeCommand *NodeSymbolFunction::getCommands(){
        return this->commands;
    }

    int NodeSymbolFunction::getPointerLvl(){
        return this->pointerLvl;
    }

    void NodeSymbolFunction::setPointerLvl(int pointerLvl){
        this->pointerLvl = pointerLvl;
    }


    void NodeSymbolFunction::setFunctionName(string functionName){
        this->functionName = functionName;
    }

    void NodeSymbolFunction::setReturnType(ReturnType RType){
        this->returnType = RType;
    }

    void NodeSymbolFunction::addNewSymbol(NodeSymbol *newSymbol){
        NodeSymbol *next = this->symbolTable;
        if (next != nullptr) while (next->getNext() != nullptr)
        {
            next = (NodeSymbol*) next->getNext();
        }else{
            this->symbolTable = newSymbol;
            return;
        }
        next->setNext(newSymbol);
    }

    void NodeSymbolFunction::addNewCommand(NodeCommand *newCommand){
        NodeCommand *next = this->commands;
        if (next != nullptr) while (next->getNext() != nullptr)
        {
            next = (NodeCommand*) next->getNext();
        }else{
            this->commands = newCommand;
            return;
        }
        next->setNext(newCommand);
    }