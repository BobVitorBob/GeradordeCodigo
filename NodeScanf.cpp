#include "NodeScanf.h"

NodeScanf::NodeScanf(string formatString, NodeVariable *variable) : NodeCommand(CScanf){
    this->formatString = nullptr;
    this->variable = nullptr;
}

NodeScanf::~NodeScanf(){
    delete this;
}

string NodeScanf::getFormatString(){
    return this->formatString;    
}

NodeVariable *NodeScanf::getVariable(){
    return this->variable;
}
