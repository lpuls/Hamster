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
[ \t\v\n\f]		{ count(); }
"uint16" {
	count();
	return TYPE_INTEGER_U16;
}
"uint32" {
	count();
	return TYPE_INTEGER_U32;
}
"int16" {
	count();
	return TYPE_INTEGER_16;
}
"int32" {
	count();
	return TYPE_INTEGER_32;
}
"float" {
	count();
	return TYPE_FLOAT;
}
"string" {
	count();
	return TYPE_STRING;
}
"bool" {
	count();
	return TYPE_BOOL;
}
"list" {
	count();
	return TYPE_LIST;
}
"import" { 
	count();
	return IMPORT; 
}
"package" { 
	count();
	return PACKAGE; 
}
"class" {
	count();
	return STRUCT;
}
"enum" {
	count();
	return ENUM;
}
{char}({char}|{num})* { 
	count();
	yylval.String = yytext; 
	return IDENTIFIER; 
}
"." { 
	count(); 
	return('.'); 
}
";" { 
	count(); 
	return(';'); 
}
"{" { 
	count(); 
	return('{'); 
}
"}" { 
	count();
	return('}'); 
}
"[" {
	count();
	return('['); 
}
"]" {
	count();
	return(']'); 
}
"<" {
	count();
	return('<');
}
">" {
	count();
	return('>');
}
"=" {
	count();
	return('='); 
}
":" {
	count();
	return(':');
}

%%

int yywrap()
{
	return 1;
}

int line = 1;
int column = 1;
void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
	{	
		if (yytext[i] == '\n')
		{	
			column = 1;
			line += 1;
		}
		else if (yytext[i] == '\t')
		{	
			column += 8 - (column % 8);
		}
		else
		{
			column++;
		}
	}
}

void yyInit()
{
    fopen_s(&yyin, "Example\\Proto\\Example.proto", "r");
}

void yyOver()
{
	fclose(yyin);
}

int yyerror(const char *msg)
{
	string log = msg;
	log = MC::toStr(log, "\tLine: ");
	log = MC::toStr(log, line);
	log = MC::toStr(log, "\tcolumn ");
	log = MC::toStr(log, column);
	LOG_ERROR(log);
	return 0;
}

int isatty(int a)
{
	return 1;
}