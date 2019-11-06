#include "Operator.h"
class UnaryOperator : Operator
{
protected:
    Operator *son;
public:
    UnaryOperator();
    ~UnaryOperator();
    Operator *getSon();
};