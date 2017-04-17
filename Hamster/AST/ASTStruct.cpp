#include "ASTStruct.h"

using namespace Hamster::AST;

ASTStruct::ASTStruct()
{
	ASTNode::ASTNode();
	type = ASTType::AST_TYPE_STRUCT;
}

ASTStruct::~ASTStruct()
{
}

std::string Hamster::AST::ASTStruct::toString()
{
    std::string log = "struct " + _name + "\n{\n}";
    return log;
}

void Hamster::AST::ASTStruct::release()
{
    if (nullptr != _body)
    {
        _body->release();
        delete(_body);
    }
    _body = nullptr;
}

void Hamster::AST::ASTStruct::setName(std::string name)
{
	_name = name.substr(0, name.find(':'));
}
