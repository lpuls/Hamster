%{
#include "Flex/Flex.h"
#include "Yacc.h"
#include "Tool.h"

#include <stdio.h>
#include <iostream>

#define fileno _fileno
using namespace Hamster::FLEX;
%}

package package
import import
char [A-Za-z]|[_]
num [0-9]
assign [=]
token {char}+
space [\t|\n|" "]
separated [\.]
end [;]

%%
{package} {
	yylval.String = yytext;
	LOG_INFO(MC::toStr("PACKAGE: ", yytext));
	return PACKAGE;
}
{import} {
	yylval.String = yytext;
	LOG_INFO(MC::toStr("IMPORT: ", yytext));
	return IMPORT;
}
{separated} {
	// yylval.String = "";  // yytext;
	LOG_INFO(MC::toStr("SEPARATED: ", yytext));
	return SEPARATED; 
}
{token} {
	yylval.String = yytext;
	LOG_INFO(MC::toStr("TOKEN: ", yytext));
	return TOKEN;
}
{assign} { 
	yylval.String = yytext;
	LOG_INFO(MC::toStr("ASSIGN: ", yytext));
	return ASSIGN;
}
{space} {
}
{end} {
	yylval.String = remove(yylval.String, ';');
	LOG_INFO(MC::toStr("END: ", yylval.String));
	return END;
}
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