#include "NodeExpression.h"

    NodeExpression::NodeExpression(NodeOperator *operator_) : NodeCommand((CommandType) CExpression){
        this->next = nullptr;
        this->operator_ = operator_;
    }

    NodeExpression::~NodeExpression(){

    }

    NodeOperator *NodeExpression::getOperator(){
        return this->operator_;
    }

    void NodeExpression::getOperator(NodeOperator *operator_){
        this->operator_ = operator_;
    }
