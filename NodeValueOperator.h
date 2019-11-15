#include "NodeOperator.h"
class ValueNodeOperator : NodeOperator
{
protected:
    void *value;
public:
    ValueNodeOperator();
    ~ValueNodeOperator();
    void *getValue();
};