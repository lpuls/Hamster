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
}

Bison::~Bison()
{
}

void Bison::toFile(std::string fileName)
{
    // ofstream saveFile(fileName);
    // std::string code = _body->toString();
    // saveFile << code;
    // saveFile.close();
}

void Hamster::Yacc::Bison::pushBody(AST::ASTBody * body)
{
    _bodys.push(body);
}

Hamster::AST::ASTBody * Hamster::Yacc::Bison::popBody()
{
    if (_bodys.size() <= 0)
        return nullptr;

    Hamster::AST::ASTBody * top = _bodys.top();
    _bodys.pop();
    return top;
}

bool Hamster::Yacc::Bison::isBottom()
{
    return _bodys.size() == 1;
}
