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

DEFS::DEFS(/*estrutura AST*/)
{
    //inicializa defMIPS com .data
    
    //percorre estrutura passada
        //(switch case) identifica tipo de declaração: #define, int, char, pointer(void, int, char)
        //e redireciona a função adequada -> return tradução p/ mips
        //add na lista
}