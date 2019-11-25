#ifndef NODERETURN
#define NODERETURN
#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeReturn : public NodeCommand
{
protected:
    NodeExpression *returnValue;
public:
    NodeReturn(NodeExpression *returnValue);
    ~NodeReturn();
    NodeExpression *getReturnValue();
};
#endif