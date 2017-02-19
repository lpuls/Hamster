#include "Bison.h"
#include "../AST/ASTBody.h"
#include <fstream>

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
    _body = new Hamster::AST::ASTBody();
}

Bison::~Bison()
{
}

void Bison::toFile(std::string fileName)
{
    ofstream saveFile(fileName);
    std::string code = _body->toString();
    saveFile << code;
    saveFile.close();
}
