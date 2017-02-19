#include "ASTEnum.h"

Hamster::AST::ASTEnum::ASTEnum()
{
}

Hamster::AST::ASTEnum::~ASTEnum()
{
}

std::string Hamster::AST::ASTEnum::toString()
{
    std::string log = "enum " + _name + "\n{\n}";
    return log;
}

void Hamster::AST::ASTEnum::release()
{

}

void Hamster::AST::ASTEnum::addEnum(ASTValue* enumValue)
{
    _enums.push_back(enumValue);
}

Hamster::AST::ASTValue* Hamster::AST::ASTEnum::getEnum(int index)
{
    if (index >= 0 && index < _enums.size())
        return _enums[index];
    return nullptr;
}

int Hamster::AST::ASTEnum::getEnumCount()
{
    return _enums.size();
}
