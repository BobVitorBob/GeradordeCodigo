#include "Node.h"
#include <string>
// ReturnType == 0: int
// ReturnType == 1: char
// ReturnType == 2: ponteiro
class NodeVariable : Node
{
protected:

    string name;
    int type;
    void *value;

public:
    NodeVariable();
    ~NodeVariable();
    string getName();
    int getType();
    void *getValue();
};