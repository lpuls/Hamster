#include "Yacc.h"
#include "Yacc/Bison.h"
#include "AST/ASTPackage.h"
#include "AST/ASTGuidance.h"
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

    ASTGuidance * guidance = new ASTGuidance();
    guidance->addNext("Def");
    guidance->addNext("Client");

    ASTPackage * package = new ASTPackage();
    package->setPackageName(guidance);

    ASTBody * body = new ASTBody();
    package->setBody(body);

    ASTClass * astClass = new ASTClass();
    astClass->setName("Player");

    ASTBody * classBody = new ASTBody();
    astClass->setBody(classBody);

    ASTDef * def = new ASTDef();
    def->setType("std::string");
    def->setName("name");
    classBody->addStatement(def);


    def = new ASTDef();
    def->setType("int");
    def->setName("age");
    classBody->addStatement(def);

    def = new ASTDef();
    def->setType("int");
    def->setName("id");
    classBody->addStatement(def);

    body->addStatement(astClass);


    ASTEnum * astEnum = new ASTEnum();
    astEnum->setName("LoginResultCode");

    ASTBody * enumBody = new ASTBody();
    astEnum->setBody(enumBody);

    ASTValue * value = new ASTValue();
    value->setType(UASTValueType::STRING);
    value->setValue("INVALED");
    enumBody->addStatement(value);

    value = new ASTValue();
    value->setType(UASTValueType::STRING);
    value->setValue("SUCCESS");
    enumBody->addStatement(value);

    value = new ASTValue();
    value->setType(UASTValueType::STRING);
    value->setValue("FAILED");
    enumBody->addStatement(value);

    body->addStatement(astEnum);

    LOG_INFO(package->toString());
    package->release();
    delete(package);
    package = nullptr;

#endif

    system("pause");
    return 0;
}
