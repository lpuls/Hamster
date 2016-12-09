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
	LOG("������")
} 
{FLOAT} {
	LOG("��������")
}
{TOKEN} {
	LOG("��ʶ����")
}
{STRING} {
	LOG("�ַ�����")
}
{ASSIGN} {
	LOG("�Ⱥţ�")
}
{ADD} {
	LOG("�Ӻţ�")
}
{LESS} {
	LOG("���ţ�")
}
{MULTIPLY} {
	LOG("�˺ţ�")
}
{EXCEPT} {
	LOG("���ţ�")
}
{MODULO} {
	LOG("ȡģ��")
}
{BOOL_OPERATOR} {
	LOG("�Ƚϣ�")
}
{SPACE} {
	// LOG("�ո�")
}
{END} {
	LOG("�ֺţ�")
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