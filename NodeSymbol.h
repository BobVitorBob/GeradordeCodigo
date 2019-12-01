#ifndef NODESYMBOL
#define NODESYMBOL
#include "Node.h"
#include <string>
enum SymbolType{
    SConstant,
    SVariable,
    SFunction
};

class NodeSymbol : public Node
{
protected:
    SymbolType symbolType;
    string name;
public:
    NodeSymbol(SymbolType symbolType, string name);
    ~NodeSymbol();
    SymbolType getSymbolType();
    string getName();
};
#endif