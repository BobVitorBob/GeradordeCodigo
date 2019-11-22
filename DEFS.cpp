#include <iostream>
#include <list>
#include "DEFS.h"
//class node/tabela passado
using namespace std;

list<string> defsMIPS;

/*
    .word - int/int[]
    .space - pointer
    .asciiz - string/chars
*/

DEFS::DEFS(/*symbolTable*/)
{
    defsMIPS.push_back(".data\n");
    
    
}