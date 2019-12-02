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

    NodeSymbol *symbolTable;
    NodeSymbol *paramList;
    NodeCommand *commands;
    ReturnType returnType;
    int pointerLvl;

public:
    NodeSymbolFunction(string name=string(""), NodeSymbol *symbolTable=nullptr, NodeCommand *commands=nullptr, ReturnType returnType=RVoid);
    ~NodeSymbolFunction();
    NodeSymbol *getSymbolTable();
    NodeSymbol *getParamList();
    ReturnType getReturnType();
    NodeCommand *getCommands();
    int getPointerLvl();
    void setPointerLvl(int pointerLvl);
    void setReturnType(ReturnType RType);
    void addNewSymbol(NodeSymbol *newSymbol);
    void addNewParam(NodeSymbol *newParam);
    void addNewCommand(NodeCommand *newCommand);
};
#endif