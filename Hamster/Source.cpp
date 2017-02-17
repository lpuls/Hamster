#include "Yacc.h"
#include "AST/ASTValue.h"

#define __YACC__

int main()
{
#ifdef __YACC__
	while (true)
	{
		yyparse();
	}
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
