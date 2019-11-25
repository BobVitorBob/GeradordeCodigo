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
    void *value;
    ReturnType returnType;
public:
    NodeSymbol(SymbolType symbolType, string name, void *value, ReturnType returnType);
    ~NodeSymbol();
    SymbolType getSymbolType();
    string getName();
    void *getValue();
    ReturnType getReturnType();
};
#endif