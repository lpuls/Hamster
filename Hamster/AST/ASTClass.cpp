#include "ASTClass.h"

using namespace Hamster::AST;

ASTClass::ASTClass()
{
	ASTNode::ASTNode();
	type = ASTType::AST_TYPE_CLASS;
}

ASTClass::~ASTClass()
{
}

std::string Hamster::AST::ASTClass::toString()
{
    std::string log = "class " + _name + "\n{\n";
    if (nullptr != _body)
        log += _body->toString();
    log = log + "}\n";
    return log;
}
