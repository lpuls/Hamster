#include "../Tool.h"
#include "ASTPackage.h"

Hamster::AST::ASTPackage::ASTPackage()
{
	ASTNode::ASTNode();
    _packageName = nullptr;
	type = ASTType::AST_TYPE_PACKAGE;
}

Hamster::AST::ASTPackage::~ASTPackage()
{
}

string Hamster::AST::ASTPackage::toString()
{
	if (nullptr == _packageName)
		return "";
	std::string log = "namespace " + _packageName->toString() + "\n";
	std::string body = _body->toString();
    log = log + "{\n\t" + body + "\n}\t";
	return log;
}

void Hamster::AST::ASTPackage::release()
{
	if (nullptr != _packageName)
	{
		_packageName->release();
		delete(_packageName);
	}
	_packageName = nullptr;

	if (nullptr != _body)
	{
		_body->release();
		delete(_body);
	}
	_body = nullptr;
}
