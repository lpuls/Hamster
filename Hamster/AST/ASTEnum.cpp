#include "ASTEnum.h"

Hamster::AST::ASTEnum::ASTEnum()
{
}

Hamster::AST::ASTEnum::~ASTEnum()
{
}

std::string Hamster::AST::ASTEnum::toString()
{
    std::string log = "enum " + _name + "\n{\n";

    log += _body->toString();
    log += "\n}";

    return log;
}
