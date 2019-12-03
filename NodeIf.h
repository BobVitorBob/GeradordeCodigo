#ifndef NODEIF
#define NODEIF
#include "Node.h"
#include "NodeExpression.h"
#include "NodeCommand.h"
class NodeIf : public NodeCommand
{
protected:
    NodeExpression *conditional;

    NodeCommand *then;

    NodeCommand *else_;

public:

    NodeIf();
    
    ~NodeIf();
    
    NodeExpression *getConditional();

    NodeCommand *getThen();

    NodeCommand *getElse();

};
#endif