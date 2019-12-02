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

NodeSymbolVariable *resolveFuncParameter(vector <string> programV, int * startPos){
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
    *startPos = i;
    return newVar;
}

NodeSymbolVariable *resolveFuncVariable(vector <string> programV, int * startPos){
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
    *startPos = i;
    return newVar;
}

NodeCommand *resolveCommand(string s, int *startPos=nullptr);
NodeExpression *resolveExpression(string s, int *startPos=nullptr);

NodeDoWhile *resolveDoWhile(string s, int *startPos=nullptr){
    int *i = startPos;
    *i+=9;
    printf("StartPos: %d\n s[i]: %c\n", *startPos, s[*i]);
    NodeDoWhile *newDoWhile = new NodeDoWhile();
    NodeCommand *DoWhileCommands;
    while(s[*startPos] != ',')
    {
        newDoWhile->addCommand(resolveCommand(s, startPos));
        *startPos++;
    }
    newDoWhile->setStopCondition(resolveExpression(s, startPos));
}

NodeIf *resolveIf(string s, int *startPos=nullptr){
    return nullptr;
}

NodeWhile *resolveWhile(string s, int *startPos=nullptr){
    return nullptr;
}

NodeFor *resolveFor(string s, int *startPos=nullptr){
    return nullptr;
}

NodePrintf *resolvePrintf(string s, int *startPos=nullptr){
    return nullptr;
}

NodeScanf *resolveScanf(string s, int *startPos=nullptr){
    return nullptr;
}

NodeExit *resolveExit(string s, int *startPos=nullptr){
    return nullptr;
}

NodeReturn *resolveReturn(string s, int *startPos=nullptr){
    return nullptr;
}

NodeExpression *resolveExpression(string s, int *startPos=nullptr){
    //BPlus,
    //BMinus,
    //BMultiply,
    //BDiv,
    //BRemainder,
    //BBitwise_and,
    //BBitwise_or,
    //BBitwise_xor,
    //BLogical_and,
    //BLogical_or,
    //BEqual,
    //BNot_equal,
    //BLess_than,
    //BGreater_than,
    //BLess_equal,
    //BGreater_equal,
    //BR_shift,
    //BL_shift,
    //BAssign,
    //BAdd_assign,
    //BMinus_assign,
    //unary
    //UPlus,
    //UPointer,
    //UMinus,
    //UInc,
    //UDec,
    //UBitwise_not,
    //UNot,
    //UBitwise_and
    NodeExpression *expression = new NodeExpression();
    if(startPos == nullptr) startPos = new int(0);
    string op = 
}

NodeCommand *resolveCommand(string s, int *startPos=nullptr){
    int i = *startPos;
        if(s[0] == 'D')
        {
            return resolveDoWhile(s, startPos);
        }
        else if(s[0] == 'I')
        {
            return resolveIf(s, startPos);
        }
        else if(s[0] == 'W')
        {
            return resolveWhile(s, startPos);
        }
        else if(s[0] == 'F')
        {
            return resolveFor(s, startPos);
        }
        else if(s[0]== 'P')
        {
            return resolvePrintf(s, startPos);
        }
        else if(s[0] == 'S')
        {
            return resolveScanf(s, startPos);
        }
        else if(s[0] == 'E')
        {
            return resolveExit(s, startPos);
        }
        else if(s[0]== 'R')
        {
            return resolveReturn(s, startPos);
        }
        else
        {
            return resolveExpression(s, startPos);
        }
    *startPos = i;
}

NodeSymbolFunction *readFunction(vector <string> programV, int *startPos=nullptr){
    int i = *startPos;
    i++;
    NodeSymbolFunction *newFunction = new NodeSymbolFunction();
    string funcName(programV[i].c_str());
    newFunction->setName(funcName);
    i+=2;
    tuple<ReturnType, int> funcRetType = resolveFuncReturn(programV[i]);
    newFunction->setReturnType(get<0>(funcRetType));
    newFunction->setPointerLvl(get<1>(funcRetType));
    i++;
    int *zero = new int(0);
    while (true)
    {
        *startPos = i;
        if(programV[i].compare("END_FUNCTION") == 0) break;
        else if(programV[i].compare("PARAMETER:") == 0)
        {
            newFunction->addNewSymbol(resolveFuncParameter(programV, startPos));
        }
        else if(programV[i].compare("VARIABLE:") == 0)
        {
            newFunction->addNewSymbol(resolveFuncVariable(programV, startPos));
        }
        else{
            newFunction->addNewCommand(resolveCommand(programV[i], zero));
            *startPos++;
        }
        i = *startPos;
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
        //printf("Commands: %s\n", functions->getName().c_str());
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