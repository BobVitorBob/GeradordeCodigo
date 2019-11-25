#include "includes.h"

//Transformação do código
//#define c1 5
//#define c2 c1+10
//int a,b,c[5][5];
//int foo(int fooo, int aVar)
//{
//int a2Var;
//return (1+2);
//}
//int main()
//{
//} 

int main(){
    //#define c1 5
    NodeSymbol *c1 = new NodeSymbol(SConstant, "c1", new int(5), RInt);
    //#define c2 c1+10
    NodeSymbol *c2 = new NodeSymbol(SConstant, "c2", new int(5 + 10), RInt);
    c1->setNext(c2);
    //int a, b, c[5][5]
    NodeSymbol *a1 = new NodeSymbol(SVariable, "a", nullptr, RInt);
    c2->setNext(a1);
    NodeSymbol *b1 = new NodeSymbol(SVariable, "b", nullptr, RInt);
    a1->setNext(b1);
    NodeSymbol *c3 = new NodeSymbol(SVariable, "c", nullptr, RInt);// n sei
    b1->setNext(c3);

    //int foo(int fooo, int aVar){
    NodeSymbol *fooSymbol = new NodeSymbol(SFunction, "foo", nullptr, RInt);
    c3->setNext(fooSymbol);
    
    NodeSymbol *aVarSym = new NodeSymbol(SFunction, "aVar", nullptr, RInt);
    NodeVariable *aVar = new NodeVariable("aVar", nullptr, VInt);
    
    NodeSymbol *foooSym = new NodeSymbol(SFunction, "fooo", nullptr, RInt);
    NodeVariable *fooo = new NodeVariable("fooo", nullptr, VInt);
    
    aVarSym->setNext(foooSym);
    aVar->setNext(fooo);

    //int a2Var;
    NodeSymbol *a2VarSym = new NodeSymbol(SFunction, "a2Var", nullptr, RInt);
    foooSym->setNext(a2VarSym);

    //return(1+2);

    NodeBinaryOperator *plusOperator = new NodeBinaryOperator(BPlus, RInt);

    plusOperator->setLeftSon(new NodeValueOperator(new int(1), RInt));
    
    plusOperator->setRightSon(new NodeValueOperator(new int(2), RInt));

    NodeExpression *returnV = new NodeExpression(plusOperator);

    NodeCommand *return_ = new NodeReturn(returnV);
    
    NodeFunction *fooFunction = new NodeFunction("foo", aVar, aVarSym, return_, RInt);
    //}

    //main(){

    NodeFunction *mainFunction = new NodeFunction("main", nullptr, nullptr, nullptr, RInt);

    fooFunction->setNext(mainFunction);
    
    //}

    NodeProgram *programaTeste = new NodeProgram(fooFunction, c1);
    printf("fim");
}