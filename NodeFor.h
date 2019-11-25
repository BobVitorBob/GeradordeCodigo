#ifndef NODEFOR
#define NODEFOR
#include "Node.h"
#include "NodeExpression.h"
#include "NodeCommand.h"
class NodeFor : public NodeCommand
{
protected:

    NodeExpression *startOfLoop;

    NodeExpression *stopCondition;

    NodeExpression *endOfIteration;

    NodeCommand *forCode;

public:
    NodeFor();
    
    ~NodeFor();

    NodeExpression *getStartOfLoop();

    NodeExpression *getStopCondition();

    NodeExpression *getEndOfIteration();

    NodeCommand *getForCode();
};
#endif