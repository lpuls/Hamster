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
#include "AST/ASTClass"
#include "AST/ASTGuidance.h"
#include "AST/ASTImport.h"
#include "AST/ASTPackage.h"

using namespace std;
using namespace Hamster::AST;
using namespace Hamster::Yacc;

}

%token <String> IDENTIFIER
%token IMPORT PACKAGE ENUM STRUCT INTEGER FLOAT STRING BOOL LIST 


%union {
    int Int;
    char* String;
	ASTNode* Node;
	ASTBody* Body;
	ASTDef* Def;
	ASTStruct* Struct;
	ASTGuidance* Guidance;
}

%type <Body> translation_unit;
%type <Guidance> package_name;
%type <Node> declaration;
%type <Body> package_body;
%type <Struct> struct_or_enum;
%type <Body> struct_or_enum_body;
%type <Def> type;
%start translation_unit

%%
translation_unit
	: declaration {
		Bison::getInstance()->getBody()->addStatement($1);
		LOG_INFO($1->toString());
	}
	| translation_unit declaration  {
		Bison::getInstance()->getBody()->addStatement($1);
		Bison::getInstance()->getBody()->addStatement($2);
		LOG_INFO($2->toString());
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
	| struct_or_enum IDENTIFIER '{' struct_or_enum_body '}' {
		$1->setName($2);
		$1->setBody($4);
		$$ = $1;
	}
	;
struct_or_enum
	: STRUCT {
		ASTClass * astClass = new ASTClass();
		$$ = astClass;
	}
	| ENUM {
		ASTEnum * astEnum = new ASTEnum();
		$$ = astEnum;
	}
struct_or_enum_body
	: type IDENTIFIER ';' {
		if (nullptr == $$)
			$$ = new ASTBody();
		$1->setName($1);
		$$->addStatement($1);
	}
	| struct_or_enum_body ';' type IDENTIFIER ';' {
		if (nullptr == $$)
			$$ = new ASTBody();
		$3->setName($4);
		$$->addStatement($3);

	}
	;
type
	: INTEGER {
		ASTDef * def = new ASTDef();
		def->setType("int");
		$$ = def;
	}
	| FLOAT {
		ASTDef * def = new ASTDef();
		def->setType("float");
		$$ = def;
	} 
	| STRING {
		ASTDef * def = new ASTDef();
		def->setType("string");
		$$ = def;
	} 
	| BOOL {
		ASTDef * def = new ASTDef();
		def->setType("bool");
		$$ = def;
	} 
	| IDENTIFIER {
		ASTDef * def = new ASTDef();
		def->setType($1);
		$$ = def;
	}
	; 
package_body
	: '{' translation_unit '}' {
		ASTBody * body = new ASTBody();
		body->addStatement(body);
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

