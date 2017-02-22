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
    std::string log = "class " + _name + "\n{\npublic:\n";
    for (int i = 0; i < _defs.size(); i++)
        log = log + "\t" + _defs[i]->toString();
    log = log + "};\n";
    return log;
}

void Hamster::AST::ASTClass::release()
{
    for (int i = 0; i < _defs.size(); i++)
        _defs[i]->release();
    _defs.clear();
}

int Hamster::AST::ASTClass::getDefCount()
{
    return _defs.size();
}

void Hamster::AST::ASTClass::addDef(ASTDef * def)
{
    _defs.push_back(def);
}

ASTDef * Hamster::AST::ASTClass::getDef(int index)
{
    if (index >= 0 && index < _defs.size())
        return _defs[index];
    return nullptr;
}
