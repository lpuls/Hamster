%{
#include "Flex/Flex.h"
#include "Yacc.h"
#include "Tool.h"

#include <stdio.h>
#include <iostream>

#define fileno _fileno
using namespace Hamster::FLEX;
%}

char [A-Za-z_]
num [0-9]

%%
[ \t\v\n\f]		{}
"import" { return IMPORT; }
{char}({char}|{num})* { 
	yylval.String = yytext; 
	return IDENTIFIER; 
}
"." { return('.'); }
";" { return(';'); }

%%
/*
int main()
{
	while (true)
		yylex();
	// system("pause");
	return 0;
}
*/
int yywrap()
{
	return 1;
}

int isatty(int a)
{
	return 1;
}