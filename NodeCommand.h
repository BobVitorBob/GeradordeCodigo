#ifndef NODECOMMAND
#define NODECOMMAND
#include "Node.h"
enum CommandType{
    CDo_while,
    CIf,
    CWhile,
    CFor,
    CPrintf,
    CScanf,
    CExit,
    CReturn,
    CExpression
};
class NodeCommand : public Node
{
protected:
    CommandType commandType;
public:
    NodeCommand() = default;
    NodeCommand(CommandType commandType);
    ~NodeCommand();
    int getCommandType();
};
#endif