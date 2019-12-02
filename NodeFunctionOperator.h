#ifndef NODEFUNCTIONOPERATOR
#define NODEFUNCTIONOPERATOR
#include "NodeOperator.h"
class NodeFunctionOperator : public NodeOperator
{
protected:
    void *Function;
public:
    NodeFunctionOperator(void *Function, ReturnType returnType);
    ~NodeFunctionOperator();
    void *getFunction();
};
#endif