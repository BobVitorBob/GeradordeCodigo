#include "NodeCommand.h"

NodeCommand::NodeCommand(CommandType commandType) : Node(NCommand){
    this->commandType = commandType;
}

NodeCommand::~NodeCommand(){
    delete this;
}

int NodeCommand::getCommandType(){
    return this->commandType;
}