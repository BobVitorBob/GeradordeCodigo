#ifndef NODEEXPRESSION
#define NODEEXPRESSION
#include "Node.h"
#include "NodeOperator.h"
#include "NodeCommand.h"
class NodeExpression : public NodeCommand
{
protected:
    NodeOperator *operator_;
public:
    NodeExpression(NodeOperator *operator_=nullptr);
    ~NodeExpression();
    NodeOperator *getOperator();
    void getOperator(NodeOperator *operator_);
};
#endif