%{
#include "Tool.h"

#include <string>
#include <iostream>

int yylex();
int yyerror(const char *);


%}

%code requires {
#include "Yacc/Bison.h"
#include "AST/ASTBody.h"
#include "AST/ASTNode.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTImport.h"
#include "AST/ASTPackage.h"

using namespace std;
using namespace Hamster::AST;
using namespace Hamster::Yacc;

}

%token <String> IDENTIFIER
%token IMPORT PACKAGE ENUM STRUCE


%union {
    int Int;
    char* String;
	ASTNode* Node;
	ASTBody* Body;
	ASTGuidance* Guidance;
}

%type <Body> translation_unit;
%type <Guidance> package_name;
%type <Node> declaration;
%start translation_unit

%%
translation_unit
	: declaration { 
		Bison::getInstance()->getBody()->addStatement($1); 
		Bison::getInstance()->getBody()->print();
	}
	| translation_unit declaration  {
		Bison::getInstance()->getBody()->addStatement($2); 
		Bison::getInstance()->getBody()->print();
	}
	;
declaration 
	: IMPORT package_name ';' {
			LOG_WARNING(MC::toStr("Package Name ", $2->print())); 
			ASTImport* import = new ASTImport();
			import->setPackageName($2);
			$$ = import;
		}
	| PACKAGE package_name '{' translation_unit '}' {
			ASTPackage* package = new ASTPackage();
			package->setPackageName($2);
			package->setBody($4);
			$$ = package;
			LOG_INFO("PACKAGE BODY ", $4->print());
			std::string log = package->print();
			LOG_INFO(log);
		}
	;
package_name
	: IDENTIFIER { 
			LOG_WARNING(MC::toStr("Identifier ", $1)); 
			ASTGuidance* packageName = new ASTGuidance();
			packageName->addNext($1);
			$$ = packageName;
		}
	| package_name '.' IDENTIFIER { 
			LOG_WARNING(MC::toStr("$1 Package Name . Identifier ", $1->print())); 
			LOG_WARNING(MC::toStr("$3 Package Name . Identifier ", $3)); 
			$$->addNext($3);
			LOG_WARNING(MC::toStr("$1 again Package Name . Identifier ", $1->print())); 
		}
	;
%%

