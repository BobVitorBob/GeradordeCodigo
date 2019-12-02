#include "NodeSymbolFunction.h"

    NodeSymbolFunction::NodeSymbolFunction(string name, NodeSymbol *symbolTable, NodeCommand *commands, ReturnType returnType) : NodeSymbol(SFunction, name){
        
        this->returnType = returnType;
        
        this->symbolTable = symbolTable;
        
        this->commands = commands;
    }

    NodeSymbolFunction::~NodeSymbolFunction(){
        delete this;
    }

    NodeSymbol *NodeSymbolFunction::getSymbolTable(){
        return this->symbolTable;
    }

    NodeSymbol *NodeSymbolFunction::getParamList(){
        return this->paramList;
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

    void NodeSymbolFunction::addNewParam(NodeSymbol *newParam){
        NodeSymbol *next = this->paramList;
        if (next != nullptr) while (next->getNext() != nullptr)
        {
            next = (NodeSymbol*) next->getNext();
        }else{
            this->paramList = newParam;
            return;
        }
        next->setNext(newParam);
    }