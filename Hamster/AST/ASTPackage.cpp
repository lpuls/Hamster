#include "../Tool.h"
#include "ASTPackage.h"

Hamster::AST::ASTPackage::ASTPackage()
{
    _packageName = nullptr;
	_body = new ASTBody();
}

Hamster::AST::ASTPackage::~ASTPackage()
{
}

string Hamster::AST::ASTPackage::print()
{
	if (nullptr == _packageName)
		return "error: package name is nullptr";
	std::string log = "Package " + _packageName->print() + "\n";
	std::string body = _body->print();
	return log + body;
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
