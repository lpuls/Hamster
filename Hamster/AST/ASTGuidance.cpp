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


void ASTGuidance::print()
{
	LOG_INFO(MC::toStr("Package Name Park: ", name));
	if (nullptr != next)
		next->print();
}
