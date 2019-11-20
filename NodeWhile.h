#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeWhile : NodeCommand
{
protected:

    NodeCommand *commands;

    NodeExpression *stopCondition;

public:
    NodeWhile(/* args */);
    ~NodeWhile();
    NodeCommand *getCommands();
    NodeCommand *getStopCondition();
};