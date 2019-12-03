#ifndef ASSIGN_H
#define ASSIGN_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <map> 
#include <list>
#include <stack>
#include <iterator> 
using namespace std;

class assign
{
    public:
        int sucess;
        
        assign(map<int, list<int>>, stack<int> pilha, int k);

    private:
        stack<int> spill;
        map<int, int> aloc;

        int colour(map<int, int> regs, int value);
};

#endif