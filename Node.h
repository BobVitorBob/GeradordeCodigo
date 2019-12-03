#ifndef NODE
#define NODE
using namespace std;
enum NodeType{
    NProgram,
    NCommand,
    NFunction,
    NOperator,
    NVariable,
    NSymbol
};

enum ReturnType{
    RInt,
    RChar,
    RVoid
};

class Node
{
protected:

    Node *next;

    NodeType nodeType;

public:
    Node() = default;

    Node(NodeType nodeType);

    ~Node();

    Node *getNext();
    
    void setNext(Node *next);

    NodeType getNodeType();

};
#endif