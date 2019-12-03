#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
#include <map> 
#include <iterator> 
#include <sstream> 
#include <stack>
#include <vector>
#include <map>
#include "grafo.h"
#include "simplify.h"
#include "assign.h"
#include "liveness.h"
using namespace std;

map<string, int> REGALLOC(list<string> code, int numBlocks)
{
/* LIVENESS ANALISYS */
liveness* LA = new liveness(code, numBlocks);

/* BUILD: construir grafo */  
grafo* GD = new grafo();
GD->BUILD(LA->interfs, 0);

/* SIMPLIFY: empilhar nós */
simplify* SYM = new simplify(18, GD->relact, GD->graus);

/* ASSIGN: aloca as vars */
assign* aloc = new assign(GD->relact, SYM->pilha, 18);
}
