#ifndef FOR_H
#define FOR_H

#include <iostream>
#include <list>
#include "NodeFor.h"
#include "NodeExpression"
using namespace std;

class FOR
{
    public:
        list<string> forMIPS;
        list<string>::iterator FOR(NodeFor *node);
};

#endif