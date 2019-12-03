#ifndef NODEBINARYOPERATOR
#define NODEBINARYOPERATOR
#include "NodeOperator.h"
#include "NodeExpression.h"
enum BinaryOpType{
BPlus,
BMinus,
BMultiply,
BDiv,
BRemainder,
BBitwise_and,
BBitwise_or,
BBitwise_xor,
BLogical_and,
BLogical_or,
BEqual,
BNot_equal,
BLess_than,
BGreater_than,
BLess_equal,
BGreater_equal,
BR_shift,
BL_shift,
BAssign,
BAdd_assign,
BMinus_assign
};
class NodeBinaryOperator : public NodeOperator
{
protected:
    BinaryOpType binaryOpType;
    NodeExpression *leftSon;
    NodeExpression *rightSon;
public:
    NodeBinaryOperator(BinaryOpType binaryOpType, ReturnType returnType);
    ~NodeBinaryOperator();
    void setLeftSon(NodeExpression *leftSon);
    void setRightSon(NodeExpression *rightSon);
    NodeExpression *getLeftSon();
    NodeExpression *getRightSon();
    BinaryOpType getBinaryOpType();
};
#endif