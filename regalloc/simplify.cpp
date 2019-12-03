#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator> 
#include "simplify.h"
using namespace std;

int k;
stack<int> pilha;
//int diff;
int max;
//list<int> eqlity;

void simplify::empilha(int value, int comp)
{
    pilha.push(value);
    if(comp >= k){
        cout << "Push: " << value << " *\n";
    }else{
        cout << "Push: " << value << "\n";
    }
    //diff = comp;
}

vector<int> simplify::newK(map<int, list<int>> gd, list<int> inter, vector<int> graus)
{
    /*int index = distance(gd.begin(), gd.find(32));
    cout << index;*/
    //percorre inter
    for(list<int>::iterator it = inter.begin(); it != inter.end(); ++it){
        //find inter in gd and get index
        if(gd.find(*it) != gd.end()){
            int index = distance(gd.begin(), gd.find(*it));
            if(graus[index] != max){
                graus[index] = graus[index] - 1;
            }
        }
    }
    return graus;
}

int simplify::bound_max(vector<int> graus, map<int, list<int>> gd)
{
     int asd = 0, w = 0, keep;
     vector<int>::iterator val;
     map<int, list<int>>:: iterator itr, itr2;
        
            for(val = graus.begin(); val != graus.end(); ++val){
                if(*val < max){
                    if(*val > asd){
                        asd = *val;
                        keep = w;
                    }else if(*val == asd){
                        itr = gd.begin();
                        advance(itr, w);
                        itr2 = gd.begin();
                        advance(itr2, keep);
                        if(itr->first < itr2->first){
                            keep = w;
                        }
                    }
                }
                w++;
            }
            //eqlity.push_back(keep);
            //cout << keep << "\n";
            return keep;
            
}

/*bool simplify::testeNPS(int flag, vector<int> graus, int minV)
{
    /*if(flag == 1){
        if( *min_element(graus.begin(), graus.end()) >= k && graus[bound_max(graus)] == minV ){
            return true;
        }
    }
    return false;*/
//}

simplify::simplify(int n, map<int, list<int>> gd, vector<int> graus)
{
    int min, minI, i, minAUX;
    vector<int> index;
    vector<int> values;
    map<int, list<int>>::iterator iter;
    k = n;

    int flag = 0;
    
    //salva o maior valor de grau - invalido
    max = *max_element(graus.begin(), graus.end()) + 1;
    i = 0;

    do{
        // get menor grau
        minI = min_element(graus.begin(), graus.end()) - graus.begin();

        //if minI > k -> get maior grau
        int minV ;
        //cout << graus[minI];
        if(graus[minI] >= k && flag == 0){
            //cout << "entrou\n";
            minV = bound_max(graus, gd);
            flag = 1;
            //minV = max;
        }else{
        
            minV = graus[minI];
            if(minV == max){
                break;
            }
        
            graus[minI] = max;
        }
        
        if( *min_element(graus.begin(), graus.end()) == minV && flag == 0){

            index.push_back(minI);
            minAUX = minV;

            //graus[minI] = minV;
            //cout << "more\n";

            i++;
        }else if(flag == 1){
            int mn = max;
            int py;
            list<int> l2;
            

            //for(list<int>::iterator itl = eqlity.begin(); itl != eqlity.end(); ++itl){
                //itl = eqlity.begin();
                //cout << *itl << "\n";
                iter = gd.begin();
                //advance(itl, l);
                advance(iter, minV);

                //cout << iter->first << "\n";
                /*if(iter->first < mn || mn == max){
                    py = *itl;
                    mn = iter->first;
                    l2 = iter->second;
                    minV = graus[*itl];
                }
            }*/

            //cout << py << "\n";

            empilha(iter->first, graus[minV]);
            graus[minV] = max;
            graus = newK(gd, iter->second, graus);
            i = flag = 0;
            //eqlity.clear();
            //cout << "spill\n";

        }else{
            if(i == 0){
                iter = gd.begin();
                advance(iter, minI);
                empilha(iter->first, minV);
                graus = newK(gd, iter->second, graus);
                //cout << iter->first << "\n"; 

                flag = 0;
                //cout << "unique\n";
            }else{
                index.push_back(minI);
                for(int j=0; j<index.size(); j++){
                    iter = gd.begin();
                    advance(iter, index[j]);
                    values.push_back(iter->first);

                    //cout << iter->first << " ";
                }
                //cout << "\n";
                //g = values.size();
                //for(int j=0; j<g; j++){
                minI = min_element(values.begin(), values.end()) - values.begin();
                min = values[minI];
                //index[minI] = max;

                    //minI = min_element(values.begin(), values.end()) - values.begin();
                    //values[minI] = max;
                auto aux = gd.find(min);

                for(int j=0; j<index.size(); j++){
                    //if(index[j] != max){
                        graus[index[j]] = minAUX;
                    //}
                }

                empilha(min, graus[index[minI]]);
                //cout << graus[index[minI]];
                graus[index[minI]] = max;
                graus = newK(gd, aux->second, graus);
                    //cout << min << "\n";
                //}
                
                values.clear();
            //}
                index.clear();
                i = 0;
                flag = 0;
                //cout << "more\n";
            }
        }
        /*cout << pilha.size() << " " << graus.size() << "\n";
        cout << i << "\n";*/
    }while(pilha.size() < graus.size());
}
