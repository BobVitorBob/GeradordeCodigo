#ifndef NODEPRINTF
#define NODEPRINTF
#include "NodeCommand.h"
#include "NodeExpression.h"
#include <string>
class NodePrintf : public NodeCommand
{
protected:
    NodeExpression *expressions;
    string text;
public:
    NodePrintf(string text);
    ~NodePrintf();
    string getText();
    NodeExpression *getExpressions();
};
#endif