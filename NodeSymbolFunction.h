#ifndef NODESYMBOLFUNCTION
#define NODESYMBOLFUNCTION
#include "Node.h"
#include "NodeSymbolVariable.h"
#include "NodeCommand.h"
#include "NodeSymbol.h"
#include <string>
class NodeSymbolFunction : public NodeSymbol
{
protected:

    string functionName;
    NodeSymbol *symbolTable;
    NodeCommand *commands;
    ReturnType returnType;
    int pointerLvl;

public:
    NodeSymbolFunction(string functionName=string(""), NodeSymbol *symbolTable=nullptr, NodeCommand *commands=nullptr, ReturnType returnType=RVoid);
    ~NodeSymbolFunction();
    string getFunctionName();
    NodeSymbol *getSymbolTable();
    ReturnType getReturnType();
    NodeCommand *getCommands();
    int getPointerLvl();
    void setPointerLvl(int pointerLvl);
    void setFunctionName(string functionName);
    void setReturnType(ReturnType RType);
    void addNewSymbol(NodeSymbol *newSymbol);
    void addNewCommand(NodeCommand *newCommand);
};
#endif