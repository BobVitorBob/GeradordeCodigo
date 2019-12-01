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
