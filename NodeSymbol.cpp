#include "NodeSymbol.h"

    NodeSymbol::NodeSymbol(SymbolType symbolType, string name, void *value, ReturnType returnType) : Node(NSymbol){
        this->symbolType = symbolType;
        this->name = name;
        this->value = value;
        this->returnType = returnType;
    }

    NodeSymbol::~NodeSymbol(){
        delete this;
    }

    SymbolType NodeSymbol::getSymbolType(){
        return this->symbolType;
    }

    string NodeSymbol::getName(){
        return this->name;
    }

    void *NodeSymbol::getValue(){
        return this->value;
    }

    ReturnType NodeSymbol::getReturnType(){
        return this->returnType;
    }
