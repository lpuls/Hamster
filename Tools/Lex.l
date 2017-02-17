%{
#include "Flex/Flex.h"
#include "Yacc.h"
#include "Tool.h"

#include <stdio.h>
#include <iostream>

#define fileno _fileno
#define LEX_LOG(var) LOG_INFO(var)

using namespace Hamster::FLEX;

void count();
%}

char [A-Za-z_]
num [0-9]

%%
[ \t\v\n\f]		{}
"import" { 
	LEX_LOG("IMPORT"); 
	return IMPORT; 
}
"package" { 
	LEX_LOG("PACKAGE"); 
	return PACKAGE; 
}
{char}({char}|{num})* { 
	LEX_LOG("IDENTIFIER");
	yylval.String = yytext; 
	return IDENTIFIER; 
}
"." { 
	LEX_LOG("."); 
	return('.'); 
}
";" { 
	LEX_LOG(";"); 
	return(';'); 
}
"{" { 
	LEX_LOG("{"); 
	return('{'); 
}
"}" { 
	LEX_LOG("}"); 
	return('}'); 
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

int column = 0;
void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	// ECHO;
}

int yyerror(const char *msg)
{
	string log = msg;
	log = MC::toStr(log, column);
	LOG_ERROR(log);
	// system("pause");
	return 0;
}

int isatty(int a)
{
	return 1;
}