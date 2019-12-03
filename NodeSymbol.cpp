#include "NodeSymbol.h"

    NodeSymbol::NodeSymbol(SymbolType symbolType, string name) : Node(NSymbol){
        this->symbolType = symbolType;
        this->name = name;
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

    void NodeSymbol::setName(string name){
        this->name = name;
    }
    
    void NodeSymbol::setSymbolType(SymbolType symbolType){
        this->symbolType = symbolType;
    }
