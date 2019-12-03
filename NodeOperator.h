#ifndef NODEOPERATOR
#define NODEOPERATOR
#include "Node.h"

enum OpId{
    unaryOp,
    binaryOp,
    function,
    trueValue
};

class NodeOperator : public Node
{
protected:
    OpId opId;

    ReturnType returnType;
public:
    NodeOperator() = default;
    NodeOperator(OpId opId, ReturnType returnType);
    ~NodeOperator();
    OpId getOpId();
    ReturnType getReturnType();
};
#endif