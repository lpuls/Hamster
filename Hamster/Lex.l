/********
 * function : lex tool
 * author : xp
 * 2016-12-9
 ********/
%{ 
#include "stdio.h" 
#include "stdlib.h" 
#include <iostream>
using namespace std;

#define LOG(var) cout << var << yytext << endl;
#define fileno(var) _fileno(var)
%} 

INTEGER [1-9][0-9]*|[0]
FLOAT [0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
TOKEN [a-zA-Z]*
STRING (\"[\s|\S]*\")
ASSIGN [=]
ADD ++|+
LESS --|-
MULTIPLY [*]
EXCEPT [/]
MODULO [%]
BOOL_OPERATOR >|<|>=|<=|==
SPACE [ \t\n]
END [;]

%%
{INTEGER} {
	LOG("整数：")
} 
{FLOAT} {
	LOG("浮点数：")
}
{TOKEN} {
	LOG("标识符：")
}
{STRING} {
	LOG("字符串：")
}
{ASSIGN} {
	LOG("等号：")
}
{ADD} {
	LOG("加号：")
}
{LESS} {
	LOG("减号：")
}
{MULTIPLY} {
	LOG("乘号：")
}
{EXCEPT} {
	LOG("除号：")
}
{MODULO} {
	LOG("取模：")
}
{BOOL_OPERATOR} {
	LOG("比较：")
}
{SPACE} {
	// LOG("空格：")
}
{END} {
	LOG("分号：")
}

%%

int main(int argc, char* argv[])
{ 
	yylex(); 
	return 0;
}

int isatty YY_PROTO((int)) 
{ 
	return 1; 
};

int yywrap()
{
	return 1;
}