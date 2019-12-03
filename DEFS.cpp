#include <iostream>
#include <list>
#include "DEFS.h"
#include "NodeSymbol.h"
using namespace std;

list<string> defsMIPS;

DEFS::void AddDef(NodeSymbol *simbs)
{
    defsMips.push_back(simbs->name+": ");
    if(simbs->returnType.compare("RInt")==0){
        defsMIPS.push_back(".word ");
        if(simbs->value != nullptr){
            defsMIPS.push_back(simbs->value+"\n");
        }
    }else if(simbs->returnType.compare("RChar")==0){
        defsMIPS.push_back(".asciiz ");
        if(simbs->value != nullptr){
            defsMIPS.push_back('"'+simbs->value+'"'+"\n");
        }
    }else if(/*VECTOR*/){

    }
}

DEFS::DEFS()
{
    defsMIPS.push_back(".data\n");
}