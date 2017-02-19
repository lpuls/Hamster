#include "ASTClass.h"

using namespace Hamster::AST;

ASTClass::ASTClass()
{
}

ASTClass::~ASTClass()
{
}

std::string Hamster::AST::ASTClass::toString()
{
    std::string log = "class " + _name + "\n{\n}";
    return log;
}

void Hamster::AST::ASTClass::release()
{
}
