#ifndef NODEFUNCTION
#define NODEFUNCTION
#include "Node.h"
#include "NodeVariable.h"
#include "NodeCommand.h"
#include "NodeSymbol.h"
#include <string>
class NodeFunction : public Node
{
protected:

    string functionName;
    NodeSymbol *symbolTable;
    NodeVariable *param;
    NodeCommand *commands;
    ReturnType returnType;

public:
    NodeFunction(string functionName, NodeVariable *param, NodeSymbol *symbolTable, NodeCommand *commands, ReturnType returnType);
    ~NodeFunction();
    string getFunctionName();
    NodeSymbol *getSymbolTable();
    NodeVariable *getParam();
    ReturnType getReturnType();
    NodeCommand *getCommands();
};
#endif