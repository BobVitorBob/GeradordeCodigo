#include "NodeCommand.h"

NodeCommand::NodeCommand(CommandType commandType){//que porar é ssa caralho tiltei
    this->commandType = commandType;
}

NodeCommand::~NodeCommand(){
    delete this;
}

int NodeCommand::getCommandType(){
    return this->commandType;
}