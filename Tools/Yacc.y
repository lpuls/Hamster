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

}

%token <String> IDENTIFIER
%token <String> IMPORT


%union {
    int Int;
    char* String;
	ASTGuidance* Guidance;
}

%type <String> translation_unit;
%type <Guidance> package_name;
%start translation_unit

%%
translation_unit
	: IMPORT package_name ';' {
			LOG_WARNING(MC::toStr("Package Name ", $2)); 
			ASTImport* import = new ASTImport();
			import->setPackageName($2);
			std::string log = import->print();
			LOG_INFO(log);
			if (nullptr != import)
			{
				import->release();
				delete(import);
			}
			import = nullptr;
		}
	;
package_name
	: IDENTIFIER { 
			LOG_WARNING(MC::toStr("Identifier ", $1)); 
			ASTGuidance* packageName = new ASTGuidance();
			// packageName->setName($1);
			packageName->addNext($1);
			$$ = packageName;
		}
	| package_name '.' IDENTIFIER { 
			LOG_WARNING(MC::toStr("$1 Package Name . Identifier ", $1->print())); 
			LOG_WARNING(MC::toStr("$3 Package Name . Identifier ", $3)); 
			$$->addNext($3);
			/*
			ASTGuidance* packageName = new ASTGuidance();
			packageName->setName($3);
			packageName->setNext(nullptr);
			$1->getNext()->setNext(packageName);
			$$ = $1;
			*/
			LOG_WARNING(MC::toStr("$1 again Package Name . Identifier ", $1->print())); 
		}
	;
%%

int yyerror(const char *msg)
{
	LOG_ERROR(msg);
	system("pause");
	return 0;
}