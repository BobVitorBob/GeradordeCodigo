#include "includes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <stdexcept>
//AST -->
//CONSTANT: hkey VALUE: 666
//GLOBAL VARIABLE: j TYPE: int
//FUNCTION: f
//RETURN_TYPE: void
//VARIABLE: i TYPE: int
//VARIABLE: w TYPE: int[10]
//IF(j,=(w[(i)++],0));
//++(j);
//RETURN()
//END_FUNCTION
using namespace std;

vector<string> splitStringBySpace(string s){
    printf("Spliting string...\n");
    vector<string> split;
    string help;
    int i = 0;
    while (i < s.length() || s[i] != '\0')
    {
        help.clear();
        while (s[i] != '\n' && s[i] != '\0' && s[i] != ' ')
        {
            help.append(&s[i], 1);
            i++;
        }
        i++;
        if(!help.empty()) split.emplace_back(help);
    }
    printf("String Split!\n");
    return split;    
}

int fSize(ifstream &file){
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    return length;
}

string fileToString(ifstream &file){
    int length = fSize(file);
    printf("Tamanho do arquivo: %d", length);
    char * buffer = new char [length-1];
    file.read(buffer, length);
    string fileString(buffer);
    delete[] buffer;
    return fileString;
}

int countPLvl(string s, int startPos){
    int counter = 0;
    while(s[startPos] == '*'){
        startPos++;
        counter++;
    }
    return counter;
}

vector<int> resolveArrayDimension(string s, int startPos){
    string size;
    vector<int> arrays;
    while(s[startPos] == '['){
        startPos++;
        size.clear();
        while(s[startPos] != ']'){
            size.append(&s[startPos], 1);
            startPos++;
        }
        arrays.emplace_back(stoi(size));
        startPos++;
    }
    return arrays;
}

tuple<ReturnType, int, vector<int>> resolveVarType(string s){
    ReturnType varType;
    int startPos;
    if(s[0] == 'i'){
        varType = RInt;
        startPos = 3;
    }else if(s[0] == 'c'){
        varType = RChar;
        startPos = 4;
    }else{
        varType = RVoid;
        startPos = 4;
    }
    int cLvl = countPLvl(s, startPos);
    startPos += cLvl;
    vector<int> arrayDimension = resolveArrayDimension(s, startPos);
    return make_tuple(varType, cLvl, arrayDimension);
}

NodeSymbol *readConstant(vector<string> programV, int *startPos){
    int i = *startPos;
    i++;
    string constantName(programV[i]);
    i+=2;
    int constantValue = stoi(programV[i]);
    NodeSymbol *newSymbol = new NodeSymbolConstant(constantName, constantValue);
    *startPos = i;
    return newSymbol;
}

NodeSymbol *readGlobalVariable(vector<string> programV, int *startPos){
    int i = *startPos;
    i+=2;
    string varName(programV[i]);
    i+=2;
    tuple<ReturnType, int, vector<int>> varTypeInfo = resolveVarType(programV[i]);
    NodeSymbol *newVar = new NodeSymbolVariable(varName, nullptr, get<0>(varTypeInfo), get<1>(varTypeInfo), get<2>(varTypeInfo));
    *startPos = i;
    return newVar;
}

tuple<ReturnType, int> resolveFuncReturn(string s){
    ReturnType varType;
    int startPos;
    if(s[0] == 'i'){
        varType = RInt;
        startPos = 3;
    }else if(s[0] == 'c'){
        varType = RChar;
        startPos = 4;
    }else{
        varType = RVoid;
        startPos = 4;
    }
    int cLvl = countPLvl(s, startPos);
    return make_tuple(varType, cLvl);
}

void setFuncParameter(vector <string> programV, int * startPos, NodeSymbolFunction *newFunction){
    int i = *startPos;
    i++;
    NodeSymbolVariable *newVar = new NodeSymbolVariable();
    string varName = programV[i];
    i+=2;
    tuple<ReturnType, int, vector<int>> varRType = resolveVarType(programV[i]);
    newVar->setName(varName);
    newVar->setVarType(get<0>(varRType));
    newVar->setPointerLvl(get<1>(varRType));
    newVar->setArrayDimension(get<2>(varRType));
    newFunction->addNewSymbol(newVar);
    *startPos = i;
}

void setFuncVariable(vector <string> programV, int * startPos, NodeSymbolFunction *newFunction){
    int i = *startPos;
    i++;
    NodeSymbolVariable *newVar = new NodeSymbolVariable();
    string varName = programV[i];
    i+=2;
    tuple<ReturnType, int, vector<int>> varRType = resolveVarType(programV[i]);
    newVar->setName(varName);
    newVar->setVarType(get<0>(varRType));
    newVar->setPointerLvl(get<1>(varRType));
    newVar->setArrayDimension(get<2>(varRType));
    newFunction->addNewSymbol(newVar);
    *startPos = i;
}

NodeDoWhile *resolveDoWhile(string s){

}

NodeIf *resolveIf(string s){

}

NodeWhile *resolveWhile(string s){

}

NodeFor *resolveFor(string s){

}

NodePrintf *resolvePrintf(string s){

}

NodeScanf *resolveScanf(string s){

}

NodeExit *resolveExit(string s){

}

NodeReturn *resolveReturn(string s){

}

NodeExpression *resolveExpression(string s){

}


