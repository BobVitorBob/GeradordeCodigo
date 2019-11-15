#include "Node.h"
#include "NodeFunction.h"
#include "NodeSymbolTable.h"
class NodeProgram : Node
{
protected:
    
    NodeSymbolTable *symbolTable;
    NodeFunction *functions;

public:
    NodeProgram();
    ~NodeProgram();
    NodeFunction *getFunctions();
    NodeSymbolTable *getSymbolTable();
};