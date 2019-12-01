#include "NodeSymbolVariable.h"

    NodeSymbolVariable::NodeSymbolVariable(string name, void *value, ReturnType varType, int pointerLvl, vector<int> arrayDimension) : NodeSymbol(SVariable, name){
        this->value = value;
        this->varType = varType;
        this->pointerLvl = pointerLvl;
        this->arrayDimension = arrayDimension;
    }

    NodeSymbolVariable::~NodeSymbolVariable(){
        delete this;
    }

    string NodeSymbolVariable::getName(){
        return this->name;
    }

    ReturnType NodeSymbolVariable::getVarType(){
        return this->varType;
    }

    void *NodeSymbolVariable::getValue(){
        return this->value;
    }

    int NodeSymbolVariable::getPointerLvl(){
        return this->pointerLvl;
    }

    int NodeSymbolVariable::getArrayDimension(){
        return this->arrayDimension.size();
    }

    int NodeSymbolVariable::getArraySize(int i){
        return this->arrayDimension[i];
    }

    void NodeSymbolVariable::setPointerLvl(int pointerLvl){
        this->pointerLvl = pointerLvl;
    }

    void NodeSymbolVariable::setArrayDimension(vector<int>){
        this->arrayDimension = arrayDimension;
    }


    void NodeSymbolVariable::setName(string name){
        this->name = name;
    }

    void NodeSymbolVariable::setVarType(ReturnType varType){
        this->varType = varType;
    }

    void NodeSymbolVariable::setValue(void *value){
        this->value = value;
    }

