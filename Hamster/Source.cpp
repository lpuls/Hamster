#include "Yacc.h"
#include "ToFile/ToFile.h"
#include "ToFile/ToFile.h"
#include "ToFile/ToPy.h"
#include "Yacc/Bison.h"
#include "AST/ASTPackage.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTDef.h"
#include "AST/ASTClass.h"
#include "AST/ASTBody.h"
#include "Tool.h"

#define __YACC__

using namespace Hamster;
using namespace Hamster::AST;
using namespace Hamster::Yacc;

int main()
{
#ifdef __YACC__
    yyInit();
    yyparse();
    yyOver();
	Hamster::AST::ASTBody * body = Bison::getInstance()->getBody(0);
    if (nullptr != body)
    {
		ToPy toPy;
		std::string content = toPy.toFile(body);  // body->toString();
        LOG_INFO(content);
        Bison::getInstance()->toFile("E:\\My\\C++\\Hamster\\Code.py", content);
    }
    Bison::getInstance()->clear();
    // Bison::getInstance()->toFile("G:/Code/C++/Hamster/Code.txt");
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

    ToFile file;
    std::string code = file.toFile(body, 0);
    LOG_INFO(code);

    LOG_INFO(package->toString());
    package->release();
    delete(package);
    package = nullptr;

#endif

    system("pause");
    return 0;
}
