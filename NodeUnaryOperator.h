#include "NodeOperator.h"
class UnaryNodeOperator : NodeOperator
{
protected:
    NodeOperator *son;
    int opType;
public:
    UnaryNodeOperator();
    ~UnaryNodeOperator();
    NodeOperator *getSon();
    int getOpType();
};