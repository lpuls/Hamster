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

void yyInit(const char * path);
void yyOver();
}

%token <String> IDENTIFIER
%token IMPORT PACKAGE ENUM STRUCT 
%token TYPE_STRING TYPE_INTEGER_U16 TYPE_INTEGER_U32 TYPE_INTEGER_16 TYPE_INTEGER_32 TYPE_FLOAT TYPE_BOOL TYPE_LIST


%union {
    int Int;
    char* String;

	ASTNode* Node;
	ASTValue* Value;
	ASTBody* Body;
	ASTDef* Def;
	ASTEnum* Enum;
	ASTClass* Class;
	ASTGuidance* Guidance;
	ASTValue* Inherit;
	ASTNode* Types;
}

%type <Body> translation_unit;
%type <Guidance> package_name;
%type <Node> declaration;
%type <Body> package_body;
%type <Def> declaration_specifiers;
%type <Enum> enum_specifiers;
%type <Body> enum_specifiers_body;
%type <Body> enum_specifiers_body_impl;
%type <Class> struct_specifiers;
%type <Inherit> inherit
%type <Types> types;
%start translation_unit

%%
translation_unit
	: declaration {
		$$ = new ASTBody();
		$$->addStatement($1);
		$1->parent = $$;
		Bison::getInstance()->pushBody($$);
	}
	| translation_unit declaration {
		if (nullptr == $$)
			$$ = new ASTBody();
		$$->addStatement($2);
		$2->parent = $$;
	}
	;
declaration 
	: IMPORT package_name ';' {
		ASTImport * import = new ASTImport();
		import->setPackageName($2);
		$$ = import;
		$2->parent = $$;
	}
	| PACKAGE package_name package_body {
		ASTPackage * package = new ASTPackage();
		package->setPackageName($2);
		package->setBody($3);
		$$ = package;
		$2->parent = $$;
		$3->parent = $$;
	}
	| declaration_specifiers ';' {
		$$ = $1;
	}
	| enum_specifiers enum_specifiers_body {
		$$ = $1;
		$1->setBody($2);
		$2->parent = $1;
	}
	| struct_specifiers package_body {
		$$ = $1;
		$1->setBody($2);
		$2->parent = $1;
	}
	;
declaration_specifiers
	: TYPE_INTEGER_U16 IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("uint16");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_INTEGER_U32 IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("uint32");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_INTEGER_16 IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("int16");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_INTEGER_32 IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("int32");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_STRING IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("string");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_FLOAT IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("float");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_BOOL IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("bool");
		astDef->setName($2);
		$$ = astDef;
	}
	| TYPE_LIST '<' types '>' IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType("list");
		astDef->setName($5);
		astDef->setOther($3);
		$$ = astDef;
	}
	| IDENTIFIER IDENTIFIER {
		ASTDef * astDef = new ASTDef();
		astDef->setType($1);
		astDef->setName($2);
		$$ = astDef;
	}
	;
types
	: TYPE_STRING {
		ASTValue * value = new ASTValue();
		value->setValue("string");
		$$ = value;
	}
	| TYPE_INTEGER_U16 {
		ASTValue * value = new ASTValue();
		value->setValue("uint16");
		$$ = value;
	}
	| TYPE_INTEGER_U32 {
		ASTValue * value = new ASTValue();
		value->setValue("uint32");
		$$ = value;
	}
	| TYPE_INTEGER_16 {
		ASTValue * value = new ASTValue();
		value->setValue("int16");
		$$ = value;
	}
	| TYPE_INTEGER_32 {
		ASTValue * value = new ASTValue();
		value->setValue("int32");
		$$ = value;
	}
	| TYPE_FLOAT {
		ASTValue * value = new ASTValue();
		value->setValue("float");
		$$ = value;
	}
	| TYPE_BOOL {
		ASTValue * value = new ASTValue();
		value->setValue("bool");
		$$ = value;
	}
	| IDENTIFIER {
		ASTValue * value = new ASTValue();
		value->setValue($1);
		$$ = value;
	}
	| TYPE_LIST '<' types '>' {
		ASTDef *value = new ASTDef();
		value->setType("list");
		value->setOther($3);
		$$ = value;
	}
	;
enum_specifiers
	: ENUM IDENTIFIER  {
		ASTEnum * astEnum = new ASTEnum();
		astEnum->setName($2);
		astEnum->setBody(nullptr);
		$$ = astEnum;
	}
	;
enum_specifiers_body
	: '{' enum_specifiers_body_impl '}' {
		$$ = new ASTBody();
		$$ = $2;
	}
	| '{' '}' {
		ASTBody * body = new ASTBody();
		$$ = body;
	}
	;
enum_specifiers_body_impl
	: IDENTIFIER {
		ASTValue * value = new ASTValue();
		value->setValue($1);
		
		ASTBody * body = new ASTBody();
		body->addStatement(value);
		$$ = body;
	}
	| enum_specifiers_body_impl ';' IDENTIFIER {
		if (nullptr == $$)
			$$ = new ASTBody();

		ASTValue * value = new ASTValue();
		value->setValue($3);
		$$->addStatement(value);
	}
	;
struct_specifiers
	: STRUCT IDENTIFIER inherit {
		ASTClass * astClass = new ASTClass();
		astClass->setName($2);
		astClass->setInherit($3);
		$$ = astClass;
	}
	;
inherit
	: ':' IDENTIFIER {
		$$ = new ASTValue();
		$$->setValue($2);
	}
	| {
		$$ = nullptr;
	}
	;
package_body
	: '{' translation_unit '}' {
		ASTBody * body = new ASTBody();
		body->addStatement($2);
		$$ = body;
		$2->parent = $$;
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

