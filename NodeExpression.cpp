#include "NodeExpression.h"

    NodeExpression::NodeExpression(NodeOperator *operator_) : NodeCommand((CommandType) CExpression){
        this->next = nullptr;
        this->operator_ = operator_;
    }

    NodeExpression::~NodeExpression(){

    }

    NodeOperator *NodeExpression::getOperator(){

    }
