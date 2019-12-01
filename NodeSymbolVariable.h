#ifndef NODESYMBOLVARIABLE
#define NODESYMBOLVARIABLE
#include "NodeSymbol.h"
#include <string>
#include <vector>

class NodeSymbolVariable : public NodeSymbol
{
protected:

    string name;
    ReturnType varType;
    void *value;
    int pointerLvl;
    vector<int> arrayDimension;

public:
    NodeSymbolVariable(string name=string(""), void *value=nullptr, ReturnType varType=RVoid, int pointerLvl=0, vector<int> arrayDimension=vector<int>());
    ~NodeSymbolVariable();
    string getName();
    ReturnType getVarType();
    void *getValue();
    int getPointerLvl();
    int getArrayDimension();
    int getArraySize(int i);
    void setPointerLvl(int pointerLvl);
    void setArrayDimension(vector<int>);
    void setName(string name);
    void setVarType(ReturnType varType);
    void setValue(void *value);
};
#endif