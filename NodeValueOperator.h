#ifndef NODEVALUEOPERATOR
#define NODEVALUEOPERATOR
#include "NodeOperator.h"
class NodeValueOperator : public NodeOperator
{
protected:
    void *value;
public:
    NodeValueOperator(void *value, ReturnType returnType);
    ~NodeValueOperator();
    void *getValue();
};
#endif