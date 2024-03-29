#ifndef NODEDOWHILE
#define NODEDOWHILE
#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeDoWhile : public NodeCommand
{
protected:

    NodeCommand *commands;

    NodeExpression *stopCondition;

public:
    NodeDoWhile();
    ~NodeDoWhile();
    NodeCommand *getCommands();
    NodeExpression *getStopCondition();
    void addCommand(NodeCommand *newCommand);
    void setStopCondition(NodeExpression *stopCondition);
};
#endif