#include "../Tool.h"
#include "ASTGuidance.h"

using namespace Hamster::AST;

ASTGuidance::ASTGuidance()
{
	// _name = "";
	// _next = nullptr;
}

ASTGuidance::~ASTGuidance()
{
}

void ASTGuidance::addNext(std::string name)
{
	_next.push_back(name);
}

std::string ASTGuidance::getNext(int index)
{
	if (index >= 0 && index < _next.size())
		return _next[index];
	return "";
}
int ASTGuidance::getCount()
{
	return _next.size();
}

std::string ASTGuidance::print()
{
	std::string log = "";
	for (int i = 0; i < _next.size(); i++)
        log = log + " " + _next[i]; 
    return log;
}

void ASTGuidance::release()
{
	_next.clear();
}