void setFuncCommand(vector <string> programV, int * startPos, NodeSymbolFunction *newFunction){
    return;
    int i = *startPos;
        if(programV[i].compare("DO_WHILE") == 0)
        {
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("IF") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("WHILE") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("FOR") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("PRINTF") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("SCANF") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("EXIT") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else if(programV[i].compare("RETURN") == 0){
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
        else{
            newFunction->addNewCommand(resolveDoWhile(programV[i]));
        }
    *startPos = i;
}

NodeSymbolFunction *readFunction(vector <string> programV, int *startPos){
    int i = *startPos;
    i++;
    NodeSymbolFunction *newFunction = new NodeSymbolFunction();
    string funcName(programV[i].c_str());
    newFunction->setFunctionName(funcName);
    i+=2;
    tuple<ReturnType, int> funcRetType = resolveFuncReturn(programV[i]);
    newFunction->setReturnType(get<0>(funcRetType));
    newFunction->setPointerLvl(get<1>(funcRetType));
    i++;
    while (true)
    {
        *startPos = i;
        if(programV[i].compare("END_FUNCTION") == 0) break;
        else if(programV[i].compare("PARAMETER:") == 0)
        {
            setFuncParameter(programV, startPos, newFunction);
        }
        else if(programV[i].compare("VARIABLE:") == 0){
            setFuncVariable(programV, startPos, newFunction);
        }else{
            setFuncCommand(programV, startPos, newFunction);
        }
        i++;
    }
    *startPos = i;
    return newFunction;
}

NodeProgram *parser(string programS){
    vector<string> programV = splitStringBySpace(programS);
    int *i = new int(2);
    NodeProgram *program = new NodeProgram();
    while (*i < programV.size())
    {
        if(programV[*i].compare("CONSTANT:") == 0){
            printf("Got a constant!\n");
            program->setNewSymbol(readConstant(programV, i));
        }else if(programV[*i].compare("GLOBAL") == 0){
            printf("Got a global variable!\n");
            program->setNewSymbol(readGlobalVariable(programV, i));
        }else if(programV[*i].compare("FUNCTION:") == 0){
            printf("Got a function!\n");
            program->setNewFunction(readFunction(programV, i));
        }else break;
        *i = *i + 1;
    }
    
    return program;
}

void printAllSymbols(NodeProgram *program){
    NodeSymbol *symbols = program->getSymbolTable();
    printf("All Symbols:\n");
    NodeSymbolConstant *constant;
    NodeSymbolVariable *globalVar;
    while (symbols != nullptr)
    {
        printf("Symbol name: %s\n", symbols->getName().c_str());
        if(symbols->getSymbolType() == SConstant){
            constant = (NodeSymbolConstant *)symbols;
            printf("Constant Value: %d\n", constant->getValue());
        }else if(symbols->getSymbolType() == SVariable){
            globalVar = (NodeSymbolVariable *)symbols;
            printf("Var type: %d\n", globalVar->getVarType());
            printf("Pointer lvl: %d\n", globalVar->getPointerLvl());
            printf("Array Dimension: %d\n", globalVar->getArrayDimension());
            int i = 0;
            while (i < globalVar->getArrayDimension())
            {
                printf("Array D. %d Size: %d\n", i, globalVar->getArraySize(i));
                i++;
            }
            
        }
        symbols = (NodeSymbol*) symbols->getNext();
    }
}

void printAllFunctions(NodeProgram *program){
    NodeSymbolFunction *functions = program->getFunctions();
    printf("All Functions:\n");
    NodeSymbol *symbol;
    NodeSymbolVariable *variable;
    while (functions != nullptr)
    {
        printf("Function name: %s\n", functions->getName().c_str());
        printf("Symbols:\n");
        symbol = functions->getSymbolTable();
        while (symbol != nullptr)
        {
            if (symbol->getSymbolType() == SFunction)
            {
                printf("Function name: %s\n");
            }else if(symbol->getSymbolType() == SVariable){
                variable = (NodeSymbolVariable*) symbol;
                printf("Variable name: %s\n", variable->getName().c_str());
                printf("Variable type: %d\n", variable->getVarType());
                printf("Pointer lvl: %d\n", variable->getPointerLvl());
                printf("Array Dimension: %d\n", variable->getArrayDimension());
                int i = 0;
                while (i < variable->getArrayDimension())
                {
                    printf("Array D. %d Size: %d\n", i, variable->getArraySize(i));
                    i++;
                }
            }
            symbol = (NodeSymbol*) symbol->getNext();
        }
        printf("Commands: %s\n", functions->getName().c_str());
        printf("Return Type: %d\n", functions->getReturnType());
        printf("Pointer Lvl: %d\n", functions->getPointerLvl());

        functions = (NodeSymbolFunction*) functions->getNext();
    }
}

int main(int argc, char* argv[]){
    printf("\n------------------------------------------------\n");
    printf("inicio");
    printf("\n------------------------------------------------\n");
    ifstream file;
    file.open(argv[1]);
    string AST = fileToString(file);
    file.close();
    printf("\n------------------------------------------------\n");
    printf("arquivo da AST: %s\n", AST.c_str());
    printf("------------------------------------------------\n");
    NodeProgram *program = parser(AST);
    delete &AST;
    printAllSymbols(program);
    printAllFunctions(program);
    printf("fim do programa");
    printf("\n------------------------------------------------");
}