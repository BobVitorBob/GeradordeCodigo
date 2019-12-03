#include <iostream>
#include <list>
#include <iterator>
#include "FOR.h"
#include "NodeFor.h"
#include "NodeExpression.h"
using namespace std;

list<string> forMIPS;
int n = 1;

/*
por causa do n, criar essa classe uma unica vez, e quando precisar usar novamente, limpar o forMIPS
*/

list<string>::iterator FOR::FOR(NodeFor *node)
{
    forMIPS.push_back("FOR"+n+":");
    n++;

   //chama função que constroi expressão passando node->startOfLoop
   //add resposta no forMIPS

   //chama função que constroi expressão passando node->stopCondition
   //add resposta no forMIPS

   //chama função que constroi expressão passando node->endOfIteration
   //add resposta no forMIPS

   forMIPS.push_back("CODE");
   forMIPS.push_back("j FOR"+n);
}