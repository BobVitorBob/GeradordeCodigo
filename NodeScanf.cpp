#include "NodeScanf.h"

NodeScanf::NodeScanf(string formatString, NodeSymbolVariable *variable) : NodeCommand(CScanf){
    this->formatString = nullptr;
    this->variable = nullptr;
}

NodeScanf::~NodeScanf(){
    delete this;
}

string NodeScanf::getFormatString(){
    return this->formatString;    
}

NodeSymbolVariable *NodeScanf::getVariable(){
    return this->variable;
}
