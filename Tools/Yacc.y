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
#include "AST/ASTStruct.h"
#include "AST/ASTClass.h"
#include "AST/ASTEnum.h"
#include "AST/ASTDef.h"
#include "AST/ASTClass.h"
#include "AST/ASTValue.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTImport.h"
#include "AST/ASTPackage.h"

using namespace std;
using namespace Hamster::AST;
using namespace Hamster::Yacc;

void yyInit();
void yyOver();
}

%token <String> IDENTIFIER
%token IMPORT PACKAGE ENUM STRUCT 
%token TYPE_STRING TYPE_INTEGER TYPE_FLOAT TYPE_BOOL


%union {
    int Int;
    char* String;

	ASTNode* Node;
	ASTValue* Value;
	ASTBody* Body;
	ASTDef* Def;
	ASTStruct* Struct;
	ASTGuidance* Guidance;
}

%type <Body> translation_unit;
%type <Guidance> package_name;
%type <Node> declaration;
%type <Body> package_body;
%type <Def> declaration_specifiers;
%start translation_unit

%%
translation_unit
	: declaration {
		$$ = new ASTBody();
		$$->addStatement($1);
		// Bison::getInstance()->getBody()->addStatement($1);
		LOG_INFO($$->toString());
		LOG_INFO("\t");
	}
	| translation_unit declaration {
		if (nullptr == $$)
			$$ = new ASTBody();
		$$->addStatement($2);
		// Bison::body->addStatement($2);
		// Bison::getInstance()->getBody()->addStatement($2);
		LOG_INFO($$->toString());
		LOG_INFO("\t");
	}
	;
declaration 
	: IMPORT package_name ';' {
		ASTImport * import = new ASTImport();
		import->setPackageName($2);
		$$ = import;
	}
	| PACKAGE package_name package_body {
		ASTPackage * package = new ASTPackage();
		package->setPackageName($2);
		package->setBody($3);
		$$ = package;
	}
	| declaration_specifiers ';' {
		$$ = $1;
	}
	;
declaration_specifiers
	: TYPE_INTEGER IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("int");
		astDef->setName($2);
		$$ = astDef;
	}
	;
package_body
	: '{' translation_unit '}' {
		ASTBody * body = new ASTBody();
		body->addStatement($2);
		$$ = body;
	}
	| '{' '}' {
		ASTBody* body = new ASTBody();
		$$ = body;
	}
	;
package_name
	: IDENTIFIER { 
		ASTGuidance * packageName = new ASTGuidance();
		packageName->addNext($1);
		$$ = packageName;
	}
	| package_name '.' IDENTIFIER { 
		$$->addNext($3);
	}
	;
%%

