#include "Yacc.h"
#include "Yacc/Bison.h"
#include "AST/ASTDef.h"
#include "AST/ASTClass.h"

// #define __YACC__

using namespace Hamster::Yacc;
using namespace Hamster::AST;

int main()
{
#ifdef __YACC__
	yyparse();
    Bison::getInstance()->toFile("G:\Code.txt");
#else

    ASTClass *astClass = new ASTClass();
    astClass->setName("Player");
    ASTDef *def = new ASTDef();
    def->setType("std::string");
    def->setName("name");
    astClass->addDef(def);

    def = new ASTDef();
    def->setType("int");
    def->setName("age");
    astClass->addDef(def);

    def = new ASTDef();
    def->setType("int");
    def->setName("id");
    astClass->addDef(def);

    LOG_INFO(astClass->toString());
    delete(astClass);
    astClass = nullptr;

#endif

    system("pause");
    return 0;
}
