#include "NodeCommand.h"
#include "NodeExpression.h"
#include <string>
class NodePrintf : NodeCommand
{
protected:
    NodeExpression *expressions;
    string text;
public:
    NodePrintf(/* args */);
    ~NodePrintf();
    string getText();
    NodeExpression *getExpressions();
};