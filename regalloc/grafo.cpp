#include <iostream>
#include <stdio.h>
#include <cstring>
#include <list>
#include <sstream> 
#include <map> 
#include <vector> 
#include <iterator> 
#include "grafo.h"
using namespace std;

//list<int> nodes;
map<int, list<int>> relact;
vector<int> graus;
map<int, int> rest;

grafo::grafo(){}

int grafo::makeNo(string entrada, int i){
	string part;
	int resp;

	part = "";
	while(i>=0 && entrada.at(i)!=' '){
		part = entrada.at(i) + part;
		i--;
		//cout << part << "\n";
	}

	stringstream geek(part); 
	geek >> resp;
	return resp;
}

int grafo::makeRelations(string entrada, int i, int n){
	string piece;
	int number;
	int j = i;
	list<int> values;

	//cout << i << " " << entrada.length() << "\n";
	piece = "";
	while(i<entrada.length()-1){
		piece = piece + entrada.at(i);

		if(entrada.at(i) == ' '){
			if(entrada.at(i+1) == '-'){
				//pair< map<int,list<int>>::iterator, bool> ret;
				relact.insert(pair<int, list<int>>(n, values));
				graus.push_back(values.size());
				return j;
			}
			j = i;
			stringstream geek(piece); 
			geek >> number;
			piece = "";
			values.push_back(number);
			/*if(relact.find(number) == relact.end()){
				rest.insert(pair<int, int>(number, 0));
			}*/
			//cout << n << " " << number << "\n";
		}
		i++;
	}
	//cout << "piece: " << piece << "\n";
	stringstream geek(piece); 
	geek >> number;
	values.push_back(number);
	relact.insert(pair<int, list<int>>(n, values));
	graus.push_back(values.size());

	//cout << n << " " << number << "\n";
	return i;
}

void grafo::BUILD(string entrada, int size){
	
	//int n = 0;
	int i;

	for(i = 0; i < entrada.length(); ++i){
		//cout << "m: " << entrada.at(i) << "\n";
		//cout << entrada.at(i);
		if(entrada.at(i) == '-'){
			//cout << entrada.at(i-2);
			int no = makeNo(entrada, i-2);
			
			/*if(rest.find(no) != rest.end()){
				rest.erase(no);
			}*/
			
			i = makeRelations(entrada, i+4, no);
			//n++;
		}
	}
	
	/*for(map<int, int>::iterator it = rest.begin(); it != rest.end(); ++it){
		relact.insert(pair<int, list<int>>(it->first, NULL));
		//graus.insert(graus.begin(), 0);
	}*/
}
