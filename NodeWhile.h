#ifndef NODEWHILE
#define NODEWHILE
#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeWhile : public NodeCommand
{
protected:

    NodeCommand *commands;

    NodeExpression *stopCondition;

public:
    NodeWhile(NodeCommand *commands, NodeExpression *stopCondition);
    ~NodeWhile();
    NodeCommand *getCommands();
    NodeCommand *getStopCondition();
};
#endif