#include "NodeCommand.h"
#include "NodeExpression.h"
class NodeDoWhile : NodeCommand, Node
{
protected:

    NodeCommand *commands;

    NodeExpression *stopCondition;

public:
    NodeDoWhile(CommandType commandType);
    ~NodeDoWhile();
    NodeCommand *getCommands();
    NodeExpression *getStopCondition();
    void setCommands(NodeCommand *commands);
    void setStopCondition(NodeExpression *stopCondition);
};