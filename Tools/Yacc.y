%{

#include "Tool.h"

#include <string>
#include <iostream>

int yylex();
int yyerror(const char *);
%}

%code requires {
#include "AST/Node.h"

using namespace std;
using namespace Hamster::AST;

}

%union {
    int Int;
    char* String;
	ASTImport* Import;
	ASTGuidance* Guidance;
}
%token ASSIGN IMPORT TOKEN SEPARATED END
%type <String> TOKEN
%type <String> ASSIGN
%type <String> IMPORT
%type <String> SEPARATED
%type <Import> import
%type <Guidance> package

%%
file : import
;
import : IMPORT NAME package {
		$$ = new Hamster::AST::ASTImport();
		$$->packageName = $2;
		// MC::log(MC::toStr("Import S1 ", $1), GARY);
		MC::log(MC::toStr("", $$->packageName), GARY);
	}
;
package : SEPARATED NAME package {
		$$ = new Hamster::AST::ASTGuidance();
		$$->name = $2;
		MC::log(MC::toStr("", $$->name), GARY);
	}
	| END
;
%%

int yyerror(const char *msg)
{
	LOG_ERROR(msg);
	system("pause");
	return 0;
}