#include "ASTDef.h"

Hamster::AST::ASTDef::ASTDef()
{
	type = ASTType::AST_TYPE_DEF;
}

Hamster::AST::ASTDef::~ASTDef()
{
}

std::string Hamster::AST::ASTDef::toString()
{
    std::string log = "public " + _type + " " + _name + ";\n";
    return log;
}

void Hamster::AST::ASTDef::release()
{
}