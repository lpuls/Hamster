#include "ASTDef.h"

Hamster::AST::ASTDef::ASTDef()
{
}

Hamster::AST::ASTDef::~ASTDef()
{
}

std::string Hamster::AST::ASTDef::toString()
{
    std::string log = _type + " " + _name + ";\n";
    return log;
}

void Hamster::AST::ASTDef::release()
{
}
