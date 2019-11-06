#include "Operator.h"
class ValueOperator : Operator
{
protected:
    void *value;
public:
    ValueOperator();
    ~ValueOperator();
    void *getValue();
};