#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <list>
#include <iterator> 
#include <map> 
#include <algorithm>
#include "liveness.h"
using namespace std;

/*necessario pré-processamento - add flag FIM abaixo de chamada de funções*/

map<int, string> vars;
string interfs;

map<int, list<string>> liveness::insertDefUse(string simb, string numDU, map<int, list<string>> uses)
{
    int num;
    map<int, list<string>>::iterator itmap;
    list<string> listaux;
    list<string>::iterator itl;

    stringstream geek(numDU);
    geek >> num;  
    itmap = uses.find(num);

    if(itmap == uses.end()){
        listaux.push_back(simb);
        uses.insert(pair<int, list<string>>(num, listaux));
        
    }else{
        itl = find(itmap->second.begin(), itmap->second.end(), simb);
        if(itl == itmap->second.end()){
            itmap->second.push_back(simb);
        }
        
    }
    return uses;
}

map<int, list<string>> liveness::Def_Use(list<string> code){
    /*  estrutura do block: 
        primeiro num = num do bloco
        segundo num = 1 p/ def e 2 p/ use
    */
    map<int, list<string>> uses;
    string block = "1";
    int num;

    list<string>::iterator it = code.begin();
    while(it != code.end())
    {
        if(*it == "="){
            uses = insertDefUse(*it, block+"1", uses);
            it++;
            uses = insertDefUse(*it, block+"2", uses);

        }else if(*it == "-" || *it == "+"){
            it++;
            if(*it == "-" || *it == "+"){
                uses = insertDefUse(*it, block+"1", uses);
                uses = insertDefUse(*it, block+"2", uses);
            }else{
                uses = insertDefUse(*it, block+"2", uses);
            }
            
        }else if(*it == "FIM"){
            stringstream geek(block);
            geek >> num;  
            num++;
            block = to_string(num);
        }
        it++;
    }

    return uses;
}

map<int, list<string>> liveness::In_Out(int numBlocks, map<int, list<string>> defUse){
    /*  estrutura do block: 
        primeiro num = num do bloco
        segundo num = 1 p/ in e 2 p/ out
    */
    map<int, list<string>> inout;
    map<int, list<string>>::iterator it;
    map<int, list<string>>::iterator it2;
    list<string>::iterator its;
    string block = "1";
    string aux;
    int num;

    while(numBlocks > 0){
        //OUT
        stringstream geek(block);
        geek >> num;  
        num++;
        aux = to_string(num);
        aux = aux + "2";
        stringstream geek(aux);
        geek >> num; 
        it = inout.find(num);
        if(it != inout.end()){
            list<string> outs;
            for(its=it->second.begin(); its!=it->second.end(); ++its){
                outs.push_back(*its);
            }
            stringstream geek(block+"2");
            geek >> num;  
            inout.insert(pair<int, list<string>>(num, outs));
        }

        //IN
        list<string> ins;
        stringstream geek(block+"2");
        geek >> num;  
        it = defUse.find(num);
        if(it!=defUse.end()){
            ins = it->second;
        }
        it = inout.find(num);
        stringstream geek(block+"1");
        geek >> num;
        it2 = defUse.find(num);
        if(it!=inout.end() && it2==defUse.end()){
            for(its=it->second.begin(); its!=it->second.end(); ++its){
                if(find(ins.begin(), ins.end(), *its) == ins.end()){
                    ins.push_back(*its);
                }
            }
        }else if(it2!=defUse.end() && it!=inout.end()){
            ins = it->second;
            list<string>::iterator el;
            for(its=it2->second.begin(); its!=it2->second.end(); ++its){
                el = find(ins.begin(), ins.end(), *its);
                if(el!=it->second.end()){
                    ins.remove(*el);
                }
            }
            stringstream geek(block+"1");
            geek >> num;  
            inout.insert(pair<int, list<string>>(num, ins));
        }
        numBlocks--;
        stringstream geek(block);
        geek >> num;  
        num++;
        block = to_string(num);
    }
    return inout;
}

map<string, list<string>> liveness::build_interfs(list<string> code, map<int, list<string>> inOut, int numBlocks)
{
    list<string>::iterator it;
    list<string>::iterator itl;
    list<string> aux;
    map<int, list<string>>::iterator it2;
    map<string, list<string>> mapI;
    map<string, list<string>>::iterator itm;
    string str;
    int num;

    str = to_string(numBlocks);
    str = str+"2";
    stringstream geek(str);
    geek >> num;  
    for(it=code.end(); it!=code.begin(); --it)
    {
        str = to_string(numBlocks);
        str = str+"2";
        stringstream geek(str);
        geek >> num;

        it2 = inOut.find(num);
        itl = it2->second.begin();
        itm = mapI.find(*itl);
        if(itm==mapI.end()){
            str = *itl;
            aux.clear();
            while(itl!=it2->second.end()){
                ++itl;
                aux.push_back(*itl);
            }
            mapI.insert(pair<string, list<string>>(str, aux));
        }else{
            while(itl!=it2->second.end()){
                ++itl;
                itm->second.push_back(*itl);
            }
        }

    }

}

liveness::liveness(list<string> code, int numBlocks)
{
    map<int, list<string>> defUse = Def_Use(code);
    map<int, list<string>> inOut = In_Out(numBlocks, defUse);
    map<string, list<string>> aux = build_interfs(code, inOut, numBlocks);

    map<string, list<string>>::iterator it;
    list<string>::iterator its;
    for(it=aux.begin(); it!=aux.end(); ++it){
        interfs = interfs + " " + it->first + " -> ";
        for(its=it->second.begin(); its!=it->second.end(); ++its){
            interfs = interfs + *its + " ";
        }
    }
}