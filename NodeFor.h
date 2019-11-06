#include "Node.h"
#include "NodeExpression.h"
class NodeFor
{
private:

protected:

    NodeExpression *NodeStartOfLoop;

    NodeExpression *NodeStopCondition;

    NodeExpression *NodeEndOfIteration;

    Node *NodeForCode;

public:
    NodeFor();
    ~NodeFor();
};