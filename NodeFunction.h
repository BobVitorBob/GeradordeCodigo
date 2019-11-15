#include "Node.h"
#include "NodeSymbolTable.h"
#include "NodeVariable.h"
#include "NodeCommand.h"
class NodeFunction : Node
{
protected:
    
    NodeSymbolTable *symbolTable;
    NodeVariable *param;
    int returnType;
    NodeCommand *commands;

public:
    NodeFunction();
    ~NodeFunction();

    NodeSymbolTable *getSymbolTable();
    NodeVariable *getParam();
    int getReturnType();
    NodeCommand *getCommands();
};