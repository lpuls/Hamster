%{

#include "Tool.h"

#include <string>
#include <iostream>

int yylex();
int yyerror(const char *);
%}

%code requires {
#include "AST/Node.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTImport.h"

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
%type <Guidance> package_name

%%
file : import
;
import : IMPORT package_name {
		$$ = new Hamster::AST::ASTImport();
		$$->packageName = $2;
		$$->print();
	}
;
package_name : TOKEN package_name {
		$$ = new Hamster::AST::ASTGuidance();
		$$->name = $1;
		$$->next = $2;
		$$->print();
	}
	| SEPARATED package_name { 
		$$ = nullptr;
		MC::log("Separated ", BLUE); 
	}
	| END { 
		$$ = nullptr;
		MC::log("End", BLUE); 
	}
;
%%

int yyerror(const char *msg)
{
	LOG_ERROR(msg);
	system("pause");
	return 0;
}