#include "NodeSymbolConstant.h"

    NodeSymbolConstant::NodeSymbolConstant(string name, int value) : NodeSymbol(SConstant, name){
        this->value = value;
    }

    NodeSymbolConstant::~NodeSymbolConstant(){

    }

    int NodeSymbolConstant::getValue(){
        return this->value;
    }

    void NodeSymbolConstant::setValue(int value){
        this->value = value;
    }
