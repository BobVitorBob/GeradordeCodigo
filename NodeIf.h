#include "Node.h"
#include "NodeExpression.h"
class NodeIf : public Node
{
private:
    NodeExpression *NodeConditional;

    Node *NodeThen;

    Node *NodeElse;

public:

    NodeIf();
    
    ~NodeIf();
    
};