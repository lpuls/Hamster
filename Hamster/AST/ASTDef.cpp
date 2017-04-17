#include "ASTDef.h"

Hamster::AST::ASTDef::ASTDef()
{
	ASTNode::ASTNode();
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

void Hamster::AST::ASTDef::setType(std::string type)
{
	size_t index = type.find(' ');
	_type = type.substr(0, index);
}