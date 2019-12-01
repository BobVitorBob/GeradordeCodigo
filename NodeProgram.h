#ifndef NODEPROGRAM
#define NODEPROGRAM
#include "Node.h"
#include "NodeSymbolFunction.h"
#include "NodeSymbolVariable.h"
#include "NodeSymbol.h"
class NodeProgram : public Node
{
protected:
    
    NodeSymbol *symbolTable;
    NodeSymbolFunction *functions;

public:
    NodeProgram(NodeSymbolFunction *functions=nullptr, NodeSymbol *symbolTable=nullptr);
    ~NodeProgram();
    NodeSymbolFunction *getFunctions();
    NodeSymbol *getSymbolTable();
    void setNewFunction(NodeSymbolFunction *function);
    void setNewSymbol(NodeSymbol *symbol);
};
#endif