using namespace std;
enum NodeType{
    a,
    b,
    c,
    etc
};
class Node
{
protected:

    Node *next;

    NodeType nodeType;

public:
    
    Node(NodeType nodeType);

    ~Node();

    Node *getNext();
    
    NodeType getNodeType();

};