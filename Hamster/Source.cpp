#include "Yacc.h"
#include "Yacc/Bison.h"
#include "AST/ASTValue.h"

// #define __YACC__

using namespace Hamster::Yacc;

int main()
{
#ifdef __YACC__
	yyparse();
    Bison::getInstance()->toFile("G:\Code.txt");
#else



#endif

    system("pause");
    return 0;
}
