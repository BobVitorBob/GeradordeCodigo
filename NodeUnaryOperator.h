#ifndef NODEUNARYOPERATOR
#define NODEUNARYOPERATOR
#include "NodeOperator.h"
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
    NodeOperator *son;
    UnaryOpType unaryOpType;
public:
    NodeUnaryOperator(UnaryOpType unaryOpType, ReturnType returnType);
    ~NodeUnaryOperator();
    NodeOperator *getSon();
    UnaryOpType getUnaryOpType();
};
#endif