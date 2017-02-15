%{

#include "Tool.h"

#include <string>
#include <iostream>

int yylex();
int yyerror(const char *);
%}

%code requires {
#include "AST/ASTNode.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTImport.h"
#include "AST/ASTPackage.h"

using namespace std;
using namespace Hamster::AST;

// %token IMPORT TOKEN SEPARATED END PACKAGE
}

%token <String> ASSIGN
%token <String> IMPORT
%token <String> TOKEN
%token <String> SEPARATED
%token <String> END
%token <String> PACKAGE

%union {
    int Int;
    char* String;
	ASTImport* Import;
	ASTGuidance* Guidance;
	ASTPackage* Package;
}


%type <Import> import
%type <Guidance> package_name
%type <Package> package

%%
file : import
	| package
;
import : IMPORT package_name {
		auto node = new Hamster::AST::ASTImport();
		std::string packageName = $2->name;
		node->packageName = packageName;
		MC::log(typeid($2).name(), BLUE);
		MC::log(packageName, RED);
		node->print();
		$$ = node;
	}
;
package : PACKAGE package_name {
		// $$ = new Hamster::AST::ASTPackage();
		// $$->packageName = $2;
		// $$->print();
	}
package_name : TOKEN package_name {
		auto node = new Hamster::AST::ASTGuidance();
		node->name = $1;
		node->next = $2;
		node->print();
		$$ = node;
		// MC::log(typeid($1).name(), BLUE);
		// MC::log(typeid($2).name(), BLUE);
		// MC::log(MC::toStr("Token ", $1), RED); 
		// MC::log(MC::toStr("package_name ", $2), RED); 
	}
	| SEPARATED package_name { 
		// $$ = $2;
		auto I = $$;
		auto II = $1;
		auto III = $2;
		MC::log(MC::toStr("Separated ", $2), RED); 
	}
	| END  { 
		$$ = nullptr; 
		auto I = $$;
		auto II = $1;
		MC::log($1, RED); 
	}
;
%%

int yyerror(const char *msg)
{
	LOG_ERROR(msg);
	system("pause");
	return 0;
}