#ifndef NODEVARIABLE
#define NODEVARIABLE
#include "Node.h"
#include <string>
enum VarType{
    VInt,
    VChar,
    VPointer
};

class NodeVariable : public Node
{
protected:

    string name;
    VarType varType;
    void *value;

public:
    NodeVariable(string name, void *value, VarType varType);
    ~NodeVariable();
    string getName();
    VarType getVarType();
    void *getValue();
};
#endif