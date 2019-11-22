#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <iterator> 
#include <map> 
using namespace std;

class grafo
{
    public:
        map<int, list<int>> relact;
        vector<int> graus;

        grafo();
        void BUILD(string entrada, int size);

    private:
        map<int, int> rest;

        int makeNo(string entrada, int i);
        int makeRelations(string entrada, int i, int n);
};

#endif
