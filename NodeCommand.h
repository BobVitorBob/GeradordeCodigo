#include "Node.h"
enum CommandType{
    Do_while,
    If,
    While,
    For,
    Printf,
    Scanf,
    Exit,
    Return,
    Expressions
};
class NodeCommand : Node
{
protected:
    CommandType commandType;
public:
    NodeCommand(CommandType commandType);
    ~NodeCommand();
    int getCommandType();
};