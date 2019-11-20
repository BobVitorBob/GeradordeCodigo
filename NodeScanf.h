#include "NodeCommand.h"
#include <string>
class NodeScanf : NodeCommand
{
protected:
    string formatString;

    void *variable;
public:
    NodeScanf();
    ~NodeScanf();
    string getFormatString();
    void *getVariable();
};