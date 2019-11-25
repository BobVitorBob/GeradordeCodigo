#ifndef NODEPROGRAM
#define NODEPROGRAM
#include "Node.h"
#include "NodeFunction.h"
#include "NodeVariable.h"
#include "NodeSymbol.h"
class NodeProgram : public Node
{
protected:
    
    NodeSymbol *symbolTable;
    NodeFunction *functions;

public:
    NodeProgram(NodeFunction *functions, NodeSymbol *symbolTable);
    ~NodeProgram();
    NodeFunction *getFunctions();
    NodeSymbol *getSymbolTable();
};
#endif