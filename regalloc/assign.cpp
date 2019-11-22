#include <iostream>
#include <stdio.h>
#include <string>
#include <map> 
#include <list>
#include <stack>
#include <iterator> 
#include "assign.h"
using namespace std;

stack<int> spill;
map<int, int> aloc;
int sucess;

int assign::colour(map<int, int> regs, int value)
{
   for(map<int, int>::iterator it = regs.begin(); it != regs.end(); ++it){
       if(it->second == 1){
           aloc.insert(pair<int, int>(value, it->first));
            cout << "Pop: " << value << " -> " << it->first << "\n";
           return 0;
       }
   }
   sucess = 0;
   return 1;
}

assign::assign(map<int,list<int>> gd, stack<int> pilha, int k)
{
    map<int, int> regs;
    int i;

    sucess = 1;

    //incializa cores
    for(i = k-1; i >= 0; i--){
        regs.insert(pair<int, int>(i, 1));
    }

    while(pilha.size() > 0){
        map<int, list<int>>::iterator el = gd.find(pilha.top());

        //percorre lista da pilha -> encontra cor -> retira cor
        if(el != gd.end() && el->second.size() > 0){
            list<int> lista = el->second;
            for(list<int>::iterator it = lista.begin(); it != lista.end(); ++it){
                //ver. lista pilha in regs
                if(*it < k){
                    map<int, int>::iterator r = regs.find(*it);
                    r->second = 0;
                }

                auto aux = aloc.find(*it);
                if(aux != aloc.end()){
                    auto fin = regs.find(aux->second);
                    fin->second = 0;
                }
            }   
        }else{
            for(map<int, int>::iterator al = aloc.begin(); al != aloc.end(); ++al){
                auto iop = gd.find(al->first);
                if(iop->second.size() > 0){
                    for(list<int>::iterator li = iop->second.begin(); li != iop->second.end(); ++li){
                        if(pilha.top() == *li){
                            auto r = regs.find(al->second);
                            r->second = 0;
                        }
                    }
                }
            }
        }

        int res = colour(regs, pilha.top());
        if(res == 1){
            cout << "Pop: " << pilha.top() << " -> NO COLOR AVAILABLE\n";
            //return;
        }
        pilha.pop();
        for(map<int, int>::iterator ux = regs.begin(); ux != regs.end(); ++ux){
            if(ux->second == 0){
                ux->second = 1;
            }
        }
    }
}