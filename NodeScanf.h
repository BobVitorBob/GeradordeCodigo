#ifndef NODESCANF
#define NODESCANF
#include "NodeCommand.h"
#include "NodeVariable.h"
#include <string>
class NodeScanf : public NodeCommand
{
protected:
    string formatString;

    NodeVariable *variable;
public:
    NodeScanf(string formatString, NodeVariable *variable);
    ~NodeScanf();
    string getFormatString();
    NodeVariable *getVariable();
};
#endif