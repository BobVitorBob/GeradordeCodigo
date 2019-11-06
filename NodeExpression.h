#include "Node.h"
#include "Operator.h"
class NodeExpression : public Node
{
private:
    Operator *NodeOperator;
public:
    NodeExpression();
    ~NodeExpression();
};