#include "Yacc.h"
#include "Yacc/Bison.h"
#include "AST/ASTValue.h"

#define __YACC__

using namespace Hamster::Yacc;

int main()
{
#ifdef __YACC__
	yyparse();
	if (nullptr != Bison::getInstance()->getBody())
	{
		Bison::getInstance()->getBody()->print();
		Bison::getInstance()->getBody()->release();
	}
	delete(Bison::getInstance());
#else

	Hamster::AST::ASTValue *value = new Hamster::AST::ASTValue();
	value->setValue(10);
	value->setValue("hello world");
	LOG_INFO(MC::toStr(value->getValue().Int));
	LOG_INFO(value->getValue().String);

	delete(value);
	value = nullptr;

#endif

    system("pause");
    return 0;
}
