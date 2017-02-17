#include "Bison.h"

using namespace Hamster::Yacc;

Bison* Bison::_instance = nullptr;

Bison* Bison::getInstance()
{
	if (nullptr == _instance)
		_instance = new Bison();
	return _instance;
}

Bison::Bison()
{
	_mainCode = new AST::ASTBody();
}

Bison::~Bison()
{
	if (nullptr != _mainCode)
	{
		_mainCode->release();
		delete(_mainCode);
	}
	_mainCode = nullptr;
}
