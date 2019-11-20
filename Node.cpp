#include "Node.h"

Node::Node(NodeType nodeType){
    this->next = nullptr;
    this->nodeType = nodeType;
}

Node::~Node(){
    delete this;
}

Node *Node::getNext(){
    return next;
}

NodeType Node::getNodeType(){
    return nodeType;
}