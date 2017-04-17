#include "../Tool.h"
#include "ASTImport.h"

using namespace Hamster::AST;

ASTImport::ASTImport()
{
	_packageName = nullptr;
	type = ASTType::AST_TYPE_IMPORT;
}

ASTImport::~ASTImport()
{
}

std::string ASTImport::toString()
{
	if (nullptr == _packageName)
		return "";
    std::string log = "using namespace " + _packageName->toString();
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
