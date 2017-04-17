#include "ASTEnum.h"

Hamster::AST::ASTEnum::ASTEnum()
{
	ASTNode::ASTNode();
	type = ASTType::AST_TYPE_ENUM;
}

Hamster::AST::ASTEnum::~ASTEnum()
{
}

std::string Hamster::AST::ASTEnum::toString()
{
    std::string log = "enum " + _name + "\n{\n";
    if (nullptr != _body)
        log += _body->toString();
    log += "\n}";

    return log;
}
