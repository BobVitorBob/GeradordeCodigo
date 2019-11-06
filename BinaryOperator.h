#include "Operator.h"
class BinaryOperator : Operator
{
protected:
    Operator *leftSon;
    Operator *rightSon;
public:
    BinaryOperator();
    ~BinaryOperator();
    Operator *getLeftSon();
    Operator *getRightSon();
};