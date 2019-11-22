#ifndef LIVENESS_H
#define LIVENESS_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <iterator> 
#include <map> 
using namespace std;

class liveness
{
    public:
        map<int, string> vars;
        string interfs;

        liveness(string code);
    private:
        map<string, list<string>> Def_Use(string code);
        
};

#endif
