using namespace std;
class Node
{
protected:

    Node *next;

    int nodeType;

public:
    
    Node();

    ~Node();

    Node *getNext();
    
    int getNodeType();

};