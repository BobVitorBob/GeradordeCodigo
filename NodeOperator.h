#include "Node.h"

// OpId == 0: Operador Unário
// OpId == 1: Operador Binário
// OpId == 2: Valor Puro

// ReturnType == 0: int
// ReturnType == 1: char
// ReturnType == 2: ponteiro

class NodeOperator : Node
{
protected:
    int opId;

    int returnType;
public:
    NodeOperator();
    ~NodeOperator();
    int getOpId();
    int getReturnType();
};