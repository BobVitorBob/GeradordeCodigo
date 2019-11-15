#include "Node.h"
class NodeSymbolTable : Node
{
protected:
    Node *symbolList;
public:
    NodeSymbolTable();
    ~NodeSymbolTable();
    Node *getSymbolList();
};