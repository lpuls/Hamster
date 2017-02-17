#include "../Tool.h"
#include "ASTImport.h"

using namespace Hamster::AST;

ASTImport::ASTImport()
{
	_packageName = nullptr;
}

ASTImport::~ASTImport()
{
}

std::string ASTImport::print()
{
	if (nullptr == _packageName)
		return "error: package name is nullptr";
    std::string log = "Import " + _packageName->print();
    // MC::log(log, DARK_GREEN);
    return log;
}

void ASTImport::release()
{
	if (nullptr != _packageName)
	{
		_packageName->release();
		delete(_packageName);
	}
	_packageName = nullptr;
}
