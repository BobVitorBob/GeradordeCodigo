#ifndef SIMPLIFY_H
#define SIMPLIFY_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <map> 
#include <stack>
#include <vector>
using namespace std;

class simplify
{
    public:
        int k;
        stack<int> pilha;

        simplify(int n, map<int, list<int>> gd, vector<int> graus);

    private:
       int max;
    
       int bound_max(vector<int> graus, map<int, list<int>> gd);
       void empilha(int value, int comp);
       vector<int> newK(map<int, list<int>> gd, list<int> inter, vector<int> graus);
};

#endif