#ifndef NODEUNARYOPERATOR
#define NODEUNARYOPERATOR
#include "NodeOperator.h"
#include "NodeExpression.h"
enum UnaryOpType{
UPlus,
UPointer,
UMinus,
UInc,
UDec,
UBitwise_not,
UNot,
UBitwise_and
};

class NodeUnaryOperator : public NodeOperator
{
protected:
    NodeExpression *son;
    UnaryOpType unaryOpType;
public:
    NodeUnaryOperator(UnaryOpType unaryOpType, ReturnType returnType);
    ~NodeUnaryOperator();
    NodeExpression *getSon();
    UnaryOpType getUnaryOpType();
};
#endif