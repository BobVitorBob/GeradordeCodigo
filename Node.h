class Node
{
private:

protected:

    Node *next;

    int nodeType;

public:
    
    Node();

    ~Node();

    Node *getNext();
    
    int getNodeType();

};