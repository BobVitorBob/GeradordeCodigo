#include "Node.h"
#include "NodeOperator.h"
#include "NodeCommand.h"
class NodeExpression : NodeCommand
{
protected:
    NodeOperator *operator_;
public:
    NodeExpression();
    ~NodeExpression();
    NodeOperator *getOperator();
};