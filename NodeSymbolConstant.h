#include "NodeSymbol.h"
class NodeSymbolConstant : public NodeSymbol
{
protected:
    int value;
public:
    NodeSymbolConstant(string name, int value);
    ~NodeSymbolConstant();
    int getValue();
    void setValue(int value);
};