#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeReturn : NodeCommand
{
protected:
    NodeExpression *returnValue;
public:
    NodeReturn();
    ~NodeReturn();
    NodeExpression *getReturnValue();
};