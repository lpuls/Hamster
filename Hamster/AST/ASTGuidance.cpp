#include "../Tool.h"
#include "ASTGuidance.h"

using namespace Hamster::AST;

ASTGuidance::ASTGuidance()
{
	name = "";
	next = nullptr;
}

ASTGuidance::~ASTGuidance()
{
	if (nullptr != next)
		delete(next);
	next = nullptr;
}


std::string ASTGuidance::print()
{
    std::string log = ""; // "Package Name Park: ";
    if (nullptr != next)
    {
        MC::toStr(log, next->print());
        MC::toStr(log, " ");
    }
    MC::log(MC::toStr(log, name), DARK_GREEN);
    return log;
}