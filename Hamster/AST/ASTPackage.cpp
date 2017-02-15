#include "../Tool.h"
#include "ASTPackage.h"

Hamster::AST::ASTPackage::ASTPackage()
{
    packageName = nullptr;
}

Hamster::AST::ASTPackage::~ASTPackage()
{
}

string Hamster::AST::ASTPackage::print()
{
    string log = "Package ";
    if (nullptr != packageName)
    {
        MC::toStr(log, packageName->print());
        MC::toStr(log, " ");
    }
    MC::log(log, DARK_GREEN);
    return log;
}
