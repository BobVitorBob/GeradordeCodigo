#ifndef NODEEXIT
#define NODEEXIT
#include "NodeExpression.h"
#include "NodeCommand.h"
class NodeExit : public NodeCommand
{
protected:
    NodeExpression *exitValue;
public:
    NodeExit(NodeExpression *exitValue);
    ~NodeExit();
    NodeExpression *getExitValue();
};
#endif