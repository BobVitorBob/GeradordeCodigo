#ifndef NODEBINARYOPERATOR
#define NODEBINARYOPERATOR
#include "NodeOperator.h"
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
    NodeOperator *leftSon;
    NodeOperator *rightSon;
public:
    NodeBinaryOperator(BinaryOpType binaryOpType, ReturnType returnType);
    ~NodeBinaryOperator();
    void setLeftSon(NodeOperator *leftSon);
    void setRightSon(NodeOperator *rightSon);
    NodeOperator *getLeftSon();
    NodeOperator *getRightSon();
    BinaryOpType getBinaryOpType();
};
#endif