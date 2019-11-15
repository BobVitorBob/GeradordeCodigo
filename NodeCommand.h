#include "Node.h"
// commandType == 0: do-while
// commandType == 1: if
// commandType == 2: while
// commandType == 3: for
// commandType == 4: printf
// commandType == 5: scanf
// commandType == 6: exit
// commandType == 7: return
// commandType == 8: expressões matemáticas. 
class NodeCommand : Node
{
protected:
    int commandType;
public:
    NodeCommand();
    ~NodeCommand();
    int getCommandType();
};