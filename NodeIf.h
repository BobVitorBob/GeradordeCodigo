#include "Node.h"
#include "NodeExpression.h"
#include "NodeCommand.h"
class NodeIf : NodeCommand
{
protected:
    NodeExpression *NodeConditional;

    NodeCommand *NodeThen;

    NodeCommand *NodeElse;

public:

    NodeIf();
    
    ~NodeIf();
    
    NodeExpression *getConditional();

    NodeCommand *getThen();

    NodeCommand *getElse();

};