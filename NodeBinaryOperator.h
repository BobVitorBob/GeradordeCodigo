#include "NodeOperator.h"
enum OpType{
plus,
minus,
multiply,
div,
remainder,
bitwise_and,
bitwise_or,
bitwise_xor,
logical_and,
logical_or,
equal,
no_equal,
less_than,
greater_than,
less_equal,
greater_equal,
r_shift,
l_shift,
assign,
add_assign,
minus_assign
};
class BinaryNodeOperator : NodeOperator, Node
{
protected:
    OpType opType;
    NodeOperator *leftSon;
    NodeOperator *rightSon;
public:
    BinaryNodeOperator(OpId opId, OpType opType, int returnType);
    ~BinaryNodeOperator();
    void setLeftSon(NodeOperator *leftSon);
    void setRightSon(NodeOperator *rightSon);
    NodeOperator *getLeftSon();
    NodeOperator *getRightSon();
    OpType getOpType();
};