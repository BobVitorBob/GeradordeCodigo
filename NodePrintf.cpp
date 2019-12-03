#include "NodePrintf.h"

    NodePrintf::NodePrintf(string text){
        this->expressions = nullptr;
    }

    NodePrintf::~NodePrintf(){
        delete this;
    }

    string NodePrintf::getText(){
        return this->text;
    }

    NodeExpression *NodePrintf::getExpressions(){
        return this->expressions;
    }
