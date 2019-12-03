#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <list>
#include "DEFS.h"
#include "NodeSymbol.h"
using namespace std;

class DEFS
{
    public:
        list<string> defsMIPS;
        DEFS();
        void AddDef(NodeSymbol *simbs);
};

#endif