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

void Bison::toFile(std::string fileName, std::string content)
{
    ofstream saveFile(fileName);
    saveFile << content;
    saveFile.close();
}

void Hamster::Yacc::Bison::pushBody(AST::ASTBody * body)
{
    _bodys.push_back(body);
}

Hamster::AST::ASTBody * Hamster::Yacc::Bison::getBody(int index)
{
    if (index >= 0 && index < _bodys.size())
        return _bodys[index];
    return nullptr;
}

int Hamster::Yacc::Bison::getBodys()
{
    return _bodys.size();
}

void Hamster::Yacc::Bison::clear()
{
    if (0 < _bodys.size())
    {
        _bodys[0]->release();
        _bodys[0] = nullptr;
    }
    _bodys.clear();
}
