#include "NodeExpression.h"
#include "NodeCommand.h"
class NodeExit : NodeCommand, Node
{
protected:
    NodeExpression *exitValue;
public:
    NodeExit(CommandType commandType, NodeExpression *exitValue);
    ~NodeExit();
    NodeExpression *getExitValue();
};