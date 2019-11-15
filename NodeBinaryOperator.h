#include "NodeOperator.h"
class BinaryNodeOperator : NodeOperator
{
protected:
    NodeOperator *leftSon;
    int opType;
    NodeOperator *rightSon;
public:
    BinaryNodeOperator();
    ~BinaryNodeOperator();
    NodeOperator *getLeftSon();
    NodeOperator *getRightSon();
    int getOpType();
};