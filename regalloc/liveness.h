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

        liveness(list<string> code, int numBlocks);
    private:
        /*necessario pré-processamento - add flag FIM abaixo de chamada de funções*/
        map<int, list<string>> Def_Use(list<string> code);
        map<int, list<string>> In_Out(int numBlocks, map<int, list<string>> defUse);
        map<string, list<string>> build_interfs(list<string> code, map<int, list<string>> inOut, int numBlocks);
        map<int, list<string>> insertDefUse(string simb, string numDU, map<int, list<string>> uses);
};

#endif
