#ifndef NODESCANF
#define NODESCANF
#include "NodeCommand.h"
#include "NodeSymbolVariable.h"
#include <string>
class NodeScanf : public NodeCommand
{
protected:
    string formatString;

    NodeSymbolVariable *variable;
public:
    NodeScanf(string formatString, NodeSymbolVariable *variable);
    ~NodeScanf();
    string getFormatString();
    NodeSymbolVariable *getVariable();
};
#endif